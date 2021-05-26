#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int insertionSort(int array[], int size)
{
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }

    gettimeofday(&stop, NULL);
    printf(" INSERTION SORT...............%lu µs\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    FILE *fp;
    int i;

    fp = fopen("/home/jntsfrts/Faculdade/APSDP/software/aps-sort/main/algoritmos/resultado_insertion_sort.txt", "w");

    for (i = 0; i < 5000; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }

    fclose(fp);

    return 1;
}
