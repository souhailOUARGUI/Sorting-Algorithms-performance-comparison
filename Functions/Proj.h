#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *GenerateRandomList(int size)
{
    srand((unsigned int)time(NULL));
    int *list = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % 5000;
    }
    return list;
}

void print_list(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int *copie_liste(int *list, int size)
{
    // initialiser une liste copie
    int *list_copie = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {                            // parcour la liste
        list_copie[i] = list[i]; // copie les elements
    }
    return list_copie; // retourne la liste copie
}

int *EclapesedTime(int *func(int *, int), int *list, int size)
{
    clock_t start, end;
    start = clock();
    int *p = func(list, size);
    end = clock();
    printf("EclapesedTime : %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    // print_list(p, size);
    // printf("sorted list********************************************************** \n");
    return p;
}

int *Tri_bulle(int *list, int size)
{
    int *temp = copie_liste(list, size); // copie la liste
    int c;
    for (int i = size - 1; i > 1; i--)
    {

        for (int j = 0; j < i; j++)
        {

            if (temp[j] > temp[j + 1])
            {
                c = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = c;
            }
        }
    }
    return temp;
}

int *Tri_Selection(int *list, int size)
{
    int *temp = copie_liste(list, size); // copie la liste
    int min_index, tmp;
    for (int i = 0; i < size - 2; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (temp[min_index] > temp[j])
                min_index = j;
        }
        tmp = temp[i];
        temp[i] = temp[min_index];
        temp[min_index] = tmp;
    }
    return temp;
}

int *Tri_Insertion(int *list, int size)
{
    int *temp = copie_liste(list, size); // copie la liste
    int tmp, j;
    for (int i = 1; i < size; i++)
    {
        tmp = temp[i];
        j = i - 1;
        while (j >= 0 && temp[j] > tmp)
        {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = tmp;
    }
    return temp;
}

// int *Tri_fusion(int *list, int size){

// }

// int *Tri_rapide(int *list, int size)
// {
//    
// }