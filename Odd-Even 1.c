//

/*
    Input:
    Number of Input
    Inputs
    Output:
    'even' or 'odd'
*/

#include <stdio.h>

int main()
{
    int T, n;

    scanf("%d", &T);
    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            scanf("%d", &n);
            if(n % 2)
                printf("odd\n");
            else
                printf("even\n");
        }
    }

    else
        printf("T out of bound\n");

    return 0;
}
