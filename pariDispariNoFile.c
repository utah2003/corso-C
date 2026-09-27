#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc > 10){
         puts("troppi numeri inseriti");
        exit(1);
   }
    int parametri = argc;
    int grandezzaPari = 2;
    int grandezzaDispari = 2;
    int inseritiP = 0;
    int inseritiD = 0;
    int *pari, *dispari;

    pari = malloc(grandezzaPari*sizeof(int));
    dispari = malloc(grandezzaDispari*sizeof(int));

    for (int i=1;i<parametri;i++){
        if(atoi(argv[i])%2==0){
            if(inseritiP==grandezzaPari){
                int *tempP=realloc(pari,(grandezzaPari+2)*sizeof(int));
                if(!tempP){
                    free(pari);
                    free(dispari);
                    return 1;
                }
                pari = tempP;
            }
            pari[inseritiP]=atoi(argv[i]);
            inseritiP += 1;
        }else{
            if(inseritiD==grandezzaDispari){
                int *tempD=realloc(dispari,(grandezzaDispari+2)*sizeof(int));
                if(!tempD){
                    free(pari);
                    free(dispari);
                    return 1;
                }
                dispari = tempD;
             }
           dispari[inseritiD]=atoi(argv[i]);
           inseritiD += 1;
         }
    }
    puts("numeri pari inseriti");
    for(int i=0;i<inseritiP;i++){
        printf("%d\n",pari[i]);
    }
    puts("numeri dispari inseriti");
    for(int i=0;i<inseritiD;i++){
        printf("%d\n",dispari[i]);
    }

    free(pari);
    free(dispari);
    return 0;
}


