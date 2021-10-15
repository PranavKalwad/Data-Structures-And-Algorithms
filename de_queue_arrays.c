#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct queue
{
    int data[max];
    int front;
    int rear;
}de_queue;

void init(de_queue* dq);
int empty(de_queue* dq);
int full(de_queue* dq);
void enqR(de_queue* dq,int ele); //enqueue operation at the end of the queue
void enqF(de_queue* dq,int ele); //enqueue operation at the front of the queue
int deqR(de_queue* dq);//dequeue operation at the end of the queue.
int deqF(de_queue* dq);//dequeue operation at the front of the queue.
void disp(de_queue* dq);


int main()
{
    int i,x,op,n;
    de_queue d;
    init(&d);
    do
    {
        printf("\n1.create\n2.Insert(rear)\n3.Insert(front)\n4.delete(rear)\n5.delete(front)\n6.display queue\n7.exit");
        printf("Enter your choice:\t");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("\nEnter number of elements:");

                    scanf("%d",&n);

                    init(&d);

                    printf("\nEnter the data:");

                    for(i=0;i<n;i++)

                    {

                    scanf("%d",&x);

                    if(full(&d))

                    {

                    printf("\nQueue is full!!");

                    exit(0);

                    }

                    enqR(&d,x);

                    }

                    break;

                    case 2: printf("\nEnter element to be inserted:");

                    scanf("%d",&x);

                    if(full(&d))

                    {

                    printf("\nQueue is full!!");

                    exit(0);

                    }

                    enqR(&d,x);

                    break;

                    case 3: printf("\nEnter the element to be inserted:");

                    scanf("%d",&x);

                    if(full(&d))

                    {

                    printf("\nQueue is full!!");

                    exit(0);

                    }

                    enqF(&d,x);

                    break;
            case 4:if(empty(&d))
                    {
                        printf("Queue is empty");
                    }
                    else
                    {
                        x=deqR(&d);
                        printf("Element dequeued from the rear is %d\n",x);
                    }
                    break;
            case 5:if(empty(&d))
                    {
                        printf("Queue is empty");
                    }
                    else
                    {
                        x=deqF(&d);
                        printf("Element dequeued from the front is %d\n",x);
                    }
                    break;
            case 6:printf("The queue is as follows\n");
                   disp(&d);
                   break;

            case 7:exit(0);
                   break;
        }
    } while (op!=7);
    
    return 0;
}



void init(de_queue* dq)
{
    dq->front=0;
    dq->rear=0;
}
int empty(de_queue* dq)
{
    if(dq->rear==-1)
    {
        return 1;
    }
    else
        return 0;
}
int full(de_queue* dq)
{
    if((dq->rear+1)%max==dq->front)
    {
        return 1;
    }
    else
        return 0;
}
void enqR(de_queue* dq,int ele)
{
    if(empty(dq))
    {
        dq->front=0;
        dq->rear=0;
        dq->data[0]=ele;
    }
    else
    {
        dq->rear=(dq->rear+1)%max;
        dq->data[dq->rear]=ele;
    }
}
void enqF(de_queue* dq,int ele)
{
    if(empty(dq))
    {
        dq->front=0;
        dq->rear=0;
        dq->data[0]=ele;
    }
    else
    {
        dq->front=(dq->front+1)%max;
        dq->data[dq->front]=ele;
    }   
}
int deqR(de_queue* dq)
{
    int x;
    x=dq->data[dq->rear];
    if(dq->rear==dq->front) //The element to be deleted is the only element of the queue and it is to be deleted from the right
    {
        init(dq); //This makes the queue empty
    }
    else
    {
        //Decrementing the rear pointer suitably
        dq->rear=(dq->rear-1)%max;
        return x;
    }
}
int deqF(de_queue* dq)
{
    int x;
    x=dq->data[dq->front];
    if(dq->rear==dq->front) //The element to be deleted is the only element of the queue and it is to be deleted from the right
    {
        init(dq); //This makes the queue empty
    }
    else
    {
        //Decrementing the rear pointer suitably
        dq->front=(dq->front+1)%max;
        return x;
    }
}
void disp(de_queue* dq)
{
    if(empty(dq))
    {
        printf("Queue is empty\n");
    }
    else
    {
        int a=dq->front;
        while(a!=dq->rear)
        {
            printf("%d\t",dq->data[a]);
            a=(a+1)%max;
        }
        printf("%d\n",dq->data[a]);
    }
}