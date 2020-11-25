/*
Input: T numbers of variable lenght
Output: add the RMD and LMD
*/

#include <stdio.h>

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T, n, num, RSD;
    fscanf(fptr, "%d", &T);

    for(int i = 0; i < T; i++)
    {
        fscanf(fptr, "%d", &num);
        RSD = num % 10;

        while(num >= 10)
            num /= 10;

        printf("%d\n", RSD + num);
    }

    return 0;
}
