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

int *somme_distinte(int a[], int n, int *size);

int main(int argc, char *argv[])
{
    return 0;
}

int *somme_distinte(int a[], int n, int *size)
{
    assert(n>0);
    assert(a != NULL);
    assert(size != NULL);
    
}
