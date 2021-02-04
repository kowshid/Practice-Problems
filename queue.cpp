//a try by kowshid
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define Qsize 6

class Queue
{
public:
    int data[Qsize];
    int head, tail;

    Queue()
    {
        head = 0;
        tail = 0;
    }

    bool IsEmpty()
    {
        if(head == tail) return true;
        else return false;
    }

    bool IsFull()
    {
        if((tail+1)%Qsize == head) return true;
        else return false;
    }

    int sz()
    {
        if(tail >= head) return (tail-head);
        else return (tail-head+Qsize);
    }

    void enqueue(int item)
    {
        if(IsFull())
        {
            printf("\nQueue is full\n");
            return;
        }
        data[tail] = item;
        tail = (tail+1)%Qsize;
    }

    void dequeue()
    {
        if(IsEmpty()) printf("Q is empty, nothing to dq\n");
        else
        {
            printf("%d is dequeued\n", data[head]);
            head = (head+1)%Qsize;
        }
    }

    int frnt()
    {
        if(IsEmpty())
        {
            printf("\nNo front element, empty q\n");
            return -1;
        }
        return data[head];
    }

    int rear()
    {
        if(IsEmpty())
        {
            printf("No tail element, empty q\n");
            return -1;
        }
        return data[(tail-1+Qsize)%Qsize];
    }

    void print()
    {

    }
};

int main()
{
    Queue q;

    //q.dequeue();
    //q.frnt();
    //q.rear();

    q.enqueue(1);
    printf("tail = %d\n", q.tail);
    q.enqueue(2);
    printf("tail = %d\n", q.tail);
    q.enqueue(3);
    printf("tail = %d\n", q.tail);
    q.enqueue(4);
    printf("tail = %d\n", q.tail);
    q.enqueue(5);
    printf("tail = %d\n", q.tail);
    //printf("queue size is %d\n", q.sz());
    q.dequeue();
    q.enqueue(6);
    q.dequeue();
    //q.enqueue(7);
    printf("tail = %d\n", q.tail);
    printf("head idx = %d, tail idx = %d\n", q.head, q.tail);
    printf("head element = %d, tail element = %d\n", q.frnt(), q.rear());
    printf("size = %d\n", q.sz());


    return 0;
}
