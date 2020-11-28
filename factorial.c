/*
    Input: T numbers where 0 <= n <= 15
    Output:
    factorial(n)
*/

#include <stdio.h>

int up = 15;
int low = 0;

long long int factorial(int n)
{
    if(n >= low && n <= up)
    {
        long long int result = 1;
        for(int i = 1; i <= n; i++)
            result *= i;

        return result;
    }

    return -1;
}

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T, n;
    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            fscanf(fptr, "%d", &n);
            printf("%d! = %lld\n",n, factorial(n));
        }
        //printed list is unsorted
        printf("\n");
    }

    return 0;
}


