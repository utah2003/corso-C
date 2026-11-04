
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
    if (argc <= 2) {
        termina("Nessuna coppia valida trovata.");
    }
    if(argc % 2 == 0 || argc == 1)termina("inserire un numero pari di numeri");

    //! ------- CREAZIONE ARRAY DI COPPIE DAI PARAMETRI ------

    coppia *array_coppie = malloc(((argc-1)/2)*sizeof(coppia));
    if(array_coppie == NULL)termina("malloc fallito!");
    intero indice_coppia_array = 0;

    for(intero i=1; i<argc-1; i+=2 ){
        array_coppie[indice_coppia_array].primo = atoi(argv[i]);
        array_coppie[indice_coppia_array].secondo = atoi(argv[i+1]);

        indice_coppia_array++;
    }

    //! ------- ORDINAMENTO ARRAY ------------

    coppia *array_ordinato_coppie = malloc(((argc-1)/2)*sizeof(coppia));
    if(array_ordinato_coppie == NULL)termina("malloc fallito");
    int numero_coppie_ordinate = 0;

    int indice_elemento_eliminato;
    coppia min_coppia;

    int totale_coppie = indice_coppia_array;

    while(numero_coppie_ordinate != totale_coppie){

        min_coppia = array_coppie[0];
        indice_elemento_eliminato = 0;

        for(int i = 1; i < indice_coppia_array; i++)
        {
            if(differenza(min_coppia) > differenza(array_coppie[i])){
                min_coppia = array_coppie[i];
                indice_elemento_eliminato = i;
            }
        }
        //printf("i: %d --> (%d,%d)\n",indice_elemento_eliminato,min_coppia.primo,min_coppia.secondo);    
        //? ----> OUTPUT coppia minore con indice salvato per essere eleiminata dal vecchio array e aggiunta a nuovo!
        //*-- ADESSO HO:
        //*-- L INDICE DELLA COPPIA DA ELIMNARE;
        //*-- LA COPPIA DA ELIMINARE;

        //! --- MODIFICA ARRAY_COPPIE TOGLIENDO LA COPPIA SALVATA MINORE -----
        for(int z=indice_elemento_eliminato; z < indice_coppia_array; z++){
            array_coppie[z] = array_coppie[z+1];
        }
        indice_coppia_array--;

        printf("tolta la coppia minore:\n");
        for(int i=0; i<indice_coppia_array;i++){
            printf("i: %d --> (%d,%d)\n",i,array_coppie[i].primo,array_coppie[i].secondo);
        }

        array_ordinato_coppie[numero_coppie_ordinate] = min_coppia;
        numero_coppie_ordinate++;
    }

    //printf("(%d,%d)\n",min_coppia.primo, min_coppia.secondo);

    printf("ARRAY DI COPPIE ORDINATE:\n");
    for(int i=0; i<numero_coppie_ordinate;i++){
        printf("i: %d, (%d,%d)\n",i,array_ordinato_coppie[i].primo,array_ordinato_coppie[i].secondo);
    }
    
    free(array_coppie);
    free(array_ordinato_coppie);
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