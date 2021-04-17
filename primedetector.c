/*
Funzione che determina se un numero è primo.
*/
#include <stdlib.h>
#include <stdio.h>

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
    printf("Inserisci un valore intero positivo.\n");
    scanf("%d", &valore);

    if(prime(valore) == 1)
    {
     printf("%d è un numero primo.\n", valore);
    }

    if(prime(valore) == 0)
    {
     printf("%d non è un numero primo.\n", valore);
    }
    
    exit(0);
}
