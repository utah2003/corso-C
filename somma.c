//In C una variabile è una scatola con un nome e un tipo ben definito.
//int memorizza numeri interi (es. 5, -12).
//Gli operatori matematici base sono +, -, *, / e % (resto della divisione
//intera).
//In printf, il segnaposto %d viene sostituito con il valore dell'intero indicato
// dopo la virgola.


#define _GNU_SOURCE_ // # --> DIRETTIVA
#include <stdio.h> //std --> standard-output-input; .h --> tipo di file
#include <stdlib.h>

int main()
{
    //SOMMA TRA INTERI DA TERMINAE
	int a, b;
	
	printf("inserisci il primo numero della somma:");
	if(a%2!=0 && a%2!=1){
	    printf("numero non intero");
	    exit(1);
	}
	scanf("%d", &a);
	printf("inserisci il secondo:");
	scanf("%d", &b);
	
    int risultato = a + b;
	printf("la somma tra %d e %d è %d\n",a,b,risultato);

	//PRODOTTO TRA INTERI PRESI DA TERMINALE
	return 0;
}
