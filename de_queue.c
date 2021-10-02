#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* rlink,*llink;
}node_t;

typedef struct dequeue
{
    node_t* rear,*front;
}dequeue_t;

void init(dequeue_t* pdq)
{
    pdq->rear=NULL;
	pdq->front=NULL;
}

void display(dequeue_t* pdq)
{
    if(pdq->front==NULL)
    {
        printf("Empty queue");
    }
    else
    {
        node_t* pres=pdq->front;
        while(pres!=pdq->rear)
        {
            printf("%d\t",pres->data);
            pres=pres->rlink;
        }
        printf("%d\t",pres->data);
    }
}

void insert_beg(dequeue_t* pdq,int ele)
{
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    temp->data=ele;
	temp->rlink=NULL;
	temp->llink=NULL;
    if(pdq->front==NULL)
    {
        pdq->front=temp;
        pdq->rear=temp;
    }
    else
    {
        temp->rlink=pdq->front;
        pdq->front->llink=temp;
        pdq->front=temp;
    }
}

void insert_last(dequeue_t* pdq,int ele)
{
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    temp->data=ele;
	temp->rlink=NULL;
	temp->llink=NULL;
    if(pdq->front==NULL)
    {
        pdq->front=temp;
        pdq->rear=temp;
    }
    else
    {
        pdq->rear->rlink=temp;
        temp->llink=pdq->rear;
        pdq->rear=temp;
    }
}

int delete_beg(dequeue_t* pdq)
{
    int ele;
    node_t* temp;
    if(pdq->front==NULL)
    {
        ele=-1;
        return ele;
    }
    temp=pdq->front;
    ele=temp->data;

    if(pdq->front==pdq->rear) //Only 1 node is present.
    {
        pdq->front=NULL;
        pdq->rear=NULL;
    }
    else
    {
        pdq->front=temp->rlink;
        pdq->front->llink=NULL;
    }
    free(temp);
    return ele;
}


int delete_end(dequeue_t* pdq)
{
    int ele;
    node_t* temp;
    if(pdq->front==NULL)
    {
        ele=-1;
        return ele;
    }
    temp=pdq->rear;
    ele=temp->data;

    if(pdq->front==pdq->rear) //Only 1 node is present.
    {
        pdq->front=NULL;
        pdq->rear=NULL;
    }
    else
    {
        pdq->rear=pdq->rear->llink;
        pdq->rear->rlink=NULL;
    }
    free(temp);
    return ele;
}

int main()
{
    int k,x,ch;
	dequeue_t pdq;
	init(&pdq);
	printf("enter the operation to be performed\n");
	
	do
	{
	printf("1-insert beg\n 2-insert last\n 3-delete beg\n 4-delete last\n 5- display\n ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("enter the value\n");
			scanf("%d", &x);
			insert_beg(&pdq, x);
			break;

		case 2: printf("enter the value\n");
			scanf("%d", &x);
			insert_last(&pdq, x);
			break;
		case 3: k = delete_beg(&pdq);
			printf("ELEMENT DELETED = %d\n", k);
			break;
		case 4: k = delete_end(&pdq);
			printf("ELEMENT DELETED = %d\n", k);
			break;
		case 5: display(&pdq);
			break;
	}
	}while(1);
	
	return 0;
}
