/*
    Input: 2T lines:
    a string str
    a char ch
    Output:
    instance of ch in str
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int arr[26];

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = fopen("D:\\input.txt", "r");
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T;
    char str[10000], ch;
    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            fscanf(fptr, " %[^\n]", str);
            fscanf(fptr, " %c", &ch);

            for(int i = 0; i < 26; i++)
                arr[i] = 0;

            for(int j = 0; str[j]; j++)
                str[j] = tolower(str[j]);

            for(int j = 0; str[j]; j++)
                arr[str[j] - 'a']++;

            printf("In %s, Count of:\n", str);
            for(int j = 0; j < 26; j++)
            {
                if(arr[j])
                    printf("%c --> %d\n", ('a' + j), arr[j]);
            }
        }
        printf("\n");
    }

    return 0;
}


