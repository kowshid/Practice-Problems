//a try by kowshid
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    //checks if list is empty. returns true if empty, false otherwise
    bool EmptyList()
    {
        if(head) return false;
        else return true;
    }

    //Creates Nodes with NULL next pointer
    Node* CreateNode(int item)
    {
        Node *newNode = (Node *) malloc(sizeof(Node));

        if(newNode == NULL)
        {
            printf("Error! Couldn't create new node\n");
            return NULL;
        }
        newNode->data = item;
        newNode->next = NULL;

        return newNode;
    }

    //Searches Nodes using data value, returns the node found
    //in case of multiple match, returns the first instance
    Node *SearchNode(int item)
    {
        if(EmptyList())
        {
            printf("Empty List, nothing to search for\n");
            return NULL;
        }

        Node *current = head;
        while(current != NULL)
        {
            if(current->data == item) break;
            current = current->next;
        }

        if(current == NULL) printf("No such node found in search\n");

        return current;
    }

    //Inserting in front of list
    void Prepend(int item)
    {
        Node *newNode = CreateNode(item);

        if(EmptyList())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    //Inserting at the end
    void Append(int item)
    {
        Node *newNode = CreateNode(item);

        if(EmptyList())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        Node *current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        tail = newNode;

    }

    //Inserting after a certain data valued node
    void InsertAfterItem(int item, Node *previousNode)
    {
        Node *newNode = CreateNode(item);
        if(EmptyList())
        {
            head = newNode;
            tail = newNode;
        }

        if(previousNode == NULL)
        {
            printf("Node not specified, Can't add\n");
            return;
        }

        newNode->next = previousNode->next;
        previousNode->next = newNode;
        if(previousNode == tail) tail = newNode;
    }

    //O for empty node
    int CountNode()
    {
        if(EmptyList())
        {
            printf("\nEmpty List\n");
            return 0;
        }

        int result = 0;
        Node *current = head;
        while(current != NULL)
        {
            result++;
            current = current->next;
        }

        return result;
    }

    //Removes node with data value
    //In case of multiple Node having same data, first instance is deleted
    void RemoveItem(int item)
    {
        if(EmptyList())
        {
            printf("\nEmpty List, Can't remove anything\n");
            return;
        }

        Node *target = SearchNode(item);
        //printf("target->data = %d\n", target->data);

        if(target == NULL)
        {
            printf("No such node to delete\n");
            return;
        }

        if(target == head)
        {
            if(target == tail)
            {
                head = NULL;
                tail = NULL;
                return;
            }
            head = head->next;
            free(target);
            return;
        }

        Node *current = head;
        while(current->next != target)
        {
            current = current->next;
        }

        current->next = target->next;
        if(target == tail) tail = current;
        free(target);
    }

    //position starts from 1
    //removes node from specified position
    void RemoveAtPos(int position)
    {
        int len = CountNode();
        //printf("len = %d\n", len);

        if(len < position)
        {
            printf("Invalid position, not deleted anything\n");
            return;
        }

        Node *target;

        if(len == 1)
        {
            target = head;
            head = NULL;
            tail = NULL;
            free(target);
            return;
        }

        Node *current = head;

        while(position-2)
        {
            position--;
            //printf("pos = %d\n", position);
            current = current->next;
        }

        //printf("current = %d\n", current->data);

        target = current->next;

        current->next = target->next;
        if(target == tail) tail = current;
        free(target);
    }

    void PrintList()
    {
        if(EmptyList())
        {
            printf("Empty List\n");
            return;
        }

        Node *current = head;
        printf("Current List:\n");
        while(current != NULL)
        {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("\n");
    }

    void headtail()
    {
        if(head == NULL && tail == NULL)
        {
            printf("No head or tail\n");
            return;
        }
        printf("head = %d, tail = %d\n", head->data, tail->data);
    }
};

int main()
{
    LinkedList lList;
    Node *temp;
    //lList.RemoveAtPos(4);
    //lList.RemoveItem(4);
    lList.Prepend(1);
    lList.Append(2);
    lList.PrintList();
    lList.headtail();
    lList.Prepend(0);
    lList.Append(2);
    lList.headtail();
    lList.PrintList();
    //lList.RemoveItem(2);
    temp = lList.SearchNode(2);
    lList.InsertAfterItem(5, temp);
    lList.headtail();
    lList.PrintList();
    return 0;
}
