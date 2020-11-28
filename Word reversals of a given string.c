/*
    Input: 2T lines:
    a string str
    Output:
    print each word of the string in reverse order
*/

#include <stdio.h>
#include <string.h>

void printReverse(char str[])
{
    int len = strlen(str) - 1;
    for(int i = len; i >= 0; i--)
        printf("%c", str[i]);
    printf(" ");
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

    int T, len, j;
    char str[1001], word[1001];
    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int k = 0; k < T; k++)
        {
            j = 0;
            fscanf(fptr, " %[^\n]", str);
            //printf("%s\n", str);
            len = strlen(str);

            for(int i = 0; str[i]; i++)
            {
                if(str[i] != ' ')
                {
                    word[j] = str[i];
                    j++;
                }
                else if(j > 0)
                {
                    word[j] = '\0';
                    printReverse(word);
                    j = 0;
                }
            }
            if(j > 0)
            {
                word[j] = '\0';
                printReverse(word);
            }

            printf("\n");
        }
    }

    return 0;
}
