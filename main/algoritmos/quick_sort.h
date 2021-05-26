
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void swapQuickSort(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            swapQuickSort(&array[i], &array[j]);
        }
    }

    swapQuickSort(&array[i + 1], &array[high]);

    return (i + 1);
}

int quickSort(int array[], int low, int high)
{

    if (low < high)
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
    /*
*/
    return 1;
}

void doQuickSort(int array[], int low, int high)
{
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    quickSort(array, low, high);
    gettimeofday(&stop, NULL);
    printf(" QUICK SORT...................%lu µs\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    FILE *fp;
    int i;

    fp = fopen("/home/jntsfrts/Faculdade/APSDP/software/aps-sort/main/algoritmos/resultado_quick_sort.txt", "w");

    for (i = 0; i < 5000; i++)
    {
        fprintf(fp, "%d\n", array[i]);
    }

    fclose(fp);
}