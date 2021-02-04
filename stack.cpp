//a try by kowshid
//#include <bits/stdc++.h>
#include <stdio.h>
//#include <stdlib.h>
using namespace std;

#define STACK_MAX 50

class Stack
{
public:
    int top;
    int data[STACK_MAX];

    Stack()
    {
        top = 0;
        printf("Stack created, top = 0\n");
    }

    bool Empty()
    {
        if(!top) return true;
        else return false;
    }

    void push(int n)
    {
        if(top < STACK_MAX)
        {
            data[top] = n;
            top++;
        }
        else printf("\nNot Enough Space\n");
    }

    void pop()
    {
        if(Empty()) printf("\nStack is empty, No item to pop\n ");
        else top--;
    }

    int topElement()
    {
        if(Empty())
        {
            printf("\nStack is empty\n");
            return -1;
        }
        else return data[top-1];
    }

    void print()
    {
        printf("\nCurrent Stack\n");
        if(Empty()) printf("*empty*\n");
        else
        {
            for(int i = 0; i < top; i++)
            {
                printf("%d ", data[i]);
            }
        }
    }
};

int main()
{
    Stack s1;
    s1.push(5);
    s1.push(6);
    s1.push(2);
    s1.print();
    printf("\nCurrent top element is %d\n", s1.topElement());
    //s1.topElement();
    s1.pop();
    s1.pop();
    printf("\nCurrent top element is %d\n", s1.topElement());
    s1.print();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.print();
    return 0;
}
