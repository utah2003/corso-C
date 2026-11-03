#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


void termina(char *messaggio);

char *maiuscola(char *s);


int main(int argc, char *argv[])
{
    //if(argc != 2)termina("inserire un solo nome");

    for(int i=1; i<argc; i++){
        char *to_upper = malloc(strlen(maiuscola(argv[i])) * sizeof(char));
        if(to_upper == NULL)termina("malloc fallito to_upper");

        to_upper = maiuscola(argv[i]);
        printf("%s\n",to_upper);

        free(to_upper);
    }
    
    return 1;
}


char *maiuscola(char *s)
{
    char *prova =malloc(1 * sizeof(char));
    int lunghezza_stringa = 0;

    for(int i=0; i<strlen(s); i++){

        lunghezza_stringa += 1;

        char *temp = realloc(prova,(lunghezza_stringa+1) * sizeof(char));
        if(temp == NULL)termina("realloc fallita");
        prova = temp;

        char *carattere = malloc(2 * sizeof(char));
        if(carattere == NULL)termina("malloc fallito");

        carattere[0] = toupper(s[i]);
        carattere[1] = '\0';

        strcat(prova,carattere);

        free(carattere);
    }
    return prova;
}


void termina(char *messaggio)
{
    puts(messaggio);
    exit(1);
}
