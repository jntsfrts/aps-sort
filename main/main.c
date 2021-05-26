#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "./algoritmos/insertion_sort.h"
#include "./algoritmos/heap_sort.h"
#include "./algoritmos/quick_sort.h"

int qtdeItens = 5000;

int *copiaArray(int *arrayOriginal)
{
    int *arrayCopia = malloc(sizeof(int) * qtdeItens);

    for (int i = 0; i < qtdeItens; i++)
        arrayCopia[i] = arrayOriginal[i];

    return arrayCopia;
}

int main()
{
    loading();
    assinatura();
    loading();
    //Solicitando os parâmetros para o usuário
    int tipoInput = solicitarParametros();
    loading();

    // Lendo o arquivo com os dados de entrada.
    int *arrayX = malloc(sizeof(int) * qtdeItens);
    arrayX = getDados(tipoInput);

    int array[qtdeItens];

    for (int p = 0; p < qtdeItens; p++)
        array[p] = arrayX[p];

    // Ordenando os dados usando os 3 algorítmos
    int size = sizeof(array) / sizeof(array[0]);

    // Apresentando resultados
    printf("\n+-------------------------------------+\n");
    printf("|       Algoritmo        |  Tempo(µs) |\n");
    printf("+------------------------+------------+\n");

    // Chamando Quick Sort
    int *arrayQuick = malloc(sizeof(int) * qtdeItens);
    arrayQuick = copiaArray(array);
    doQuickSort(arrayQuick, 0, size - 1);

    // Chamando Insertion Sort
    int *arrayInsertion = malloc(sizeof(int) * qtdeItens);
    arrayInsertion = copiaArray(array);
    insertionSort(arrayInsertion, size);

    // Chamando Heap Sort
    int *arrayHeap = malloc(sizeof(int) * qtdeItens);
    arrayHeap = copiaArray(array);
    heapSort(arrayHeap, size);
    free(arrayHeap);
    return 1;
}
