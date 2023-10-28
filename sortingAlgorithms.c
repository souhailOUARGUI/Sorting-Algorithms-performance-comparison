#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Functions/Proj.h"

///////////////////////////////////////////////////     machine time calculating function ///
long double time_elapsed(void *f(int[], int), int T[])
{

    clock_t start, end;

    start = clock();
    f(T, 10);
    end = clock();

    return ((long double)(end - start) / CLOCKS_PER_SEC);
}

/////////////////////////////////////////////////   Sorting Algorithms   ///
// void selection(int T[], int n)
// {
//     printf("selection start");
//     int i, j, min, aux;
//     for (i = 0; i < n - 1; i++)
//     {
//         min = i;
//         for (j = i; j < n; j++)
//             if (T[j] < T[min])
//                 min = j;
//         aux = T[i];
//         T[i] = T[min];
//         T[min] = aux;
//     }
//     printf("selection end");
// }

// void insertion(int T[], int n)
// {
//     int i, j, aux;
//     for (i = 1; i < n; i++)
//     {
//         aux = T[i];
//         for (j = i; j > 0 && aux < T[j - 1]; j--)
//             T[j] = T[j - 1];
//         T[j] = aux;
//     }
// }

// void bubble(int T[], int n)
// {
//     int i, j, aux;
//     for (i = 0; i < n - 1; i++)
//         for (j = n - 1; j > i; j--)
//             if (T[j] < T[j - 1])
//             {
//                 aux = T[j];
//                 T[j] = T[j - 1];
//                 T[j - 1] = aux;
//             }
// }

// void shell(int T[], int n)
// {
//     int i, j, aux, h;
//     for (h = 1; h < n; h = 3 * h + 1)
//         ;
//     while (h > 1)
//     {
//         h /= 3;
//         for (i = h; i < n; i++)
//         {
//             aux = T[i];
//             for (j = i; j >= h && aux < T[j - h]; j -= h)
//                 T[j] = T[j - h];
//             T[j] = aux;
//         }
//     }
// }
// // void merge(int T[], int n)
// // {

// // }

// void quick(int T[], int n)
// {
//     printf("quick start");
//     int i, j, x, aux;
//     i = 0;
//     j = n - 1;
//     x = T[(i + j) / 2];
//     do
//     {
//         while (T[i] < x)
//             i++;
//         while (T[j] > x)
//             j--;
//         if (i <= j)
//         {
//             aux = T[i];
//             T[i] = T[j];
//             T[j] = aux;
//             i++;
//             j--;
//         }
//     } while (i <= j);
//     if (j > 0)
//         quick(T, j + 1);
//     if (n > i)
//         quick(T + i, n - i);
//     printf("quick end");
// }

int main()
{
    // long double t;
    // int T[10] = {2, 7, 3, 9, 1, 4, 6, 8, 0, 5};
    int *list = GenerateRandomList(20000);
    int size = 20000;
    EclapesedTime(Tri_bulle, list, size);
    EclapesedTime(Tri_Insertion, list, size);
    EclapesedTime(Tri_Selection, list, size);
    // printf("original list : ");
    // print_list(list, size);
    return 0;
}