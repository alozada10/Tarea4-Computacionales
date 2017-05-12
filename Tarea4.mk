

Resultados_hw4.pdf : *.png Resultados_hw4.tex
	pdflatex Resultados_hw4.tex

*.png : *.txt Plots_Temperatura.py
	python Plots_Temperatura.py

*.txt : a.out
	./a.out

a.out : DifusionTemperatura.c
	gcc DifusionTemperatura.c
