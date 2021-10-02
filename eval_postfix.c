#include<stdio.h>
#include<ctype.h>
#define max 15
typedef struct stack
{
    float s[max];
    int top;
}stack_t;

void init(stack_t* opst)
{
    opst->top=-1;
}

void push(stack_t* opst,float ele)
{
    if(opst->top==max)
    {
        printf("Overflow\n");
    }
    else
    {
        opst->top++;
        opst->s[opst->top]=ele;
    }
}

float pop(stack_t* opst)
{
    float ele=0;
    if(opst->top==-1)
        printf("Underflow\n");
    else
    {
        ele=opst->s[opst->top];
        opst->top--;
    }
    return ele;
}

int main()
{
    stack_t opst;
    init(&opst);
    char post[20],ch;
    float op1,op2,res;
    int i;
    printf("Enter the string:\n");
    gets(post);
    for(int i=0;post[i]!='\0';i++)
    {
        ch=post[i];
        if(isdigit(ch))
            push(&opst,ch -'0');
        else
        {
            op2=pop(&opst);
            op1=pop(&opst);
            switch(ch)
            {
                case '+':res=op1+op2;
                        break;
                case '-':res=op1-op2;
                        break;
                case '*':res=op1*op2;
                        break;
                case '/':res=op1/op2;
                        break;
            }
            push(&opst,res);
        }
    }
    res=pop(&opst);
    printf("The result is:%f\t",res);
    return 0;
}