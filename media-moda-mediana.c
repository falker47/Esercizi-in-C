//Programma che calcola MEDIA-MODA-MEDIANA

/*
le righe il cui commento è "***" indica che
tale riga serve solo ad abbellire l'interfaccia
del programma (infatti tali righe non hanno
impatto sul funzionamento del programma)
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N;//indica il numero di dati che saranno usati
    printf("--------------------------------------------\n");// ***
    printf("CALCOLATORE DI MEDIA-MODA-MEDIANA\n");
    printf("--------------------------------------------\n");// ***
    printf("Inserisci la quantità di dati che andrai ad inserire:\n");
    scanf("%d", &N);
    printf("...\n");// ***

    float dati[N]; //ora che abbiamo fissato il numero di dati creiamo un array di N elementi
    float somma = 0;
    int posizioneN = 1;//variabile che servirà ad orientare l'utente (non è fondamentale per il funzionamento del programma)

    printf("------------------------\n");// ***
    for(int counter1 = 0; counter1 < N; counter1++)//ciclo che permette di inserire gli N elementi dentro l'array
    {
        printf("Inserisci il dato N°%d:\n", posizioneN);//qui si vede lo scopo della veriabile "Posizione N"
        scanf("%f", &dati[counter1]);
        printf("...\n");// ***
        posizioneN++;
        somma = somma + dati[counter1]; //calcola la somma parziale degli elementi, così una volta finito il ciclo abbiamo già la somma tot degli N elementi necessaria per calcolare la media
    }

    int Nsort = N; //variabile che permetterà l'ordinamento degli N elementi (serve per trovare la mediana)
    int counter3 = 1;
    int tmp = 0;//variabile volante che servirà per scambiare di posizione gli N elementi

    for(int counter2 = 0; counter2 < N; counter2++) //ordina gli elementi dell'array in ordine crescente
    {
        float max = dati[0];//ipotizza che il primo elemento sia il massimo di tutti gli N elementi

        while(counter3 < Nsort)//individua il massimo tra gli N elementi
        {
            if(max < dati[counter3])
            {
                tmp = counter3; //tmp salva la posizione del massimo
                max = dati[counter3]; //salva il valore massimo
            }
            counter3++;
        }
        //i prossimi passaggi permetteranno di mettere il massimo nella posizione finale
        counter3 = 1;
        Nsort--; //dato che è un ciclo la posizione dell'elemento finale dovrà scalare progressivamente in modo da non considerare più il massimo nel prossimo ciclo ma troverà il 2° più grande, poi il 3° ecc.
        if(Nsort > 1)
        {
            dati[tmp] = dati[Nsort]; // in queste due righe avviene lo scambio
            dati[Nsort] = max;
        }
        if(Nsort <= 1 && N != 1)
        {
            if(dati[0] > dati[1])
            {
                float tmp_fl = dati[0];
                dati[0] = dati[1];
                dati[1] = tmp_fl;
            }
        }
    }

    float moda_min;
    float moda_max;
    int counter_freqmax = 0;
    int counter_freq = 0;
    int counter_freq2 = 0;

    for(int counter4 = 0; counter4 < N; counter4++) //calcola le frequenze dei valori per trovare la moda
    {
        for(int counter5 = 0; counter5 < N; counter5++)
        {
            if(dati[counter4] == dati[counter5])
            {
                counter_freq++;
            }
        }
        if(counter_freq > counter_freqmax)
        {
            counter_freqmax = counter_freq;
            moda_min = dati[counter4];
        }
        if(counter_freq == counter_freqmax)
        {
            moda_max = dati[counter4];
            counter_freq2 = counter_freqmax;
        }
        counter_freq = 0;
    }

    float media = somma / N; //calcola la media
    printf("--------------------------------------------\n"); // ***
    printf("La somma dei valori è: %f\n", somma);
    printf("La media dei valori è: %f\n", media);
    printf("\n");

    float mediana_sx = dati[(N/2)-1]; //individua la mediana
    float mediana_dx = dati[N/2];
    float mediana = dati[(N-1)/2];

    if(N % 2 == 0)
    {
        printf("Ci sono due mediane: (%f|%f)\n", mediana_sx, mediana_dx);
    }
    if(N % 2 != 0)
    {
        printf("C'è un'unica mediana: %f\n", mediana);
    }

    printf("\n");

    if(counter_freqmax == counter_freq2 && moda_max != moda_min) //individua la moda e se ne esistono più di una (la frequenza massima è condivisa da elementi diversi)
    {
        printf("Ci sono più mode di frequenza %d:\n" ,counter_freqmax);
        printf("La moda minima è: %f\n", moda_min);
        printf("La moda massima è: %f\n", moda_max);
    }
    else
    {
        printf("La moda è: %f con una frequenza di %d\n", moda_min, counter_freqmax);
    }

    printf("--------------------------------------------\n");
    
    exit(EXIT_SUCCESS); //serve per terminare il programma
}
