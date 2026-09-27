#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc > 10){
        puts("troppi numeri inseriti");
        exit(1);
    }
    //int  isValid;
    //int capacita = 2;
    //int grandezza = 0;

    int inseriti = argc-1;
    int numeri[9];
    //int *pari, *dispari;

    for (int i=0;i<inseriti;i++){
        numeri[i] = atoi(argv[i+1]);
    }
    for(int j=0;j<inseriti;j++){
        printf("%d\n",numeri[j]);
    }
    //free(pari);
    //free(dispari);
    return 0;
}
