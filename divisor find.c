//

/*
    Input: T numbers
    Output:
    all divisors of each numbers
*/

#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T, n, limit;
    fscanf(fptr, "%d", &T);

    for(int i = 0; i < T; i++)
    {
        fscanf(fptr, "%d", &n);
        limit = sqrt(n) + 1; //searching till sqrt of any number as divisors come in pairs
        //printf("%d ", limit);
        printf("Case %d:", i + 1);
        for(int j = 1; j <= limit; j++)
        {
            if(n % j == 0)
            {
                if(n/j != j) //not a perfect square
                    printf(" %d %d", j, n/j);
                else
                    printf(" %d", j);
            }
        }
        //printed list is unsorted
        printf("\n");
    }

    return 0;
}
