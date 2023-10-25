#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

///////////////////////////////////////////////////     machine time calculating function ///
double time_elapsed(void *f(int), int T[])
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    f(T);
    end = clock();
    return 0;
}

/////////////////////////////////////////////////   Sorting Algorithms   ///
void selection(int T[], int n)
{
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i; j < n; j++)
            if (T[j] < T[min])
                min = j;
        aux = T[i];
        T[i] = T[min];
        T[min] = aux;
    }
}

void insertion(int T[], int n)
{
    int i, j, aux;
    for (i = 1; i < n; i++)
    {
        aux = T[i];
        for (j = i; j > 0 && aux < T[j - 1]; j--)
            T[j] = T[j - 1];
        T[j] = aux;
    }
}

void bubble(int T[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
            if (T[j] < T[j - 1])
            {
                aux = T[j];
                T[j] = T[j - 1];
                T[j - 1] = aux;
            }
}

void shell(int T[], int n)
{
    int i, j, aux, h;
    for (h = 1; h < n; h = 3 * h + 1)
        ;
    while (h > 1)
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            aux = T[i];
            for (j = i; j >= h && aux < T[j - h]; j -= h)
                T[j] = T[j - h];
            T[j] = aux;
        }
    }
}
// void merge(int T[], int n)
// {
// }

int main()
{
    int T[10] = {2, 7, 3, 9, 1, 4, 6, 8, 0, 5};
    bubble(T, 10);

    printf("normal array is: \n ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", T[i]);
    }

    printf("Sorted array is: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", T[i]);
    }

    return 0;
}