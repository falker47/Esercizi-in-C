/*
Programma che scompone un numero in un prodotto di numeri primi
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int prime(int valore) //funzione prime checker (verifica se un numero è primo)
{   //restituirà due valori: 1 se è primo, 0 se non lo è

    int primechecker = 1; // ipotizza che il numero sia primo

    if (valore == 1) //se il numero è 1, non è primo per definizione
    {
        primechecker = 0;
    }
    
    else //negli altri casi applichiamo il seguente algoritmo
    {
        for(int counter = 2; counter < valore; counter++) //verifichiamo se esiste un numero compreso tra 2  ed il valore stesso che sia un suo divisore
        {
            if(valore % counter == 0) //se esiste almeno un valore che sia divisore, il numero non è primo 
            {
                primechecker = 0;
            }
        }
    }
    return primechecker;
}

int main ()
{
    int valore = 0;

    printf("--------------------------------------\n");
    printf("Inserisci un valore intero positivo.\n");
    printf(" \n");
    printf("Il numero scelto sarà scomposto in un unico\n");
    printf("prodotto fra numeri primi.\n");
    printf("--------------------------------------\n");
    scanf("%d", &valore);
    printf("...\n");
    
    if (prime(valore) == 0) //controlliamo se il numero è primo
    {
        printf("%d è un numero primo.\n", valore);
        printf("--------------------------------------\n");
    }
    if (prime(valore) == 1) //in caso non lo fosse il programma entra in azione
    {
        printf("%d si scompone nei seguenti fattori primi:\n", valore);
        printf("--------------------------------------\n");

        for( int counter = (valore - 1); counter > 1; counter--) //confronta tutti i valori inferiori al valore scelto alla ricerca di un opportuno divisore
        {
            if (prime(counter) == 0 ) //controlla se il potenziale counter è un numero primo
            {
                if(valore % counter == 0) //controlla se il numero primo (counter) è anche un divisore del valore
                {
                    int esponente = 0;
                    while(valore % counter == 0) //controlla quante volte counter divide il valore scelto
                    {
                        valore = valore / counter;
                        esponente++;
                    }
                    printf("%d^%d ", counter, esponente);
                }
            }
        }
        printf(" \n");
        printf("--------------------------------------\n");
    }
    exit(0);
}
