/*
Sorting of 3 input integers
*/

#include <stdio.h>

int main()
{
    int T, n1, n2, n3, temp;
    FILE *fptr; //file pointer to read from file
    fptr = (fopen("D:\\input.txt", "r"));

    if(fptr == NULL)
    {
       printf("File Pointer Error!");
       exit(1);
    }

    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            fscanf(fptr, "%d", &n1);
            fscanf(fptr, "%d", &n2);

            if(n1 > n2) //need to make n1 < n2
            {
                temp = n1;
                n1 = n2;
                n2 = temp;
            }

            fscanf(fptr, "%d", &n3);

            if(n3 > n2)
                ;

            else if(n3 > n1)
            {
                temp = n3;
                n3 = n2;
                n2 = temp;
            }

            else if(n3 < n1)
            {
                temp = n3;
                n3 = n2;
                n2 = temp;

                temp = n2;
                n2 = n1;
                n1 = temp;
            }

            printf("%d %d %d\n", n1, n2, n3);
        }
    }
    else
        printf("T out of bound\n");

    return 0;
}
