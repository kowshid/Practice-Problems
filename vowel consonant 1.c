/*
    input:
    T lines of string
    output:
    print vowels and consonants separately
*/

#include <stdio.h>
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

    int T;
    char str[10001];

    fscanf(fptr, "%d", &T);
    printf(" T = %d\n", T);

    if(T <= 0 || T > 100)
    {
        printf("Input Error!");
        exit(1);
    }

    for (int k = 0; k < T; k++)
    {
        fscanf(fptr, " %[^\n]", str);
        //printf("%s\n", str);
        for(int i = 0; str[i]; i++)
        {
            str[i] = tolower(str[i]);
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                printf("%c", str[i]);
        }
        printf("\n");
        for(int i = 0; str[i]; i++)
        {
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
                printf("%c", str[i]);
        }
        printf("\n");
    }

    return 0;
}
