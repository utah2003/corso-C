#define _GNU_SOURCE_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int eta = 23;
    eta = 24;

    int altezza;
    altezza = 175;

    int peso, soldi;
    peso = 60;
    soldi=1700;
    printf("la mia eta è:%d e la mia altezza è:%d\n",eta,altezza);
    printf("peso:%d e ho %d euro\n",peso,soldi);

    float resto = 2.56;
    bool pagamentoBuonFine = true;
    printf("il resto è di: %f, pagamento andato a buon fine?:%b\n",resto,pagamentoBuonFine);

    //PUNTATORI
    //array di interi

    int *a;
    int grandezzaArray = 10; //quanti indici nell array
    a = malloc(grandezzaArray*sizeof(int));
    if(a == NULL){
        printf("malloc fallito");
        exit(1);
    }
    a[0] = 10;
    a[1] = 20;
    a[2] = 11;
    for(int i=0;i<grandezzaArray;i++){
        printf("indice: %d --> %d\n",i,a[i]);
    }
    free(a);
    a=NULL;
    return 0;
}