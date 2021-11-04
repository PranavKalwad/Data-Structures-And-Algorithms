#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 5
typedef struct node
{
    int data;
    struct node *right,*left;
}NODE;
typedef struct stack
{
    NODE* s[max];
    int top;
}STACK;

typedef struct tree
{
    NODE* root;
}TREE;

void init_stack(STACK* ps)
{
    ps->top=-1;
}

void init_root(TREE* pt)
{
    pt->root=NULL;
}

int push(STACK *ps,NODE* pt) //we are only pushing the address of the node to the stack and not the contents of the node.
{
    if(ps->top==max-1)
        return 0;
    else
    {
        ps->top++;
        ps->s[ps->top]=pt;
        return 1;
    }
}

NODE* pop(STACK* ps)
{
    NODE* ele;
    if(ps->top==max-1)
        return 0;
    else
    {
        ele=ps->s[ps->top];
        ps->top--;
    }
    return ele;
}

float evaluate(NODE* r)
{
    float res;
    switch(r->data)
    {
        case '+':res=(evaluate(r->left)+evaluate(r->right));
                break;
        case '-':res=(evaluate(r->left)-evaluate(r->right));
                break;
        case '*':res=(evaluate(r->left)*evaluate(r->right));
                break;
        case '/':res=(evaluate(r->left)/evaluate(r->right));
                break;
        default:return(r->data-'0');
    }
    return res;
}


float eval(TREE* pt)
{

    evaluate(pt->root);
}

int main()
{
    char postfix[max];
    STACK ps;
    TREE pt;
    init_stack(&ps);
    init_root(&pt);
    printf("Enter the postfix expression:\t");
    scanf("%s",postfix);
    int i=0;
    NODE* temp;
    while(postfix[i]!='\0')
    {
        temp=(NODE*)malloc(sizeof(NODE));
        temp->data=postfix[i];
        if(isdigit(postfix[i]))
        {
            push(&ps,temp);
        }
        else //When the postfix array character is an operator.
        {
            temp->right=pop(&ps);
            temp->left=pop(&ps);
            push(&ps,temp);
        }
        i++;
    }
    pt.root=pop(&ps); //At the end the final result is stored in the stack is popped.
    printf("Result is %f\n",eval(&pt));
    return 0;
}


