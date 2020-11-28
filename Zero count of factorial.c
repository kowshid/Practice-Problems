
//

/*
    Input: T numbers where 0 <= n <= 100
    Output:
    zero (0) at the end
*/

#include <stdio.h>
int arr[101];

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T, n, count;
    arr[0] = 0;
    for(int i = 1; i < 101; i++)
    {
        if(i % 25 == 0)
            arr[i] = 2;
        else if(i % 5 == 0)
            arr[i] = 1;
    }

    fscanf(fptr, "%d", &T);
    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            count = 0;
            fscanf(fptr, "%d", &n);
            for(int j = 0; j <= n; j++)
                count += arr[j];

            printf("%d --> %d\n", n, count);
        }
        printf("\n");
    }

    return 0;
}

