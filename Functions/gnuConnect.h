#include <stdio.h>
#include <stdlib.h>
// #include "Proj.h"



void Plotgnu()
{

    char const *executer = "./executer.txt";
    char const *gnu_path = "C:/gnuplot/bin/wgnuplot";
    char com[600];
    FILE *f = fopen(executer, "w");
    if (f != NULL)
    {
        fprintf(f, "set grid;\n");
        fprintf(f, "set multiplot;\n");
        fprintf(f, "plot 'data.txt' using 1:2 with lines title 'Bubble Sort','data.txt' using 1:3 with lines title 'insertion Sort' ,'data.txt' using 1:4 with lines title 'Selection Sort','data.txt' using 1:5 with lines title 'Fusion Sort' ");
        fclose(f);
        sprintf(com, "start %s -persist %s", gnu_path, executer);
        system(com);
    }
    else
    {
        printf("Error opening file\n");
    }
}

// int gnuConnect(){
    
//     FILE *fp = popen("gnuplot -persist", "w");
//     if (fp == NULL)
//     {
//         printf("Error opening pipe!\n");
//         return -1;
//     }
//     fprintf(fp, "plot sin(x) \n");
//     fflush(fp);
//     return 0;
// }