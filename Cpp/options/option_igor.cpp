/*
 * main.cpp
 *
 *  Created on: Jan 12, 2015
 *      Author: Quentin Marcou
 *
 *  This source code is distributed as part of the IGoR software.
 *  IGoR (Inference and Generation of Repertoires) is a versatile software to analyze and model immune receptors
 *  generation, selection, mutation and all other processes.
 *   Copyright (C) 2017  Quentin Marcou
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../config.h"
#include "Deletion.h"
#include "Insertion.h"
#include "Genechoice.h"
#include "Model_Parms.h"
#include "Rec_Event.h"
#include "Singleerrorrate.h"
#include "Model_marginals.h"
#include <iostream>
#include "Aligner.h"
#include "GenModel.h"
#include "Dinuclmarkov.h"
#include "Counter.h"
#include "Coverageerrcounter.h"
#include "Bestscenarioscounter.h"
#include "Pgencounter.h"
#include "Errorscounter.h"
#include "Utils.h"
#include <chrono>
#include <set>

#include <string>
#include "CDR3SeqData.h"
#include "ExtractFeatures.h"

using namespace std;



// TODO: Possible typedef definitions for code readability.
typedef std::string strSeqID;    // fasta description >strSeqID
typedef std::string strSequence;
typedef vector< pair<const int, const strSequence> > VectorIndexedSeq;
typedef pair<strSeqID, strSequence> Indexed_Seq; // A typedef for a doublet of a strSequence and the corresponding sequence index


int terminate_IGoR_with_error_message(const forward_list<string> error_messages){
	string igor_error_prefix = "[IGoR] ERROR: ";
	for(string error_message : error_messages){
		cerr<<igor_error_prefix<<error_message<<endl;
	}
	cerr<<igor_error_prefix<<"Use \"man igor\", \"igor -help\" or visit "<<PACKAGE_URL<<" to see available commands and their effects."<<endl;
	cerr<<igor_error_prefix<<"Please report any bug by opening an issue on "<<PACKAGE_URL<<" or email: "<<PACKAGE_BUGREPORT<<endl;
	cerr<<igor_error_prefix<<"Terminating IGoR..."<<endl;
	return EXIT_FAILURE;
}

int terminate_IGoR_with_error_message(string error_message){
	return terminate_IGoR_with_error_message(forward_list<string>(1,error_message));
}

// Output both the exception handling message and the actual exception message
int terminate_IGoR_with_error_message(string error_message, exception& e){
	forward_list<string> error_messages;
	error_messages.emplace_front(e.what());
	error_messages.emplace_front(error_message);
	return terminate_IGoR_with_error_message(error_messages);
}

// Output both the exception handling message and the actual exception message
int terminate_IGoR_with_error_message(forward_list<string> error_messages, exception& e){
	error_messages.emplace_front(e.what());
	return terminate_IGoR_with_error_message(error_messages);
}

int main(int argc , char* argv[]){

	//Command line argument iterator
	size_t carg_i = 1;
	//cout<<argv[argc-1]<<endl;

	// Test if some commands were supplied to IGoR
	if(argc<2){
		return terminate_IGoR_with_error_message("The user did not supply IGoR any command.");
	}

	//Task variables
	bool run_demo = false;
	bool align = false;
	bool infer = false;
	bool evaluate = false;
	bool generate = false;
	bool custom = false;

	//Common vars
	string batchname="";


	//Working directory vars
	bool wd = false;
	string cl_path;

	//Chains vars
	bool chain_provided = false;
	string chain_arg_str;
	string chain_path_str;
	bool has_D = false;

	//Species vars
	bool species_provided = false;
	string species_str = "";

	//Custom genomic templates loading variables
	bool custom_v = false;
	string custom_v_path;
	bool custom_d = false;
	string custom_d_path;
	bool custom_j = false;
	string custom_j_path;

	//Custom gene anchors loading variables
	bool custom_v_anchors = false;
	string custom_v_anchors_path;
	bool custom_j_anchors = false;
	string custom_j_anchors_path;

	//Input sequences variables
	bool read_seqs = false;
	Fileformat seqs_fileformat;
	string input_seqs_file;

	//Genomic templates list and aligns parms
	vector<pair<string,string>> v_genomic;
	vector<pair<string,string>> d_genomic;
	vector<pair<string,string>> j_genomic;
	unordered_map<string,size_t> v_CDR3_anchors;
	unordered_map<string,size_t> j_CDR3_anchors;
	bool align_data_is_CDR3 = false;

	//Model parms and marginals
	bool load_last_inferred_parms = false;
	bool custom_cl_parms = false;
	Model_Parms cl_model_parms;
	Model_marginals cl_model_marginals;
	map<size_t,shared_ptr<Counter>> cl_counters_list;

	//Sequence generation parms
	size_t generate_n_seq;
	bool generate_werr = true;
	bool gen_output_CDR3_data = false;
	string gen_filename_prefix="";
	int gen_random_engine_seed=-1; //-1 will cause IGoR to generate a time stamp based seed

	//Inference parms
	bool viterbi_inference = false;
	double likelihood_thresh_inference = 1e-60;
	double proba_threshold_ratio_inference = 1e-5;
	size_t n_iter_inference = 5;
	bool infer_only = false;
	bool no_infer = false;
	set<string> infer_restrict_nicknames;
	bool fix_err_rate = false;
	bool subsample_seqs = false;
	size_t n_subsample_seqs;

	//Sequence evaluation parms
	bool viterbi_evaluate = false;
	double likelihood_thresh_evaluate = 1e-60;;
	double proba_threshold_ratio_evaluate = 1e-5;

	//Alignment parameters
	double heavy_pen_nuc44_vect [] = { // A,C,G,T,R,Y,K,M,S,W,B,D,H,V,N
	        5,-14,-14,-14,-14,2,-14,2,2,-14,-14,1,1,1,0,
	        -14,5,-14,-14,-14,2,2,-14,-14,2,1,-14,1,1,0,
	        -14,-14,5,-14,2,-14,2,-14,2,-14,1,1,-14,1,0,
	        -14,-14,-14,5,2,-14,-14,2,-14,2,1,1,1,-14,0,
	        -14,-14,2,2,1.5,-14,-12,-12,-12,-12,1,1,-13,-13,0,
	        2,2,-14,-14,-14,1.5,-12,-12,-12,-12,-13,-13,1,1,0,
	        -14,2,2,-14,-12,-12,1.5,-14,-12,-12,1,-13,-13,1,0,
	        2,-14,-14,2,-12,-12,-14,1.5,-12,-12,-13,1,1,-13,0,
	        2,-14,2,-14,-12,-12,-12,-12,1.5,-14,-13,1,-13,1,0,
	        -14,2,-14,2,-12,-12,-12,-12,-14,1.5,1,-13,1,-13,0,
	        -14,1,1,1,1,-13,1,-13,-13,1,0.5,-12,-12,-12,0,
	        1,-14,1,1,1,-13,-13,1,1,-13,-12,0.5,-12,-12,0,
	        1,1,-14,1,-13,1,-13,1,-13,1,-12,-12,0.5,-12,0,
	        1,1,1,-14,-13,1,1,-13,1,-13,-12,-12,-12,0.5,0,
	        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	Matrix<double> heavy_pen_nuc44_sub_matrix(15,15,heavy_pen_nuc44_vect);

		//V alignment vars
		bool align_v = false;
		string v_align_filename = "V_alignments.csv";
		double v_align_thresh_value = 50.0;
		Matrix<double> v_subst_matrix = heavy_pen_nuc44_sub_matrix;
		double v_gap_penalty = 50.0;
		bool v_best_align_only = true;
		bool v_best_gene_only = false;
		int v_left_offset_bound = INT16_MIN;
		int v_right_offset_bound = INT16_MAX;
		unordered_map<string,pair<int,int>> v_template_bounds_map;
		bool v_reversed_offsets = false;

		//D alignment vars
		bool align_d = false;
		string d_align_filename = "D_alignments.csv";
		double d_align_thresh_value = 15.0;
		Matrix<double> d_subst_matrix = heavy_pen_nuc44_sub_matrix;
		double d_gap_penalty = 50.0;
		bool d_best_align_only = false;
		bool d_best_gene_only = false;
		int d_left_offset_bound = INT16_MIN;
		int d_right_offset_bound = INT16_MAX;
		unordered_map<string,pair<int,int>> d_template_bounds_map;
		bool d_reversed_offsets = false;

		//J alignment vars
		bool align_j = false;
		string j_align_filename = "J_alignments.csv";
		double j_align_thresh_value = 15.0;
		Matrix<double> j_subst_matrix = heavy_pen_nuc44_sub_matrix;
		double j_gap_penalty = 50.0;
		bool j_best_align_only = true;
		bool j_best_gene_only = false;
		int j_left_offset_bound = INT16_MIN;
		int j_right_offset_bound = INT16_MAX;
		unordered_map<string,pair<int,int>> j_template_bounds_map;
		bool j_reversed_offsets = false;

		// Flag to extract CDR3 from aligned sequences.
		bool b_feature		  = true;
		bool b_feature_CDR3 = true;


	while(carg_i<argc){

		//Command line argument asking for help
		if(string(argv[carg_i]) == string("-h")
				or string(argv[carg_i]) == string("-help")){
			// Show the manual using man and installed manpages
			system(&("man igor")[0]);
			// End the program without error
			return 0;
		}

		//Command line argument asking for help
		if(string(argv[carg_i]) == string("-v")
				or string(argv[carg_i]) == string("-version")){
			// Display IGoR's version
			cout<<"IGoR version "<<PACKAGE_VERSION<<endl;
			clog<<"Visit "<<PACKAGE_URL<<" to check the latest version!"<<endl;
			// End the program without error
			return 0;
		}

		//Command line argument asking for igor datadir
		if(string(argv[carg_i]) == string("-getdatadir")){
			// Print IGoR's data directory path
			cout<<IGOR_DATA_DIR<<endl;
			// End the program without error
			return 0;
		}

		//Command line argument setting the number of threads
		if(string(argv[carg_i]) == string("-threads")){
			omp_set_num_threads(std::stoi(argv[++carg_i]));
			clog<<"Setting number of threads to: "<<argv[carg_i]<<endl;
		}

		//Command line to redirect the standard output to a file
		else if(string(argv[carg_i]) == string("-stdout_f")){
			clog<<"Redirecting output to file: "<<argv[carg_i+1]<<endl;
			freopen(argv[++carg_i],"a+",stdout);
		}

		else if(string(argv[carg_i]) == string("-batch")){
			++carg_i;
			batchname = argv[carg_i];
			if(batchname[batchname.size()-1] != '_'){
				batchname.append("_");
			}
			clog<<"Batch name set to: "<<batchname<<endl;
		}

		//Set custom genomic template
		else if(string(argv[carg_i]) == string("-set_genomic")){
			//Throw an error if not found?
			while((carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and string(argv[carg_i+1]).substr(0,2) == "--"){

				++carg_i;

				if(string(argv[carg_i]) == "--V"){
					custom_v = true;
					++carg_i;
					custom_v_path = string(argv[carg_i]);
				}
				else if(string(argv[carg_i]) == "--D"){
					custom_d = true;
					++carg_i;
					custom_d_path = string(argv[carg_i]);
				}
				else if(string(argv[carg_i]) == "--J"){
					custom_j = true;
					++carg_i;
					custom_j_path = string(argv[carg_i]);
				}
				else{
					return terminate_IGoR_with_error_message("Unknown gene argument \"" + string(argv[carg_i]) +"\" to set genomic templates");
				}
			}

			if((not custom_v)
					and (not custom_d)
					and (not custom_j)){
				return terminate_IGoR_with_error_message("No gene argument was passed after -set_genomic");
			}
		}

		else if(string(argv[carg_i]) == string("-set_CDR3_anchors")){
			while((carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and string(argv[carg_i+1]).substr(0,2) == "--"){

				++carg_i;

				if(string(argv[carg_i]) == "--V"){
					custom_v_anchors = true;
					++carg_i;
					custom_v_anchors_path = string(argv[carg_i]);
				}
				else if(string(argv[carg_i]) == "--J"){
					custom_j_anchors = true;
					++carg_i;
					custom_j_anchors_path = string(argv[carg_i]);
				}
				else{
					return terminate_IGoR_with_error_message("Unknown gene argument \"" + string(argv[carg_i]) +"\" to set CDR3 anchors");
				}
			}

			if((not custom_v_anchors)
					and (not custom_j_anchors)){
				return terminate_IGoR_with_error_message("No gene argument was passed after -set_CDR3_anchors");
			}
		}

		else if(string(argv[carg_i]) == "-set_custom_model"){
			custom_cl_parms = true;
			++carg_i;
			try{
				cl_model_parms.read_model_parms(string(argv[carg_i]));
			}catch(exception& e){
				return terminate_IGoR_with_error_message("Exception caught while reading custom model parms after \"-set_custom_model\"",  e);
			}
			cl_model_marginals = Model_marginals(cl_model_parms);
			if((carg_i+1)<argc
					and (string(argv[carg_i+1]).substr(0,1)!=string("-"))){
				++carg_i;
				//Check if the next argument is a new command or the corresponding marginal file
				try{
					cl_model_marginals.txt2marginals(string(argv[carg_i]),cl_model_parms);
				}
				catch(exception& e){
					forward_list<string> error_messages;
					error_messages.emplace_front("If you have altered the default model structure corresponding marginals will be created if no model marginals file is passed.");
					error_messages.emplace_front("Make sure file exist or that supplied Model_Parms and Model_Marginals match.");
					error_messages.emplace_front("Exception caught while reading custom marginals after \"-set_custom_model\"");
					return terminate_IGoR_with_error_message(error_messages, e);
				}
			}
			else{
				clog<<"No model marginals file was provided with the custom model parameters, initializing corresponding marginals to a uniform distribution!"<<endl;
				cl_model_marginals.uniform_initialize(cl_model_parms);
			}

			//Check if the model contains a D gene event in order to load the alignments
			auto events_map = cl_model_parms.get_events_map();
			if(events_map.count(tuple<Event_type,Gene_class,Seq_side>(GeneChoice_t,D_gene,Undefined_side))>0){
				has_D = true;
			}
		}

		else if(string(argv[carg_i]) == "-load_last_inferred"){
			//Cannot read straight here since the working directory have not been defined yet
			load_last_inferred_parms = true;
		}

		else if(string(argv[carg_i]) == "-run_demo"){
			clog<<"Running demo code"<<endl;
			run_demo = true;
		}

		else if(string(argv[carg_i]) == "-run_custom"){
			clog<<"Running custom code"<<endl;
			custom = true;
		}

		else if(string(argv[carg_i]) == "-subsample"){
			subsample_seqs = true;
			++carg_i;
			try{
				n_subsample_seqs = stoi(argv[carg_i]);
			}
			catch(exception& e){
				return terminate_IGoR_with_error_message("Expected an integer for the number of sequences to subsample, received: \"" + string(argv[carg_i]) + "\"");
			}
		}

		else if(string(argv[carg_i]) == "-align"){
			//Provide a boolean for aligning
			align = true;
			//Check for additional parameters specific to each gene
			while(	(carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and (string(argv[carg_i+1]).substr(0,2) == "--")){
				++carg_i;
				string gene_str_val = string(argv[carg_i]);

				//Define init booleans and corresponding variables
				bool thresh_provided = false;
				double thresh_value;

				bool matrix_provided = false;
				//Matrix subst_matrix;

				bool gap_penalty_provided = false;
				double gap_penalty;

				bool best_align_only_provided = false;
				bool best_gene_only_provided = false;
				bool best_align_only;
				bool best_gene_only;

				bool offset_bounds_provided = false;
				bool template_bounds_provided = false;
				int left_offset_bound;
				int right_offset_bound;
				bool reversed_offset_provided = false;
				bool reversed_offsets;
				unordered_map<string,pair<int,int>> template_bounds_map;

				if( (gene_str_val == "--V")
						or (gene_str_val == "--D")
						or (gene_str_val == "--J")
						or (gene_str_val == "--all")){

					while( (carg_i+1<argc)
							and (string(argv[carg_i+1]).size()>3)
							and (string(argv[carg_i+1]).substr(0,3) == string("---"))){

						++carg_i;

						if(string(argv[carg_i]) == "---thresh"){
							//Read the alignment score threshold
							++carg_i;
							try{
								thresh_value = stod(string(argv[carg_i]));
							}
							catch (exception& e) {
								return terminate_IGoR_with_error_message("Expected a float for the alignment score threshold, received: \"" + string(argv[carg_i]) + "\"");
							}
							thresh_provided = true;
						}
						else if(string(argv[carg_i]) == "---matrix"){
							//Read the substitution matrix from a file
							++carg_i;
							string matrix_filename = string(argv[carg_i]);
							try{
								if((gene_str_val == "--V") or (gene_str_val == "--all")){
									v_subst_matrix = read_substitution_matrix(matrix_filename);
								}
								if((gene_str_val == "--D") or (gene_str_val == "--all")){
									d_subst_matrix = read_substitution_matrix(matrix_filename);
								}
								if((gene_str_val == "--J") or (gene_str_val == "--all")){
									j_subst_matrix = read_substitution_matrix(matrix_filename);
								}
							}
							catch(exception& e){
								return terminate_IGoR_with_error_message("Exception caught while reading the provided substitution matrix for gene: " + gene_str_val,  e);
							}

						}
						else if(string(argv[carg_i]) == "---gap_penalty"){
							//Read the gap penalty
							++carg_i;
							try{
								gap_penalty = stod(string(argv[carg_i]));
							}
							catch (exception& e) {
								return terminate_IGoR_with_error_message("Expected a float for the alignment gap penalty, received: \"" + string(argv[carg_i]) + "\"");
							}
							gap_penalty_provided = true;
						}
						else if(string(argv[carg_i]) == "---best_align_only"){
							//Set the best alignment only boolean
							++carg_i;
							if(string(argv[carg_i]) == "true"){
								best_align_only = true;
							}
							else if(string(argv[carg_i]) == "false"){
								best_align_only = false;
							}
							else{
								return terminate_IGoR_with_error_message("Unkown argument received\"" + string(argv[carg_i]) + "\"to set best alignment only boolean, existing values are: true, false");
							}
							best_align_only_provided = true;

						}
						else if(string(argv[carg_i]) == "---best_gene_only"){
							//Set the best alignment only boolean
							++carg_i;
							if(string(argv[carg_i]) == "true"){
								best_gene_only = true;
							}
							else if(string(argv[carg_i]) == "false"){
								best_gene_only = false;
							}
							else{
								return terminate_IGoR_with_error_message("Unkown argument received\"" + string(argv[carg_i]) + "\"to set best gene/allele candidate only boolean, existing values are: true, false");
							}
							best_gene_only_provided = true;

						}
						else if(string(argv[carg_i]) == "---template_spec_offset_bounds"){
							//Read the offset bounds
							++carg_i;
							try{
								template_bounds_map = read_template_specific_offset_csv(string(argv[carg_i]));
							}
							catch (exception& e) {
								return terminate_IGoR_with_error_message("Exception caught reading a semi-colon separated offset file \"" + string(argv[carg_i]) + "\" for template specific offset bounds.",e);
							}

							template_bounds_provided = true;
						}
						else if(string(argv[carg_i]) == "---offset_bounds"){
							//Read the offset bounds
							++carg_i;
							try{
								left_offset_bound = stoi(string(argv[carg_i]));
							}
							catch (exception& e) {
								return terminate_IGoR_with_error_message("Expected an integer for the left offset bound, received: \"" + string(argv[carg_i]) + "\"");
							}

							++carg_i;
							try{
								right_offset_bound = stoi(string(argv[carg_i]));
							}
							catch (exception& e) {
								return terminate_IGoR_with_error_message("Expected an integer for the right offset bound, received: \"" + string(argv[carg_i]) + "\"");
							}
							offset_bounds_provided = true;
						}
						else if(string(argv[carg_i]) == "---reversed_offsets"){
							//Set the best alignment only boolean
							++carg_i;
							if(string(argv[carg_i]) == "true"){
								reversed_offsets = true;
							}
							else if(string(argv[carg_i]) == "false"){
								reversed_offsets = false;
							}
							else{
								return terminate_IGoR_with_error_message("Unkown argument received\"" + string(argv[carg_i]) + "\"to set reversed offsets boolean, existing values are: true, false");
							}
							reversed_offset_provided = true;
						}
						else{
							return terminate_IGoR_with_error_message("Unknown parameter\"" + string(argv[carg_i]) +"\" for gene " + gene_str_val + " in -align " );
						}
					}
				}
				else if(string(argv[carg_i]) == "--ntCDR3"){
					align_data_is_CDR3 = true;
					// Set the the V and J align thresholds accordingly
					v_align_thresh_value = 0;
					j_align_thresh_value = 0;
				}
				else if(string(argv[carg_i]) == "--feature"){
					// Option to extract feature of (nucleotides) sequences
					b_feature		  = true;
					while( (carg_i+1<argc)
							and (string(argv[carg_i+1]).size()>3)
							and (string(argv[carg_i+1]).substr(0,3) == string("---"))){

						++carg_i;
						// FIXME: Think on a better name for this subsuboption, could be confusing with the -align --ntCDR3
						if(string(argv[carg_i]) == "---ntCDR3"){
							++carg_i;
							b_feature_CDR3 = true;
						}
						else{
							return terminate_IGoR_with_error_message("Unknown --feature parameter\"" + string(argv[carg_i]) + " in -align " );
						}
					}
				}
				else{
					return terminate_IGoR_with_error_message("Unknown gene specification\"" + string(argv[carg_i]) + "\"for -align");
				}

				//Now assign back the values to the correct variables
				if( (gene_str_val == "--V") or (gene_str_val == "--all")){
					align_v = true;
					if(thresh_provided){
						v_align_thresh_value = thresh_value;
					}

					if(matrix_provided){
						//v_subst_matrix = subst_matrix;
					}

					if(gap_penalty_provided){
						v_gap_penalty = gap_penalty;
					}

					if(best_align_only_provided){
						v_best_align_only = best_align_only;
					}

					if(best_gene_only_provided){
						v_best_gene_only = best_gene_only;
					}

					if(template_bounds_provided){
						v_template_bounds_map = template_bounds_map;
					}

					if(offset_bounds_provided){
						v_left_offset_bound = left_offset_bound;
						v_right_offset_bound = right_offset_bound;
					}

					if(reversed_offset_provided){
						v_reversed_offsets = reversed_offsets;
					}
				}
				if( (gene_str_val == "--D") or (gene_str_val == "--all")){
					align_d = true;
					if(thresh_provided){
						d_align_thresh_value = thresh_value;
					}

					if(matrix_provided){
						//d_subst_matrix = subst_matrix;
					}

					if(gap_penalty_provided){
						d_gap_penalty = gap_penalty;
					}

					if(best_align_only_provided){
						d_best_align_only = best_align_only;
					}

					if(best_gene_only_provided){
						d_best_gene_only = best_gene_only;
					}

					if(template_bounds_provided){
						d_template_bounds_map = template_bounds_map;
					}

					if(offset_bounds_provided){
						d_left_offset_bound = left_offset_bound;
						d_right_offset_bound = right_offset_bound;
					}

					if(reversed_offset_provided){
						d_reversed_offsets = reversed_offsets;
					}
				}
				if( (gene_str_val == "--J") or (gene_str_val == "--all")){
					align_j = true;
					if(thresh_provided){
						j_align_thresh_value = thresh_value;
					}

					if(matrix_provided){
						//j_subst_matrix = subst_matrix;
					}

					if(gap_penalty_provided){
						j_gap_penalty = gap_penalty;
					}

					if(best_align_only_provided){
						j_best_align_only = best_align_only;
					}

					if(best_gene_only_provided){
						j_best_gene_only = best_gene_only;
					}

					if(template_bounds_provided){
						j_template_bounds_map = template_bounds_map;
					}

					if(offset_bounds_provided){
						j_left_offset_bound = left_offset_bound;
						j_right_offset_bound = right_offset_bound;
					}

					if(reversed_offset_provided){
						j_reversed_offsets = reversed_offsets;
					}
				}

			}
		}

		else if( (string(argv[carg_i]) == "-infer") or (string(argv[carg_i]) == "-evaluate")){
			//Provide a boolean for inference
			if(string(argv[carg_i]) == "-infer"){
				infer = true;
			}
			else{
				evaluate = true;
			}

			while( (carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and string(argv[carg_i+1]).substr(0,2)=="--"){
				++carg_i;
				//Some inference parameters are passed
				if(string(argv[carg_i]) == "--L_thresh"){
					double l_thresh;
					++carg_i;
					try{
						l_thresh = stod(string(argv[carg_i]));
					}
					catch(exception& e){
						return terminate_IGoR_with_error_message("Expected a float for the likelihood threshold, received: \"" + string(argv[carg_i]) + "\"");
					}

					if(infer){
						likelihood_thresh_inference = l_thresh;
					}
					else{
						likelihood_thresh_evaluate = l_thresh;
					}
				}
				else if(string(argv[carg_i]) == "--MLSO"){
					if(infer){
						viterbi_inference = true;
					}
					else{
						viterbi_evaluate = true;
					}
				}
				else if(string(argv[carg_i]) == "--P_ratio_thresh"){
					double p_ratio;
					++carg_i;
					try{
						p_ratio = stod(string(argv[carg_i]));
					}
					catch(exception& e){
						return terminate_IGoR_with_error_message("Expected a float for the probability ratio threshold, received: \"" + string(argv[carg_i]) + "\"");
					}

					if(infer){
						proba_threshold_ratio_inference = p_ratio;
					}
					else{
						proba_threshold_ratio_evaluate = p_ratio;
					}

				}
				else if(string(argv[carg_i]) == "--N_iter"){
					if(infer){
						++carg_i;
						try{
							n_iter_inference = stoi(string(argv[carg_i]));
						}
						catch(exception& e){
							return terminate_IGoR_with_error_message("Expected an integer for the number of iterations to perform for the inference, received: \"" + string(argv[carg_i]) + "\"");
						}
					}
					else{
						return terminate_IGoR_with_error_message("Invalid argument \"--N_iter\" for -evaluate");
					}
				}
				else if( (string(argv[carg_i]) == "--infer_only") or (string(argv[carg_i]) == "--not_infer")){
					if(string(argv[carg_i]) == "--infer_only"){
						infer_only = true;
					}
					else{
						no_infer = true;
					}

					//Now read the event nicknames and append to the list
					//Nicknames are added to the same list for infer_only or not_infer since they are exclusive
					//An exception will be raised later if both were given
					while( (carg_i+1<argc)
							and string(argv[carg_i+1]).size()>=1
							and string(argv[carg_i+1]).substr(0,1)!="-"){
						++carg_i;
						infer_restrict_nicknames.emplace(argv[carg_i]);
					}
				}
				else if(string(argv[carg_i]) == "--fix_err"){
					fix_err_rate = true;
				}


				else{
					return terminate_IGoR_with_error_message("Unknown argument \""+string(argv[carg_i])+"\" to specify inference/evaluate parameters");
				}
			}
		}



		else if(string(argv[carg_i]) == "-chain"){
			//Provide a boolean for the choice of a chain type (thus a set of genomic templates and model)
			chain_provided = true;
			++carg_i;
			if( (string(argv[carg_i]) == "alpha") or (string(argv[carg_i]) == "TRA")
					or (string(argv[carg_i]) == "beta") or (string(argv[carg_i]) == "TRB")
					or (string(argv[carg_i]) == "light")
					or (string(argv[carg_i]) == "heavy_naive")
					or (string(argv[carg_i]) == "heavy_memory")
					or (string(argv[carg_i]) == "lambda") or (string(argv[carg_i]) == "IGL")
					or (string(argv[carg_i]) == "kappa") or (string(argv[carg_i]) == "IGK")){
				chain_arg_str = string(argv[carg_i]);
				clog<<"Chain parameter set to: "<<chain_arg_str<<endl;
			}
			else{
				return terminate_IGoR_with_error_message("Unknown argument \""+string(argv[carg_i])+"\" to specify the chain choice!\n Supported arguments are: TRA (or alpha), TRB (or beta), heavy_naive , heavy_memory , light, IGL (or lambda), IGK (or kappa)");
			}
		}

		else if(string(argv[carg_i]) == "-species"){
			//TODO add a check on the existence of the species
			species_provided = true;
			++carg_i;
			species_str = string(argv[carg_i]);
			clog<<"Species parameter set to: "<<species_str<<endl;
		}

		/*
		 * Set the working directory
		 * /!\ Needs to be set before all the counters !  /!\
		 */
		else if(string(argv[carg_i]) == "-set_wd"){
			wd = true;
			++carg_i;
			cl_path = string(string(argv[carg_i]));

			//Append a "/" if there is not one at the end of the directory path
			if (cl_path[cl_path.size()-1] != '/'){
				cl_path+="/";
			}

			if( not cl_counters_list.empty()){
				return terminate_IGoR_with_error_message("Working directory needs to be set before declaring the counters, please re-order the arguments");
			}
		}

		/*
		 * Output arguments parsing
		 */
		else if(string(argv[carg_i]) == "-output"){
			while( (carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and string(argv[carg_i+1]).substr(0,2)=="--"){

				++carg_i;
				/*
				 * TODO For now forget about outputing for every sequences / every iterations (more command line parameters to code)
				 */
				if(string(argv[carg_i]) == "--Pgen"){
					shared_ptr<Counter> pgen_counter_ptr(new Pgen_counter (cl_path + "output/"));
					cl_counters_list.emplace(cl_counters_list.size(),pgen_counter_ptr);
				}
				else if(string(argv[carg_i]) == "--scenarios"){
					int n_record_scenarios;
					++carg_i;
					try{
						n_record_scenarios = stoi(string(argv[carg_i]));
					}
					catch(exception& e){
						return terminate_IGoR_with_error_message("Expected the number of scenarios to be recorded by the best scenario counter, received: \"" + string(argv[carg_i]) + "\"");
					}

					if(n_record_scenarios<=0){
						return terminate_IGoR_with_error_message("Number of scenarios to be recorded must be greater than zero");
					}

					shared_ptr<Counter>best_sc_ptr(new Best_scenarios_counter(n_record_scenarios , cl_path + "output/" ,true));
					cl_counters_list.emplace(cl_counters_list.size(),best_sc_ptr);
				}
				else if(string(argv[carg_i]) == "--coverage"){
					Gene_class chosen_gc;
					++carg_i;
					try{
						chosen_gc = str2GeneClass(string(argv[carg_i]));
					}
					catch(exception& e){
						return terminate_IGoR_with_error_message("Unknown argument \""+string(argv[carg_i])+"\" to specify coverage target!\n Supported arguments are: V_gene, VD_genes, D_gene, DJ_gene, VJ_gene, J_gene, VDJ_genes");
					}
					shared_ptr<Counter> coverage_counter_ptr(new Coverage_err_counter(cl_path + "output/",chosen_gc,1,false,true));
					cl_counters_list.emplace(cl_counters_list.size(),coverage_counter_ptr);
				}
				else{
					return terminate_IGoR_with_error_message("Unknown subargument \""+string(argv[carg_i])+"\" to specify outputs");
				}
			}
		}

		/*
		 * Sequence generation arguments parsing
		 */
		else if(string(argv[carg_i]) == "-generate"){
			generate = true;
			++carg_i;

			//Number of sequences to generate must be given before optionnal arguments
			try{
				generate_n_seq = stoi(string(argv[carg_i]));
			}
			catch(exception& e){
				return terminate_IGoR_with_error_message("Expected the number of sequences to generate, received: \"" + string(argv[carg_i]) + "\"");
			}

			while( (carg_i+1<argc)
					and (string(argv[carg_i+1]).size()>2)
					and string(argv[carg_i+1]).substr(0,2) == "--"){

				++carg_i;

				if(string(argv[carg_i]) == "--noerr"){
					generate_werr = false;
				}
				else if(string(argv[carg_i]) == "--CDR3"){
					gen_output_CDR3_data = true;
				}
				else if(string(argv[carg_i]) == "--name"){
					++carg_i;
					gen_filename_prefix = string(argv[carg_i])+"_";
				}
				else if(string(argv[carg_i]) == "--seed"){

					++carg_i;
					try{
						double tmp_seed = stod(string(argv[carg_i]));
						//Make sure the passed value is a positive integer
						if(tmp_seed<0
								or ((int) tmp_seed - tmp_seed)!=0.0){
							return terminate_IGoR_with_error_message("The random generator seed after \"--seed\" must be a positive integer");
						}
					}
					catch(exception& e){
						return terminate_IGoR_with_error_message("Expected a positive integer after \"--seed\" for sequence generation's seed, received: \"" + string(argv[carg_i]) + "\"");
					}
					gen_random_engine_seed = stoi(string(argv[carg_i]));
				}
				else{
					return terminate_IGoR_with_error_message("Unknown argument \""+string(argv[carg_i])+"\" to specify sequence generation parameters");
				}
			}

		}

		/*
		 * Input sequences argument parsing
		 */
		else if(string(argv[carg_i]) == "-read_seqs"){
			read_seqs = true;
			++carg_i;
			input_seqs_file = string(argv[carg_i]);
			//Get the extension index
			size_t extension_index = input_seqs_file.rfind(".");
			if(extension_index!=string::npos){
				string tmp_str = input_seqs_file.substr(extension_index , string::npos );
				transform(tmp_str.begin(),tmp_str.end(),tmp_str.begin(),::tolower);
				if( tmp_str == ".fasta" ){
					seqs_fileformat = FASTA_f;
					clog<<"FASTA extension detected for the input sequence file"<<endl;
				}
				else if(tmp_str == ".csv"){
					seqs_fileformat = CSV_f;
					clog<<"CSV extension detected for the input sequence file"<<endl;
				}
				else if(tmp_str == ".txt"){
					seqs_fileformat = TXT_f;
					clog<<"TXT extension detected for the input sequence file"<<endl;
				}
				else{
					return terminate_IGoR_with_error_message("Unknown file extension \"" + tmp_str + "\" for input sequences file! ");
				}
			}
			else{
				clog<<"No extension detected for the input sequence file assuming a text file without header"<<endl;
				seqs_fileformat = TXT_f;
			}
		}

		//If the argument doesbeta not correspond to any previous section throw an exception
		else{
			return terminate_IGoR_with_error_message("Unknown IGoR command line argument \""+string(argv[carg_i])+"\" ");
		}

		//Read the next command line argument
		++carg_i;
	}

return 0;
}
