//stack implementation using static array.
#include<stdio.h>
#define MAX 5
typedef struct stack
{
    int s[MAX];
    int top;
}stack_t;

void init(stack_t* ps);
int push(stack_t *ps,int ele);
int pop(stack_t *ps,int *pe);
int peep(stack_t *ps,int *pe); //Accessing top most element of the stack.
int isFull(stack_t* ps);
int isEmpty(stack_t* ps);
void disp(stack_t *ps);
int main()
{
    stack_t s;
    init(&s);
    int choice,ele,res;
    do{
        printf("1.Push\n2.Pop\n3.Peep\n4.Isempty\n5.isFull\n6.Display\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element:\t");
                    scanf("%d",&ele);
                    res=push(&s,ele);
                    if(res==0)
                        printf("Overflow\n");
                    else
                        printf("Push successful\n");    
                    break;
            case 2:res=pop(&s,&ele);
                    if(res==0)
                        printf("Underflow\n");
                    else
                        printf("Element popped succesully\n");    
                    break;
            case 3:
                    res=peep(&s,&ele);
                    if(res==0)
                    {
                        printf("Underflow\n");
                    }
                    else
                    {
                        printf("peep element is %d\n",ele);
                    }
                    break;
            case 4:if(isEmpty(&s))
                        printf("Underflow\n");
                    else
                        printf("Stack not empty\n");
                    break;
            case 5:
                    if(isFull(&s))
                        printf("Overflow\n");
                    else
                        printf("Stack not full\n");
                    break;
            case 6:disp(&s);
                    break;                                                        
        }

    }while(choice<7);
    return 0;
}

void init(stack_t* ps)
{
    ps->top=-1;
    
}


int push(stack_t *ps,int ele) 
{
    if(ps->top==MAX-1) //Stack is full.
    {
        return 0;
    }
    else
    { //Entering the first element of the stack
        ps->top++;
        ps->s[ps->top]=ele;
        return 1;
    }
}

int pop(stack_t *ps,int *pe)
{
    if(ps->top==-1) //When no elements to pop from the list.
    {
        return 0;
    }
    else
    {
        *pe=ps->s[ps->top]; //Top has to be updated
        ps->top--;
        return 1;
    }
}

int peep(stack_t *ps,int *pe) //Accessing the top most element of the stack.We do not make any changes.
{
    if(ps->top==-1)
    {
        return 0;
    }
    else
    {
        *pe=ps->s[ps->top];
        return 1;
    }
}

int isEmpty(stack_t* ps)
{
    return ps->top==-1;
}

int isFull(stack_t* ps)
{
    return ps->top==MAX-1;
}

void disp(stack_t *ps)
{
    if(isEmpty(ps))
    {
        printf("Stack is Empty");
    }
    else
    {
        for(int i=0;i<=ps->top;i++) 
        {
            printf("%d\t",ps->s[i]);
        }
    }
}