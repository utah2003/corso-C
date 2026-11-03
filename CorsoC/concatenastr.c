#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{
    if(argc <= 2){
        puts("devi inserire almeno due parole!");
        return 1;
    }

    char messaggio[] = "";

    int lunghezza_messaggio = 0;

    for (int j=1; j < argc; j++){
        strcat(messaggio, argv[j]);
        lunghezza_messaggio += strlen(argv[j]);
    }

    printf("la lunghezza della stringa è %d e la stringa è: %s\n",lunghezza_messaggio, messaggio);

    char *messaggio1 = malloc( 1 * sizeof(char));
    if(messaggio1==NULL){
        puts("Malloc Fallito!");
        return 1;
    }

    messaggio[0] = '\0';

    int lunghezza_messaggio1 = 0;

    for(int i=1; i<argc; i++){

        lunghezza_messaggio1 += strlen(argv[i]);
        char *temp = realloc(messaggio1, (lunghezza_messaggio1+1) * sizeof(char));
        if(temp == NULL){
            puts("Malloc di temp Fallito!");
            return 1;
        }
        messaggio1 = temp;
        strcat(messaggio1, argv[i]);
    }
    printf("la lunghezza della stringa è %d e la stringa è: %s\n",lunghezza_messaggio1, messaggio1);

    free(messaggio1);
    messaggio1 = NULL;


    return 0;
}