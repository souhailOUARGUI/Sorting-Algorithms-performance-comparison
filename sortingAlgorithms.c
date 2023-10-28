#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Functions/Proj.h"

int main()
{
   
    int *list = GenerateRandomList(5000);
    int size = 5000;
    EclapesedTime(Tri_bulle, list, size);
    EclapesedTime(Tri_Insertion, list, size);
    EclapesedTime(Tri_Selection, list, size);
   
    // printf("original list : ");
    // print_list(list, size);
    return 0;
}