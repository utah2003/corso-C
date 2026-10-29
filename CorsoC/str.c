#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void termina(const char *messaggio);

int main(int arg, char *argv[])
{
    char nome[7] = "Jacopo"; //! ---> inserisco 7 anche se il nome è composto da 6 caratteri perche per ogni stringa c'è il carattere finale "\0".

    printf("%s\n",nome);
    printf("%c\n",nome[3]);

    //nome[3] = 'h';
    //printf("%s\n",nome);

    for(int i=0; i<sizeof(nome) / sizeof(nome[0]); i++){
        printf("%c",nome[i]);
    }

    for(int i=0; i<strlen(nome); i++){
        printf("%c", nome[i]);
    }

    printf("\n");
    //?CONCATENARE DUE STRINGHE

    char benvenuto[] = "ciao, benvenuto";
    strcat(benvenuto, " ");
    printf("%s\n", strcat(benvenuto,nome));

    char addio[] = "addio, ";
    strcat(addio,nome);
    printf("%s\n", addio);

    return 0;
}

void termina(const char *messaggio)
{
    perror(messaggio);
    exit(1);
}