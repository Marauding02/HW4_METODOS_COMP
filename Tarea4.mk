all: a.out FIJAS.png Promedio_fijas.txt Resultados_hw4.tex

FIJAS.png: Plots_Temperatura.py
        python Plots_Temperatura.py

Resultados_hw4.tex: FIJAS.png 
	pdftex Resultados_hw4.tex 
    
a.out: DifusionTemperatura.c
        gcc DifusionTemperatura.c -lm
Promedio_fijas.txt:a.out
        ./a.out