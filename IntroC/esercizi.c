#define _GNU_SOURCE_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    int *a, *b, n;
    int valido;

    printf("inserisci un numero intero: \n ");
    valido = scanf("%d",&n);
    if(valido != 1){
       puts("Devi inserire un intero");
       exit(1);
    }

    int capacitaA=2, capacitaB=2;
    int dimensioneA=0,dimensioneB=0;

    a = malloc(capacitaA*sizeof(int));
    b = malloc(capacitaB*sizeof(int));

    for(int i=3;i<n;i++){
        if(i%3==0 && i%5!=0){
            if(dimensioneA==capacitaA){
                capacitaA += 2;
                int *tempA = realloc(a,capacitaA*sizeof(int));
                //VERIFICA SE LA REALLOCAZIONE È ANDATA A BUON FINE
                if(tempA == NULL){
                    puts("Errore di riallocazione!");
                    free(a);
                    free(b);
                    exit(2);
                }
                a=tempA;
            }
            a[dimensioneA] = i;
            dimensioneA++;
        }
        if(i%3!=0 && i%5==0){
            if(dimensioneB==capacitaB){
                capacitaB += 2;
                int *tempB = realloc(b,capacitaB*sizeof(int));
                //VERIFICA SE LA REALLOCAZIONE È ANDATA A BUON FINE
                if(tempB == NULL){
                    puts("Errore di riallocazione!");
                    free(a);
                    free(b);
                    exit(2);
                }
                b=tempB;
            }
            b[dimensioneB] = i;
            dimensioneB++;
        }

    }
    for(int i=0;i<dimensioneA;i++){
       // printf("%d",a[i]);
    }
    printf("lunghezza di a = %d\n",capacitaA);
    printf("lunghezza di b = %d\n", capacitaB);

    free(a);
    free(b);
    return 0;
}