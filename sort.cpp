#include <stdio.h>
using namespace std;

void swapN(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    int index_min, temp;
    for(int i = 0; i < (n-1); i++)
    {
        index_min = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j]<arr[index_min]) index_min = j;
        }

        if(index_min != i)
        {
            swapN(&arr[i], &arr[index_min]);
//            temp = arr[i];
//            arr[i] = arr[index_min];
//            arr[index_min] = temp;
        }
    }
}

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < (n-1); i++)
    {
        bool flag = true;
        for(int j = 0; j < (n-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapN(&arr[j], &arr[j+1]);
                flag = false;
            }
        }

        printf("\nafter %dth iteration\n", i);
        for(int j = 0; j < n; j++) printf("%d ", arr[j]);

        if(flag) break;
    }
}

void InsertionSort(int arr[], int n)
{
    int j, idx, item, flag;
    for(int i = 1; i < n; i++)
    {
        //flag = 1;
        item = arr[i];
        j = i-1;

        //for(int j = idx; j >= 0; j--)
        while(j >= 0 && arr[j]>item)
        {
//            if(arr[j] < item)
//            {
//                idx = j;
//                flag = 0;
//                break;
//            }
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = item;

        printf("\nafter %dth iteration\n", i);
        for(int j = 0; j < n; j++) printf("%d ", arr[j]);
    }
}

int main()
{
    int arr[] = {3, 1, 2, 5, 4};

    InsertionSort(arr, 5);
    //for(int i = 0; i < 5; i++) printf("%d ", arr[i]);

    return 0;
}

