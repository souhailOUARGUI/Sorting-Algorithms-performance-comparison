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

int *copy_list(int *list, int size)
{
    int *new_list = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        new_list[i] = list[i];
    }
    return new_list;
}



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
    int c;
    int *newlist = copy_list(list, size);
    for (int i = size - 1; i > 1; i--)
    {

        for (int j = 0; j < i; j++)
        {

            if (newlist[j] > newlist[j + 1])
            {
                c = newlist[j];
                newlist[j] = newlist[j + 1];
                newlist[j + 1] = c;
            }
        }
    }
    return newlist;
}

int *Tri_Selection(int *list, int size)
{
    int *newlist = copy_list(list, size);
    int min_index, tmp;
    for (int i = 0; i < size - 2; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (newlist[min_index] > newlist[j])
                min_index = j;
        }
        tmp = newlist[i];
        newlist[i] = newlist[min_index];
        newlist[min_index] = tmp;
    }
    return newlist;
}

int *Tri_Insertion(int *list, int size)
{
    int *temp = copy_list(list, size);
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

void merge(int *arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int *left_tmp = (int *)malloc(n1 * sizeof(int));
    int *right_tmp = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        left_tmp[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right_tmp[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (left_tmp[i] <= right_tmp[j])
        {
            arr[k] = left_tmp[i];
            i++;
        }
        else
        {
            arr[k] = right_tmp[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_tmp[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_tmp[j];
        j++;
        k++;
    }

    free(left_tmp);
    free(right_tmp);
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int *Tri_fusion(int *list, int size)
{
    int *new_list = copy_list(list, size);
    merge_sort(new_list, 0, size - 1);
    return new_list;
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j <= right - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        int partition_index = i + 1;

        quick_sort(arr, left, partition_index - 1);
        quick_sort(arr, partition_index + 1, right);
    }
}

int *Tri_rapide(int *list, int size)
{
    int *new_list = copy_list(list, size);
    quick_sort(new_list, 0, size - 1);
    return new_list;
}

void shell_sort(int *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int *Tri_Shell(int *list, int size)
{
    int *new_list = copy_list(list, size);
    shell_sort(new_list, size);
    return new_list;
}

int *Tri_Comptage(int *list, int size)
{
    int *newlist = copy_list(list, size);
    int max = list[0];
    for (int i = 1; i < size; i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    int listComptage[max + 1];
    for (int i = 0; i <= max; i++)
    {
        listComptage[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        listComptage[list[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (listComptage[i] > 0)
        {
            newlist[index] = i;
            index++;
            listComptage[i]--;
        }
    }
    return newlist;
}

int trouverChiffreMax(int T[], int size)
{
    int max = T[0];
    for (int i = 1; i < size; i++)
    {
        if (T[i] > max)
        {
            max = T[i];
        }
    }
    return max;
}

int *Tri_Base(int *list, int size)
{
    int *new_list = copy_list(list, size);
    int max = trouverChiffreMax(new_list, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int sortie[size];
        int compteur[10] = {0};

        for (int i = 0; i < size; i++)
        {
            compteur[(list[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            compteur[i] += compteur[i - 1];
        }

        for (int i = size - 1; i >= 0; i--)
        {
            sortie[compteur[(list[i] / exp) % 10] - 1] = new_list[i];
            compteur[(list[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
        {
            new_list[i] = sortie[i];
        }
    }
    return new_list;
}

// end of sorts algos

/////////////////////////////////////////////////////////////

// void reduceSpread(double mat[][3], int funcs_num, int iterations)
// {
//     for (int i = 0; i < funcs_num; i++)
//     {
//         for (int j = 1; j < iterations - 2; j++)
//         {
//             mat[j][i] = (mat[j + 1][i] + mat[j][i] + mat[j - 1][i]) / 3;
//             printf("%lf\n", mat[j][i]);
//         }
//     }
// }

void movingAverage(double mat[][8], int iterations, int funcs_num, int windowSize)
{
    for (int j = 0; j < funcs_num; j++)
    {
        for (int i = windowSize; i < iterations; i++)
        {
            double sum = 0.0;
            for (int k = i - windowSize; k <= i; k++)
            {
                sum += mat[k][j];
            }
            mat[i][j] = sum / (double)windowSize;
        }
    }
}

void printMatrix(double mat[][3], int funcs_num, int iterations)
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
    int *(*funcs[])(int *, int) = {Tri_bulle, Tri_Insertion, Tri_Selection, Tri_fusion, Tri_rapide, Tri_Shell, Tri_Comptage, Tri_Base};
    int funcs_num = 8;
    int windowSize = 3;
    double mat[iterations][funcs_num];
    FILE *f = fopen("dataa.txt", "w");
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
        fclose(f);

        // Appliquer la moyenne mobile aux données
        movingAverage(mat, iterations, funcs_num, windowSize);

        // Ouvrir un nouveau fichier pour écrire les données lissées
        f = fopen("data.txt", "w");
        if (f != NULL)
        {
            for (int i = 0; i < iterations; i++)
            {
                fprintf(f, "%d\t", i + 1);
                for (int j = 0; j < funcs_num; j++)
                {
                    fprintf(f, "%f\t", mat[i][j]);
                }
                fprintf(f, "\n");
            }
            fclose(f);
        }
    }
}


