//a try by kowshid
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool IsBalanced(char input[])
{
    char data[100], lastChar;
    int len = strlen(input), top = 0;

    for(int i = 0; i < len; i++)
    {
        if(input[i] == '(')
        {
            data[top] = '(';
            top++;
        }
        else if(input[i] == ')')
        {
            if(top == 0) return false;
            top--;
        }
    }

    if(top == 0) return true;
    else return false;
}

int main()
{
    char input[100];
    scanf("%s", input);

    if(IsBalanced(input)) printf("True\n");
    else printf("False");

    return 0;
}

