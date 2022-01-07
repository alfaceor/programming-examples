#!/bin/bash
pdflatex Presentation.tex
biber Presentation.bcf
pdflatex Presentation.tex
pdflatex Presentation.tex
