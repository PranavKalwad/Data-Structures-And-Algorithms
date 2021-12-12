#include<stdio.h>
#include<stdlib.h>

#define size 10

typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* chain[size];

void init()
{
    int i;
    for(i=0;i<size;i++)
    {
        chain[i]=NULL;
    }
}

  
void insert(int value)
{
    //Create a node with a value
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL; 

    //Calculating the hash value
    int key = value % size;

    if(chain[key]==NULL)
    {
        chain[key] = newNode;
    }
    else //We can insert at the begining or at the end of the linked list that is formed.
    {
        struct node* head = chain[key];
        while(head->next!=NULL)
        {
            head = head->next;    
        }
        head->next = newNode;
        newNode->next = NULL;
    }
}


void print()
{
    int i;
    for(i=0;i<size;i++)
    {
        NODE* temp = chain[i];
        printf("chain[%d]--->",i);
        while(temp)
        {
            printf("%d--->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    init();
    insert(20);
    insert(30);
    insert(40);
    insert(51);
    insert(61);
    insert(71);
    print();
    return 0;
}