
# Input: el archivo listo para plotar
# para eso debo generar el archivo talvez usando python


inFilename="XXXXX"
outFigName="YYYYY.tex"

set term tikz size 8.5, 6 standalone
set out outFigName
set print "-"

print outFigName

set xlabel "\Large $x$"
set ylabel "\Large $y$"

plot \
inFilename us 1:2 w l ls 1



