#include <stdio.h>

int main()
{
    int i;
    scanf("%d", &i);
    int arr[i];
    for(int k = 0; k < i; k++)
        arr[k] = k;
    for(int k = 0; k < i; k++)
        printf("%d ", arr[k]);

    return 0;
}
