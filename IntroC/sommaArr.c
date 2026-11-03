#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Scopo del programma:
//  legge un intero N da tastiera
//  crea un array *dinamico* di N int
//  legge N interi mettendoli nell'array
//  calcola la somma degli elementi dell'array
//  stampa la somma

int main(int argc, char *argv[])
{
    int *arr;
    int n;
    int valid;

    printf("inserisci quanti indici deve avere l'array:\n");
    valid = scanf("&d",&n);
    if(valid != 1){
        puts("valore non trovato!");
        exit(0);
    }
    if(n <= 0){
        puts("il numero di indici deve essere positivo");
        exit(1);
    }

    arr = malloc(n*sizeof(int));
    if(arr == NULL){
        puts("malloc fallito!");
        exit(2);
    }
    
    return 0;
}
