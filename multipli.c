#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void termina(const char *messaggio)
{
    perror(messaggio);
    exit(1);
}

int main(int argc, char *argv[])
{

    if(argc < 3)termina("inserire 'nomefile.txt intero1 intero2 ...");

    FILE *file = fopen(argv[1], "r");
    if(file == NULL)termina("Errore apertura file");

    int *array_interi = NULL;
    int i = 0;

    char intero[100];
    while(fscanf(file,"%99s",intero) == 1){
        int *temp = realloc(array_interi,(i+1)*sizeof(int));
        if(temp == NULL)termina("Realloc fallito!");

        array_interi = temp;
        array_interi[i] = atoi(intero);
        i++;
    }

    printf("sono stati salvati : %d numeri dal file in input\n", i);

    for(int z=2; z < argc; z++){

        char filename[256]; //! ----->BUFFER PER IL NOME DEL FILE
        sprintf(filename, "/home/utah/Universita/Lab02/Risultati/File/interi.txt.%d",atoi(argv[z])); //! ------>NOMI DEI FILE CHE VERRANNO CREATI

        FILE *file_interi = fopen(filename, "w");
        if(file_interi == NULL)termina("Errore creazioe file");

        for(int j=0; j<i; j++){
            if(atoi(argv[z]) != 0){
                if((array_interi[j] % atoi(argv[z])) == 0){
                fprintf(file_interi,"%d\n",array_interi[j]);
                }
            }
        }
        fclose(file_interi);
    }

    free(array_interi);
    fclose(file);
    return 0;
}