#include<stdio.h>
#define max 5
typedef struct cqueue
{
    int q[max];
    int front;
    int rear;   
}cqueue_t;

void init(cqueue_t* pcq)
{
    pcq->front=max-1;
    pcq->rear=max-1;
}

int isFull(cqueue_t* pcq)
{
    return ((pcq->rear+1)%max==pcq->front);
}

int isEmpty(cqueue_t* pcq)
{
    return (pcq->rear==pcq->front);
}

void enqueue(cqueue_t* pcq,int ele)
{
    if(isFull(pcq))
        printf("Queue is full");
    else
    {
        pcq->rear=(pcq->rear+1)%max; //Incrementing the front and the rear pointer suitably.
        pcq->q[pcq->rear]=ele;
    }
}

int dequeue(cqueue_t* pcq)
{
    int ele=-1;
    if(isEmpty(pcq))
        printf("Queue is empty");
    else
    {
        pcq->front=(pcq->front+1)%max;
        ele=pcq->q[pcq->front];
    }
    return ele;
}

void display(cqueue_t* pcq)
{
    int k;
    if(isEmpty(pcq))
        printf("Queue is empty");
    k=(pcq->front+1)%max;
    while(k!=pcq->rear)
    {
        printf("%d\t",pcq->q[k]);
        k=(k+1)%max;    
    }
    printf("%d\n",pcq->q[k]);
}

int Foq(cqueue_t* pcq)
{
    return (pcq->q[(pcq->front+1)%max]);
}



int main()
{
    cqueue_t cqt;
    init(&cqt);
    int ch,ele,res;
    while(1)
    {
        printf("Enter the opetation to be performed:\n");
        printf("\n1.Enqueue\n2.Dqueue\n3.Display\n4.isempty\n5.Toq");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element:\t");
                   scanf("%d",&ele);
                    enqueue(&cqt,ele);
                    break;
            case 2:ele=dequeue(&cqt);
                    printf("deleted element is %d\n",ele);
                    break;
            case 3:printf("The queue is:\n");
                    display(&cqt);
                    break;
            case 4:if(isEmpty)
                        printf("Queue is not empty");
                    else
                        printf("Queue is not empty");
                        break;
            case 5:res=Foq(&cqt);
                    printf("Top of stack is:%d\n",res);
                    break;
        }
    }
    return 0;
}