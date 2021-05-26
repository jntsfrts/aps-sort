#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "string.h"
#define LEN 256

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);

        heapify(array, i, 0);
    }

    gettimeofday(&stop, NULL);
    printf(" HEAP SORT....................%lu µs\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    FILE *fp;

    fp = fopen("/home/jntsfrts/Faculdade/APSDP/software/aps-sort/main/algoritmos/resultado_heap_sort.txt", "w");

    for (int i = 0; i < 5000; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }
    fclose(fp);
    //free(fpToHeap);
}
