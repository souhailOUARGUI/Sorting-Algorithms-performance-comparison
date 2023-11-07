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
        fprintf(f, "plot 'data.txt' using 1:2 with lines title 'Bubble Sort','data.txt' using 1:3 with lines title 'insertion Sort' ,'data.txt' using 1:4 with lines title 'Selection Sort','data.txt' using 1:5 with lines title 'Fusion Sort','data.txt' using 1:6 with lines title 'Fast Sort','data.txt' using 1:7 with lines title 'Shell Sort','data.txt' using 1:8 with lines title 'Counting Sort','data.txt' using 1:9 with lines title 'Base Sort' ");
        fclose(f);
        sprintf(com, "start %s -persist %s", gnu_path, executer);
        system(com);
    }
    else
    {
        printf("Error opening file\n");
    }
}



