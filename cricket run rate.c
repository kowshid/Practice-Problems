//

/*
    Input: T lines each having opposition runs, current runs, balls remaining
    Output:
    CRR, RRR
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

    int T;
    double target, score, ballsRemaining, CRR, RRR;
    fscanf(fptr, "%d", &T);

    if(T > 0 && T <= 100)
    {
        for(int i = 0; i < T; i++)
        {
            fscanf(fptr, "%lf%lf%lf", &target, &score, &ballsRemaining);
            if(target < score || ballsRemaining > 300.0)
            {
                printf("input error\n");
                continue;
            }

            target = target + 1.0;

            CRR = 6.0 * score / (300.0 - ballsRemaining);
            RRR = 6.0 * (target - score) / ballsRemaining;

            printf("Case %d: %.2lf %.2lf\n", i + 1, CRR, RRR);
        }
        //printed list is unsorted
        printf("\n");
    }

    return 0;
}

