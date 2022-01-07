#!/usr/bin/gnuplot

array="value1 value2 value3 value4"
array2=system("cat data.dat")
Nvalues=words(array2)
value=word(array2,6)+0
print sprintf("value is %g",value)
