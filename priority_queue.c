#include<stdio.h>
#define max 15
typedef struct Input_info
{
int data;
int pr;
}INFO;
typedef struct Priority_queue
{
INFO q[max];
int front;
int rear;
}PQUEUE;
int count =0;
void init(PQUEUE* ppq)
{
ppq->front = 0;
ppq->rear = -1;
}
int isempty(PQUEUE* ppq)
{
return (ppq->front > ppq->rear);
}
int isfull(PQUEUE* ppq)
{
return (ppq->rear == max-1);
}
void enqueue(PQUEUE* ppq, int ele, int Epr, int co)
{
int i,pos,k;
if(isfull(ppq))
printf("full queue\n");
else
{
i = ppq->rear;
ppq->rear++;
while(ppq->q[i].pr >= Epr && i>=0)
{
ppq->q[i+1] = ppq->q[i];
i--;
}
ppq->q[i+1].data = ele;
ppq->q[i+1].pr = Epr;

}
}

int dequeue(PQUEUE* ppq)
{ int ele;
if(isempty(ppq))
{
printf("empty queue\n");
ele = -1;
}
else
{
ele = ppq->q[ppq->front].data;
ppq->front++;
}
return ele;
}
void display(PQUEUE* ppq)
{ int k = ppq->front;
while(k<=ppq->rear)
{
printf("%d\t", ppq->q[k].data);
k++;
}
}
int FoQ(PQUEUE* ppq)
{
return (ppq->q[ppq->front].data);
}
int main()
{
PQUEUE ppq;
init(&ppq);
int ch,ele,Epr;
while(1)
{ printf("enter the operation to be performed:\n");
printf("1-enqueue\n2-dequeue\n3-display\n4-isempty\n5-FoQ\n");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("enter the element and its priority\n");
scanf("%d%d", &ele,&Epr);
enqueue(&ppq,ele,Epr,count);count++;
break;
case 2: ele = dequeue(&ppq);
printf("deleted element is %d\n", ele);count--;
break;
case 3: printf("Queue contents are:\n");
display(&ppq);
break;
case 4: if(isempty(&ppq))

printf("empty queue\n");
else
printf("Not empty queue\n");
break;
case 5: printf("front value= %d\n", FoQ(&ppq));
break;

}}}