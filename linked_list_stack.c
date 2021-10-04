typedef struct node
{
    int key;
    struct node* link;
}node_t;

typedef struct top
{
    node_t* top;
}top_t;

void init(top_t *t);
node_t* create_node(int ele);
void push(top_t* t,int ele);
int pop(top_t* t,int *pe);
void isEmpty(top_t *t);
int peep(top_t* t,int *pe);
void disp(top_t* t);
#include<stdio.h>
#include<stdlib.h>
int main()
{
    top_t t;
    init(&t);
    int choice,ele,res;
    do
    {
        printf("1.Push\n2.Pop\n3.Peep\n4.Isempty\n5.Display\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element:\t");
                   scanf("%d",&ele);
                   push(&t,ele);
                   break;
            case 2:res=pop(&t,&ele);
                   if(res==1)
                        printf("Element poped successfully is %d",ele);
                    else
                        printf("Stack is empty");
                    break;
            case 3:printf("Top of stack is:\n");
                   res=peep(&t,&ele);
                   if(res==0)
                        printf("Underflow");
                    else
                        printf("Top of stack is:%d",ele);
                    break;
            case 4:isEmpty(&t);
                    break;
            case 5:printf("The stack elements are:\n");
                   disp(&t);
                    break;
        }
    } while (choice<6);
    return 0;
}

void init(top_t *t)
{
    t->top=NULL;
}

node_t* create_node(int ele)
{
    node_t* temp=malloc(sizeof(node_t));
    temp->key=ele;
    temp->link=NULL;
}

void push(top_t* t,int ele) //Insertion at the begining of the linked list.
{
    node_t* temp=create_node(ele);
    temp->link=t->top;
    t->top=temp;

}


int pop(top_t* t,int* pe) //Deletion at the begining of the linked list.
{
    if(t->top==NULL)
    {
        return 0;
    }
    else
    {
        node_t* pres=t->top;
        *pe=pres->key;
        t->top=pres->link;
        free(pres);
        pres=NULL;
        return 1;
    }
}

void disp(top_t* t)
{
    if(t->top==NULL)
    {
        printf("Empty list.");
    }
    else
    {
        node_t* pres=t->top;
        while(pres!=NULL)
        {
            printf("%d\t",pres->key);
            pres=pres->link;
        }
        printf("\n");
    }

}


void isEmpty(top_t *t)
{
     if(t->top==NULL)
        printf("Stack is empty");
    else
        printf("stack not empty");
}

int peep(top_t* p,int* pe)
{
    if(p->top==NULL)
    {
        return 0;
    }
    else
    {
        *pe=p->top->key;
        return 1;
    }
}