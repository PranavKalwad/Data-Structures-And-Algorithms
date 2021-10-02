#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node_t;

typedef struct queue
{
    node_t* front;
    node_t* rear;
}queue_t;

void init(queue_t* pq)
{
    pq->front=NULL;
    pq->rear=NULL;
}

void display(queue_t* pq)
{
    node_t* temp=pq->front;
    if((pq->front==NULL) && (pq->rear==NULL))
    {
        printf("Queue is empty");
    }
    else
    {
        do
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        } while (temp!=pq->front);
    }
    printf("\n");
}

void enqueue(queue_t* pq,int value,int n,int skip)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = value;
	temp->link = NULL;
    if(pq->front==NULL && pq->rear==NULL)
    {
        pq->front=temp;
        pq->rear=temp;
        pq->rear->link=pq->front;
    }
    else
    {
        pq->rear->link=temp;
        pq->rear=temp;
        temp->link=pq->front;
    }

}


int dequeue_skip(queue_t* pq,int n) //n value is the number of skips.
{
    node_t* temp=pq->front;
    int i;
    node_t* p,*befp;
    p=pq->front;
    befp=NULL;
    if(n==1)
    {
        printf("Everybody is killed there is no winner!");
    }
    while(p->link!=p)  //Until only single node is left in the circular list.
    {
        for(i=0;i<n-1;i++)
        {
            befp=p;
            p=p->link;
        }
        befp->link=p->link;
        printf("%d is killed\n",p->data);
        free(p);
        p=befp->link;
    }
    pq->front=p;
    return (p->data);

}

int main()
{
    queue_t pq;
	init(&pq);
	int n,skip,i;
	printf("enter the no. of person\n");
	scanf("%d", &n);
	printf("enter the number of skips\n");
	scanf("%d", &skip);
	
	for(i = 1;i<=n;i++)
		enqueue(&pq,i,n,skip);
	display(&pq);
	int winner = dequeue_skip(&pq, skip);
	printf("Winner is %d\n",winner );
    return 0;
}