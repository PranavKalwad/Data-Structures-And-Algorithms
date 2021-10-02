#include<stdio.h>
#include<ctype.h> //Standard library functions to handle characters.
#define max 20
//We are taking seperate stack and top variable.
char stack[max];
int top=-1;

void push(int ele)
{
    if(top==max)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top]=ele;
    }
}

char pop()
{
    char ele;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        ele=stack[top];
        top--;
    }
    return ele;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int prec(char c) //Fucntion checks the precedence of the characters entered.
{
    if(c=='^') //Highest precendence.
        return 3;
    else if (c=='*' || c=='/')
        return 2; //2nd highest precedence.
    else if(c=='+'||c=='-')
        return 1; //Least precedence.
    else
        return 0;
}

void infix_to_postfix(char* in,char* post) //We are sending the pointer to the two arrays infix and postfix.
{
    int i,j=0;
    char ss,x; //ss-->Scanned symbol.
    for(i=0;i[in]!='\0';i++)
    {
        ss=in[i];
        if(isalnum(ss)) //the scanned symbol is either a alphabet or a number.
            post[j++]=ss; //First ss is added to post[j] and then the value of j is incremented.
        else
        {
            if(ss=='(')
                push(ss);
            else if(ss==')')
            {
                while((x=pop())!='(')
                {
                    post[j++]=x;
                }
            }
            else
            {
                while(prec(ss)<=prec(stack[top]))
                {
                    x=pop();
                    post[j++]=x;//First ss is added to post[j] and then the value of j is incremented.
                }
                push(ss);
            }
        }
    }
    while(!isEmpty())
    {
        post[j++]=pop();
    }
    post[j]='\0';
}

int main()
{
    char infix[20];
    char postfix[20];
    printf("Enter the infix expression:\t");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("Postfix expression is: %s\t",postfix);
    return 0;
}