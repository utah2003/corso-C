
#define _GNU_SOURCE
#include <stdio.h>  // Libreria per input/output                                                                                                                                     
#include <stdlib.h> // Libreria per vari funzioni utili                                                                                                                              
#include <string.h>  // Libreria per funzioni di stringa     
#include <assert.h>                                                                                                                        


//* DEFINIZIONE TIPI DI DATO E STRUTTURE NUOVE 
typedef int intero;
typedef int *puntatore_intero;

typedef struct duetto{
    intero primo;
    intero secondo;
}coppia;

//* DEFINIZIONE FUNZIONI DA USARE PER IL PROGRAMMA
intero differenza(coppia dupla);
void termina(const char *messaggio)
{
    perror(messaggio);
    exit(0);
}                                                                                                                                                                                                   

//* FUNZIONE PRINCIPALE
int main(int argc, char *argv[]) 
{   
    // Controllo di sicurezza che rassicura il compilatore
    int num_coppie = (argc - 1) / 2;
    if (num_coppie <= 0) {
        termina("Nessuna coppia valida trovata.");
    }
    if(num_coppie % 2 != 0 || argc == 1)termina("inserire un numero pari di numeri");

    coppia *array_coppie = malloc(((argc-1)/2)*sizeof(coppia));
    if(array_coppie == NULL)termina("malloc fallito!");
    intero indice_coppia_array = 0;

    for(intero i=1; i<argc-1; i+=2 ){
        array_coppie[indice_coppia_array].primo = atoi(argv[i]);
        array_coppie[indice_coppia_array].secondo = atoi(argv[i+1]);

        indice_coppia_array++;
    }

    coppia *array_ordinato_coppie = malloc(((argc-1)/2)*sizeof(coppia));
    if(array_ordinato_coppie == NULL)termina("malloc fallito");

    coppia min_coppia = array_coppie[0];

    for(int i = 1; i < indice_coppia_array; i++)
    {
        printf("i: %d --> (%d,%d)\n",i+1,array_coppie[i].primo,array_coppie[i].secondo);
        if(differenza(min_coppia) > differenza(array_coppie[i])){
            min_coppia = array_coppie[i];
        }
    }

    printf("(%d,%d)\n",min_coppia.primo, min_coppia.secondo);
    
    free(array_coppie);
    return 0;                                                                                                                                                                        
}                                                                                                                                                                                   
//* FINE FUNZIONE PRINCIPALE

//*FUNZIONI AGGIUNTIVE
intero differenza(coppia dupla)
{
    //assert(dupla);
    intero ris = dupla.primo - dupla.secondo;
    return ris;
}