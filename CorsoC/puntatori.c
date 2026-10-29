#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int main()
{
    int x = 56;
    int *ptr_x = &x; //!---> VARIABILE CHE CONTIENE L INDIRIZZO DEL PUNTATORE


    printf("valore: %d\n", x);
    printf("puntatore: %p\n", ptr_x);
    printf("%d\n", *ptr_x); //! ---> PER MANDARE A SCHERMO CIO CHE CNTIENE L INDIRIZZO (CIOE 56);

    int y[4] = {20,30,40,100};

    printf("puntatore di y: %p\n", &y);
    printf("gli elementi: %d, %d, %d, %d\n",y[0],y[1],y[2],y[3]);

    return 0;
}