#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void termina(const char *error)
{
    perror(error);
    exit(1);
}

int confrontas(const char *s, const char *q);

int main(int argc, char *argv[])
{
    if(argc < 2)termina("devi inserire almeno due stringhe");

    int ris = 10;

    char *parola = malloc((strlen(argv[1])+1) * sizeof(char));
    if(parola == NULL)termina("malloc fallito");

    parola = strcpy(parola,argv[1]);
    //printf("%s\n",parola);

    for(int i=2; i<argc; i++){
        
        ris = confrontas(parola,argv[i]);

        if(ris == 1){
            char *temp = realloc(parola,(strlen(argv[i])+1) * sizeof(char));
            if(temp == NULL)termina("realloc fallito");

            parola = temp;
            parola = strcpy(parola,argv[i]);
        }
        
    }

    printf("%s\n",parola);

    free(parola);
    return ris;
}

int confrontas(const char *s, const char *q)
{
    assert(s != NULL);
    assert(q != NULL);

    if(strlen(s) == strlen(q)){
        for(int i=0; i<strlen(s); i++){
            if(s[i] > q[i])return 1;
            if(s[i] < q[i])return -1;
        }
        return 0;
    }
    if(strlen(s) < strlen(q)){
        for(int i=0; i<strlen(s); i++){
            if(s[i] > q[i])return 1;
            if(s[i] < q[i])return -1;
        }
        return -1;
    }
    if(strlen(s) > strlen(q)){
        for(int i=0; i<strlen(q); i++){
            if(s[i] > q[i])return 1;
            if(s[i] < q[i])return -1;
        }
        return 1;
    }

    exit(10);
}