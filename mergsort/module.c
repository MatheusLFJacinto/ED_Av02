#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "module.h"

//função MergSort
void mergesort(int vetor[], int inicio, int tamanho) 
{
	if (inicio < tamanho)
	{
        //Calculo do meio do vetor
		int meio = inicio + (tamanho - inicio) / 2;

        //Quebra o vetor ao meio
		mergesort(vetor, inicio, meio);
		mergesort(vetor, meio + 1,tamanho);
        
        //Mescla o vetor dividido
		intercala(vetor, inicio, meio, tamanho);
	}
}

//função Intercalação, divide o vetor original em 2, ordena e por tamanho mescla 
void intercala(int vetor[], int inicio, int meio, int tamanho)
{
    int indice_esquerda, indice_direita, indice_novoarry;
    //valores a esquerda da metade do vetor
    int vetor1 = meio - inicio + 1;

    //valores a direita da metade do vetor  
    int vetor2 = tamanho - meio;  

    //Arrys temporario para dividir o vetor em dois
    int esquerda[vetor1], direita[vetor2];

    //Armazena no vetor auxiliar os valores da esquerda ao meio do vetor    
    for (indice_esquerda = 0; indice_esquerda < vetor1; indice_esquerda++)
        esquerda[indice_esquerda] =  vetor[inicio + indice_esquerda];

    //Armazena no vetor auxiliar os valores do meio a direita do vetor  
    for (indice_direita = 0; indice_direita < vetor2; indice_direita++)
        direita[indice_direita] = vetor[meio + 1 + indice_direita];

    //Inicializa para os subarrys
    indice_esquerda = 0;
    indice_direita = 0;
    indice_novoarry = inicio;

    //Mescla os o vetor a esquerda com o a direita
    while (indice_esquerda < vetor1 && indice_direita < vetor2)
    {
        if (esquerda[indice_esquerda] <= direita[indice_direita])
        {
            vetor[indice_novoarry] = esquerda[indice_esquerda];
            indice_esquerda++;
        }
        else
        {
            vetor[indice_novoarry] = direita[indice_direita];
            indice_direita++;
        }
        indice_novoarry++;
    }

    //Adiciona elementos remanecentes a esquerda
    while (indice_esquerda < vetor1)
    {
        vetor[indice_novoarry] = esquerda[indice_esquerda];
        indice_esquerda ++;
        indice_novoarry ++;
    }

    //Adiciona elementos remanecentes a direita
    while (indice_direita < vetor2)
    {
        vetor[indice_novoarry] = direita[indice_direita];
        indice_direita ++;
        indice_novoarry ++;
    }
}

//Printa o vetor
void printArry(int vetor[], int tamanho, bool sinal)
{
    bool terminalprint = sinal; //printa no terminal
    if (terminalprint == true)
    {
        for (int i = 0; i < tamanho; i++)
        {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
    
FILE *file = fopen("saida.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o aquivo!\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++)
    {
        {
            if (i == tamanho-1)
                fprintf(file,"%d", vetor[i]);
            else
                fprintf(file,"%d,", vetor[i]);
        }
    }
    fclose(file);
}








