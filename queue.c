#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct queue
{
  int q[max];
  int front;
  int rear;
}QUEUE;

void init(QUEUE* pq);
int isEmpty(QUEUE* pq);
int isFull(QUEUE* pq);
int dequeue(QUEUE *pq);
void enqueue(QUEUE* pq,int ele);
void display(QUEUE* pq);
int Foq(QUEUE* pq);


int main()
{
        QUEUE pq;
        init(&pq);
        int ch,ele;
        while(1)
        {
                printf("Enter the operation to be performed:\t");
                printf("1.Enqueue\t2.Dequeue\t3.Display\t.4.Isfull\t5.Isempty\t6.Front of queue\t7.Exit\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("Enter the element to be entered:\t");
                               scanf("%d",&ele);
                               enqueue(&pq,ele);
                                break;
                        case 2:ele=dequeue(&pq);
                               printf("Deleted element is:%d",ele);
                               break;
                        case 3:printf("The contents of the queue are:\n");
                               display(&pq);
                               break;
                        case 4:if(isEmpty(&pq))
					printf("Not empty queue\n");
				else
					printf("Empty queue");
                                break;
                        case 5:if(isFull(&pq))
					printf("queue is not empty\n");
				else
					printf("empty queue\n");
                                break;
                        case 6:printf("front value= %d\n", Foq(&pq));
                               break;    
                        case 7:exit(0);           
                }
        }
        return 0;
}


void init(QUEUE* pq)
{
     pq->front=0;
     pq->rear=-1;
}


int isEmpty(QUEUE* pq)
{
        return (pq->front>pq->rear);
}


int isFull(QUEUE* pq)
{
        return (pq->rear==max-1);
}


int dequeue(QUEUE *pq)
{
        int ele;
        if(isEmpty(pq))
        {
                printf("Queue is empty");
                ele=-1;
         }
        else
        {
                ele=pq->q[pq->front];
                pq->front++;
        }
        return ele;
}

void enqueue(QUEUE* pq,int ele)
{
        if(isFull(pq))
                printf("Queue is full");
        else
                pq->rear++;
                pq->q[pq->rear]=ele; //Assign the element to the index of the array.
                
}


void display(QUEUE* pq)
{
 int k=pq->front;
  while(k<=pq->rear)
  {
        printf("%d\t",pq->q[k]);
        k++;
  }
}


int Foq(QUEUE* pq) //To display the front of the queue.
{
        return (pq->q[pq->front]);
}



