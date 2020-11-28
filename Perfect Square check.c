/*
Input: T numbers
Output: 'yes' or 'no'
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int T, n;
    double root, diff;
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));

    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            fscanf(fptr, "%d", &n);

            root = sqrt(n);
            diff = root - (int)root;
            //printf("%lf\n", diff);
            if(diff != 0.0)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
    else
        printf("T out of bound\n");

    return 0;
}
