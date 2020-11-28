/*
    Input: 2T lines:
    a string str only containing space
    Output:
    word count in str
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));
    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    int T, count;
    char str[1001], word[1001];
    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int k = 0; k < T; k++)
        {
            count = 1;
            fscanf(fptr, " %[^\n]", str);
            //printf("%s\n", str);

            for(int i = 0; str[i]; i++)
            {
                if(str[i] == ' ')
                {
                    while(str[i] == ' ') //if contains more than one space
                        i++;
                    count++;
                }
            }

            printf("%s --> %d\n", str, count);
        }
        printf("\n");
    }

    return 0;
}

