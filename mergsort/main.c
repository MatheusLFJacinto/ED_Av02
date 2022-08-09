#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "module.h"

//Principal
int main(void) 
{
    bool sinal = true;
    
    int vetor[]={9,8,10,15,21,4,5,87,3,123,2};
    int tamanho = sizeof(vetor)/sizeof(int);
    

    if (sinal == true) 
    {
        printf("Vetor atual... \n");
        printArry(vetor, tamanho, sinal);
    }

	mergesort(vetor, 0, tamanho-1);

    if (sinal == true) 
    {
        printf("Vetor ordenado... \n");
        printArry(vetor, tamanho, sinal);
    }
    
	return 0;
}

