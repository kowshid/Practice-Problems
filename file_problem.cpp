#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define N 10

int main()
{
    FILE *fin, *f_out;
    char line[20];
    int marks[3][6], idx, n;
    char files[3][20] = {"physics.txt", "math.txt", "chemistry.txt"};

    f_out = fopen("out.txt", "w");

    for(int i = 0; i < 3; i++)
    {
        for(int k = 0; k < 20; k++)
        {
            line[k] = files[i][k];
        }

        fin = fopen(line, "r");

        if(fin != NULL)
        {
            //printf("opened file %s\n", line);
            for(int k = 0; k < 5; k++)
            {
                fscanf(fin, "%d", &idx);
                fscanf(fin, "%d", &n);
                marks[i][idx] = n;
                //printf("%d %d ", idx, marks[i][idx]);
            }
            fclose(fin);
        }
        else printf("Error Opening file\n");
    }

    f_out = fopen("out.txt", "w");
    fprintf(f_out, "\nphysics, math, chem\n");
    for(int i = 0; i < 3; i++)
    {
        fprintf(f_out, "\nNumbers of %dth sub are ", i);
        for(int k = 1; k < 6; k++)
        {
            fprintf(f_out, "%d ", marks[i][k]);
        }
    }

    fclose(f_out);

    return 0;
}
