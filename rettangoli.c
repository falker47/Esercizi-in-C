/*
Definite un tipo di dati adeguato a rappresentare
un rettangolo nel piano cartesiano, con i lati
paralleli agli assi (ragionate su quali informazioni
siano sufficienti a determinare univocamente il rettangolo).
Scrivete una funzione che, dato un rettangolo, ne calcola l’area.
Scrivete una funzione che, dati due rettangoli, calcola l’area
della regione in cui si sovrappongono (se i due rettangoli non
si sovrappongono, o si sovrappongono solo in un punto o in un lato,
la funzione deve restituire il valore 0).
Incorporate le due funzioni in un programma che collauda le due
funzioni in varie circostanze.
*/

#include <stdio.h>
#include <stdlib.h>

struct rettangolo //un rettangolo è definito da 4 punti di coordinate x,y su un piano cartesiano (i valori base e altezza servono per calcolarne l'area)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float base, altezza;
} R, R1, R2;

float area(struct rettangolo R)
{

    float A = R.base * R.altezza;

    return A;
}

float areacomune(struct rettangolo R1, struct rettangolo R2)
{
    float base, altezza, common_A; //common_A sarebbe l'area del rettangolo generato dalla sovrapposizione dei rettangolo R1 e R2

    if(R1.x1 >= R2.x3 || R2.x1 >= R1.x3) //se la (x) del vertice sx di R1 è >= del vertice dx di R2 oppure il vertice sx di R2 è >= del vertice dx di R1, R1 e R2 non si sovrappongono
    {
        common_A = 0; //e dunque l'area comune è 0
    }
    else
    {
        if(R1.y3 <= R2.y1 || R2.y3 <= R1.y1) //se la (y) del vertice alto di R1 è <= del vertice basso di R2 oppure il vertice alto di R2 è <= del vertice basso di R1, R1 e R2 non si sovrappongono
        {
            common_A = 0;
        }

        else //se non si verificano le due condizioni precedenti allora R1 e R2 si sovrappongono
        {
            float common_xmin, common_xmax, common_ymin, common_ymax;

            if(R1.x1 < R2.x1) //si cerca la x del vertice in basso a sx del rettangolo sovrapposto
            {
                common_xmin = R2.x1;
            }
            else
            {
                common_xmin = R1.x1;
            }

            if(R1.x3 < R2.x3) //si cerca la x del vertice in alto a dx del rettangolo sovrapposto
            {
                common_xmax = R1.x3;
            }
            else
            {
                common_xmax = R2.x3;
            }

            if(R1.y1 < R2.y1) //si cerca la y del vertice in basso a sx del rettangolo sovrapposto
            {
                common_ymin = R2.y1;
            }
            else
            {
                common_ymin = R1.y1;
            }

            if(R1.y3 < R2.y3) //si cerca la y del vertice in alto a dx del rettangolo sovrapposto
            {
                common_ymax = R1.y3;
            }
            else
            {
                common_ymax = R2.y3;
            }

            base = common_xmax - common_xmin;
            altezza = common_ymax - common_ymin;
            common_A = base * altezza;
        }
    }
    return common_A;
}

int main()
{
    printf("Inserisci la coordinata x del vertice in basso a sinistra del rettangolo R1.\n");
    scanf("%d", &R1.x1);
    printf("Inserisci la coordinata y del vertice in basso a sinistra del rettangolo R1.\n");
    scanf("%d", &R1.y1);
    printf("Inserisci la coordinata x del vertice in alto a destra del rettangolo R1.\n");
    scanf("%d", &R1.x3);
    printf("Inserisci la coordinata y del vertice in alto a destra del rettangolo R1.\n");
    scanf("%d", &R1.y3);

    R1.base = R1.x3 - R1.x1;
    R1.altezza = R1.y3 - R1.y1;

    R1.x2 = R1.x1 + R1.base;
    R1.y2 = R1.y1;


    R1.x4 = R1.x1;
    R1.y4 = R1.y1 + R1.altezza;

    printf("Inserisci la coordinata x del vertice in basso a sinistra del rettangolo R2.\n");
    scanf("%d", &R2.x1);
    printf("Inserisci la coordinata y del vertice in basso a sinistra del rettangolo R2.\n");
    scanf("%d", &R2.y1);
    printf("Inserisci la coordinata x del vertice in alto a destra del rettangolo R2.\n");
    scanf("%d", &R2.x3);
    printf("Inserisci la coordinata y del vertice in alto a destra del rettangolo R2.\n");
    scanf("%d", &R2.y3);

    R2.base = R2.x3 - R2.x1;
    R2.altezza = R2.y3 - R2.y1;

    R2.x2 = R2.x1 + R2.base;
    R2.y2 = R2.y1;

    R2.x4 = R2.x1;
    R2.y4 = R2.y1 + R2.altezza;


    float A1 = area(R1);
    float A2 = area(R2);
    float A0 = areacomune(R1, R2);

    printf("Il valore dell'area del rettangolo R1 è: %f\n", A1);
    printf("Il valore dell'area del rettangolo R2 è: %f\n", A2);
    printf("\n");
    if(A0 == 0)
    {
        printf("I due triangoli non si sovrappongono.\n");
    }
    else
    {
        printf("Il valore dell'area della regione in cui si intersecano\n");
        printf("i due rettangoli R1 e R2 è: %f\n", A0);
    }

    exit(0);

}
