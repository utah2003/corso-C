#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef char **array_stringhe;

void termina(const char *messaggio)
{
    perror(messaggio);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc != 3)termina("inserire solo due nomi di file");

    FILE *infile = fopen(argv[1], "r");
    if(infile == NULL){
        fclose(infile);
        termina("Errore nella lettura del file");
    }
    FILE *outfile = fopen(argv[2], "w");
    if(outfile == NULL){
        fclose(outfile);
        termina("Errore nella scrittura del file");
    }

    array_stringhe array_parole = NULL;
    int i = 0;

    //! BUUFER PER MEMORIZZARE la parola letta
    //! 99 caratteri utili + 1 per '\0'
    //! SI USA PER VERIFICARE CHE OGNI SINGOLA PAROLA LETTA NEL FILE NON SUPERI I 100 BYTE
    char parola[100];

    while(fscanf(infile,"%99s",parola) == 1){  //! %99s dice: "leggi al massimo 99 caratteri; se la parola è più lunga, fermati e aggiungi '\0'"
        //fprintf(outfile,"%s\n", parola);
        array_stringhe temp = realloc(array_parole, (i + 1) * sizeof(char *));
        if(temp == NULL)termina("realloc fallito");

        array_parole = temp;
        array_parole[i] = strdup(parola);
        i = i+1;
    }

    for(int j=i-1; j >= 0 ; j--){
        fprintf(outfile,"%s\n",array_parole[j]);
        //printf("%d\n",array_parole[j]);
    }

    for (int j = 0; j < i; j++) { 
        free(array_parole[j]);
    }
    free(array_parole);
    fclose(infile);
    fclose(outfile);

    return 0;
}