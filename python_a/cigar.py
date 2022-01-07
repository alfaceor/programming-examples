#!/usr/bin/env python3

def get_cigar_format(str_seq_reference, str_seq_read, read_offset=None):
    if read_offset is None:
        read_offset = 0
    return str_seq_reference


if __name__ == '__main__':
    str_seq_read = "TATTCATCAAGGGG"
    str_seq_reference = "ACTATTCATCAA"
    # for each character in read 
    for ii, nt_ref in enumerate(str_seq_reference):
        print(ii, nt_ref)
    for nt_read in str_seq_read:
        print(nt_read)



