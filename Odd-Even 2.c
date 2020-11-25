/*
Input: T numbers containing at most 100 digits
Output: 'even' or 'odd'
*/

#include <stdio.h>

int main()
{
    int T, RMD, idx; //right most digit
    char n[101];

    scanf("%d\n", &T);
    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            scanf("%s", &n);
            idx = 0;
            while(n[idx] != '\0')
                idx++;
            //printf("%c\n", n[idx-1]);
            RMD = n[idx-1] - '0';
            if(RMD % 2)
                printf("odd\n");
            else
                printf("even\n");
        }
    }
    else
        printf("T out of bound\n");

    return 0;
}
