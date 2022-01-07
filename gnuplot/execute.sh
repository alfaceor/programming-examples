#!/bin/bash

gnuScriptName="exampletArguments.plt"
#arguments="\"aaa='5'\" "
arguments="aaa='5';bbb=7 "
echo ${arguments}
comando="gnuplot -e ${arguments} ${gnuScriptName} "
echo ${comando}
${comando}
