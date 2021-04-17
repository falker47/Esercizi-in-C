//Risolve equazioni di secondo grado

/*
le righe il cui commento è "***" indica che
tale riga serve solo ad abbellire l'interfaccia
del programma (infatti tali righe non hanno
impatto sul funzionamento del programma)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //ci servirà per chiamare la funzione sqrt (radice quadrata)

int main ()

{
	float a, b, c, delta, x1, x2;
	printf("-----------------------------------\n"); // ***
	printf("RISOLUTORE EQUAZIONI DI SECONDO GRADO\n");
	printf("-----------------------------------\n"); // ***
	printf("Inserisci coefficiente di x^2:\n"); 
	scanf("%f", &a);
	printf("Inserisci coefficiente di x:\n");
	scanf("%f", &b);
	printf("Inserisci coefficiente del termine noto:\n");
	scanf("%f", &c);
	delta = (b*b - (4*a*c)); //formula per calcolare il delta

	if(delta < 0)//se delta è < 0 non esistono soluzioni reali
	{
		printf("-----------------------------------\n");// ***
		printf("Non esistono soluzioni reali.\n");
	}
	if(delta == 0)//se delta è = 0 esiste una singola soluzione (con molteplicità algebrica pari a 2, l'ho scritto per i più pignoli :) )
	{
		x1 = -b / (2*a); //dunque si applica la formula per calcolare le x1 e x2 considerando delta = 0
		printf("-----------------------------------\n");// ***
		printf("Esiste un'unica soluzione, x = %f\n", x1);
	}
	if(delta > 0)//se delta è > 0 esistono due soluzioni distinte
	{
		x1 = (-b + sqrt(delta)) / (2*a);
		x2 = (-b - sqrt(delta)) / (2*a);
		printf("-----------------------------------\n");// ***
		printf("Esistono due soluzioni:\n");
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
	}
	printf("-----------------------------------\n");// ***

	exit(EXIT_SUCCESS);
}
