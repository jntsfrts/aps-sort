#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "string.h"
#define INTERVAL (0.1 * CLOCKS_PER_SEC)

int itens = 5000;

void assinatura()
{
    printf("\n");
    printf("\n");
    printf("    |     '||''|.   .|'''.|  '     .|'''.|   ..|''||   '||''|.   |''||''|\n");
    printf("   |||     ||   ||  ||..  '        ||..  '  .|'    ||   ||   ||     ||   \n");
    printf("  |  ||    ||...|'   ''|||.   ||||  ''|||.  ||      ||  ||''|'      ||   \n");
    printf(" .''''|.   ||      .     '||   .        '|| '|.     ||  ||   |.     ||   \n");
    printf(".|.  .||. .||.     |'....|'       |'....|'   ''|...|'  .||.  '|'   .||.  \n");
    printf("\n");
    printf("\n");
}

void loading()
{
    int i = 0;
    clock_t target;
    char spin[] = "\\|/-";
    printf(" ");
    for (int x = 1; x < 30; x++)
    {
        printf("\b%c", spin[i]);
        fflush(stdout);
        i = (i + 1) % 4;
        target = clock() + (clock_t)INTERVAL;
        while (clock() < target)
            ;
    }
}

int solicitarParametros()
{
    int tipoInput;

    printf("\nDeseja ordenar dados aleatórios(1), dados descrescentes(2), ou semi-ordenados(3) ? ");
    scanf("%d", &tipoInput);

    return tipoInput;
}

char *getArquivoBy(int tipo)
{
    char *fileNamePath;

    if (tipo == 1)
    {
        fileNamePath = "./dados_entrada/random_data.txt";
        printf("\n+-------------------------------------+\n");
        printf("|           DADOS ALEATÓRIOS          |\n");
        printf("+-------------------------------------+");
    }

    if (tipo == 2)
    {
        fileNamePath = "./dados_entrada/reversed_data.txt";
        printf("\n+-------------------------------------+\n");
        printf("|            DADOS REVERSOS           |\n");
        printf("+-------------------------------------+");
    }

    if (tipo == 3)
    {
        fileNamePath = "./dados_entrada/nearly_sorted_data.txt";
        printf("\n+-------------------------------------+\n");
        printf("|         DADOS SEMI-ORDENADOS        |\n");
        printf("+-------------------------------------+");
    }

    return fileNamePath;
}

int *getDados(int tipoInput)
{
    FILE *arquivo;

    char *filename = getArquivoBy(tipoInput);

    arquivo = fopen(filename, "r");

    int i = 0;
    int *arrx = (int *)malloc(sizeof(int) * itens);
    char line[itens];

    while (fgets(line, sizeof line, arquivo) != NULL)
    {
        arrx[i] = atoi(strdup(line));
        i++;
    }

    fclose(arquivo);

    return arrx;
}
