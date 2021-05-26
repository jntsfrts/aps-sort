#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define LEN 256
int gerador()
{

    FILE *fp;
    int i;

    //struct timeval stop, start;
    //gettimeofday(&start, NULL);
    /* open the file for writing*/
    fp = fopen("dados.txt", "w");

    //write 10 lines of text into the file stream
    for (i = 1; i < 5000; i++)
    {
        fprintf(fp, "%d\n", i);
    }

    // srand(time(NULL));
    /*
    for (int i = 0; i < 5000; i++)
    {
        int num = rand() % 1000000;

        fprintf(fp, "%d\n", num);
    }
    */
    fclose(fp);

    // gettimeofday(&stop, NULL);
    // printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    return 0;
}