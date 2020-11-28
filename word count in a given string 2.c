
/*
    input:
    T lines of string containing , . ! ? : ;
    output:
    print vowels and consonants separately
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    fptr = fopen("D:\\input.txt", "r");

    if(fptr == NULL)
    {
        printf("File Pointer Error!");
        exit(1);
    }

    int T, count;
    char str[10001], *temp, input[10001], output[10001];
    char delim[] = " .,!?;:";

    fscanf(fptr, "%d", &T);
    printf(" T = %d\n", T);

    if(T <= 0 || T > 100)
    {
        printf("Input Error!");
        exit(1);
    }

    for (int k = 0; k < T; k++)
    {
        count = 0;
        strcpy(output, "\0");
        fscanf(fptr, " %[^\n]", str);
        strcpy(input, str);

        temp = strtok(str, delim);
        strcat(output, temp);
//        printf("%s\n", output);
        while(temp != NULL)
        {
            //printf("%s ", temp);
            count++;
            temp = strtok(NULL, delim);
            printf("output = %s, temp = %s\n", output, temp);
            if(temp != NULL)
                strcat(output, temp);
        }
        printf("check\n");
        strcat(output, "\0");

        printf("%s -> %d\n", output, count);
    }

    return 0;
}
