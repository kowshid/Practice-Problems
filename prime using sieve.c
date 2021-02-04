
/*
    input:
    T lines containing low < up
    output:
    all primes in range [a, b]
*/

#include <stdio.h>
#include <math.h>

int up = 100000;

int main()
{
    FILE *fptr;
    fptr = fopen("D:\\input.txt", "r");

    if(fptr == NULL)
    {
        printf("File Pointer Error!");
        exit(1);
    }

    int T, lo, hi, limit = sqrt(up), count;
    char str[10001], *temp, input[10001], output[10001];
    char delim[] = " .,!?;:";
    int arr[up + 1];

    fscanf(fptr, "%d", &T);

    if(T <= 0 || T > 100)
    {
        printf("Input Error!");
        exit(1);
    }

    for(int i = 2; i <= up; i++)
    {
        arr[i] = 1; //1 denoted its a prime number
    }

    for(int i = 2; i <= limit; i++)
    {
        for(int j = 2; i*j <= up; j++)
            arr[i*j] = 0;
    }

    for (int k = 0; k < T; k++)
    {
        count = 0;
        fscanf(fptr, "%d%d", &lo, &hi);
        for(int i = lo; i <= hi; i++)
        {
            if(arr[i])
            {
                count++;
                printf("%d ", i);
            }
        }
        printf("\nTotal = %d\n", count);
    }

    return 0;
}
