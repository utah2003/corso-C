#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void termina(const char *error)
{
    perror(error);
    exit(1);
}

int main(int argc, char *argv[])
{

    if(argc <= 2) termina("Devi inserire almeno due parole");

    char *messaggio = malloc (1 * sizeof(char));

    if(messaggio == NULL) termina("Malloc fallito");

    int lunghezza_totale = 0;

    for(int i=1; i<argc; i++){
        lunghezza_totale += strlen(argv[i]);

        char *temp = realloc(messaggio, (lunghezza_totale+1) * sizeof(char));
        if(temp == NULL) termina("Malloc temp fallito");

        messaggio = temp;
        strcat(messaggio,argv[i]);

    }

    printf("La lunghezza della stringa concatenata è %d, la stringa è:\n %s\n",lunghezza_totale,messaggio);

    free(messaggio);
    messaggio = NULL;

    return 0;
}
