set term pdfcairo font "Arial,12"
set out 'r2fig.pdf'
unset key
plot [0:.5] sin(1/x) lw 2

