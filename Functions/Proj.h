#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *GenerateRandomList(int size)
{
    srand((unsigned int)time(NULL));
    int *list = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % 15000;
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

// int *EclapesedTime(int *func(int *, int), int *list, int size)
// {
//     clock_t start, end;
//     start = clock();
//     int *p = func(list, size);
//     end = clock();
//     printf("EclapesedTime : %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
//     // print_list(p, size);
//     // printf("sorted list********************************************************** \n");
//     return p;
// }


double EclapesedTime(int *func(int *, int), int *list, int size)
{
    clock_t start, end;
    // Result result;

    start = clock();
    func(list, size);
    end = clock();
    // result.duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    return ((double)(end - start)) / CLOCKS_PER_SEC;
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


int *shellSort(int *list, int n) 
{ 
    int *arr = copie_liste(list, n); // copie la liste
    
    for (int gap = n/2; gap > 0; gap /= 2) 
    {
       
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return arr;
} 




/////////////////////////////////////////////////////////////

void reduceSpread(double mat[][3], int funcs_num, int iterations)
{
    for (int i = 0; i < funcs_num; i++)
    {
        for (int j = 1; j < iterations - 2; j++)
        {
            mat[j][i] = (mat[j + 1][i] + mat[j][i] + mat[j - 1][i]) / 3;
            printf("%lf\n", mat[j][i]);
        }
    }
}

void prin(double mat[][3], int funcs_num, int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < funcs_num; j++)
        {
            printf("%lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

void calculate_print()
{
    int *p;
    int list_size = 1000;
    int iterations = 40;
    int *(*funcs[])(int *, int) = {Tri_bulle, Tri_Insertion, Tri_Selection};
    int funcs_num = 3;
    // Result *result = (Result *) calloc(2, sizeof(Result));
    double mat[iterations][funcs_num];
    FILE *f = fopen("data.txt", "w");
    if (f != NULL)
    {
        for (int i = 0; i < iterations; i++)
        {
            fprintf(f, "%d\t", i + 1);
            p = GenerateRandomList(list_size);
            for (int j = 0; j < funcs_num; j++)
            {
                mat[i][j] = EclapesedTime(funcs[j], p, list_size);
                fprintf(f, "%f\t", mat[i][j]);
            }
            fprintf(f, "\n");
            list_size = list_size + 1000;
        }
    }
    // for (int i = 0; i < funcs_num; i++)
    // {
    //     for (int j = 0; j < iterations; j++)
    //     {
    //         mat[j][i] = (mat[j + 1][i] + mat[j][i] + mat[j - 1][i]) / 3;
    //         printf("%lf\n", mat[j][i]);
    //     }
    // }
    //

    prin(mat, funcs_num, iterations);
}
