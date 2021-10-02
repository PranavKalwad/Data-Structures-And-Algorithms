#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node_t;
node_t* front= NULL;
node_t* rear= NULL;

void display()
{
    if(front==NULL && rear==NULL)
        printf("Queue is empty");
    else
    {
        node_t* temp=front;
       do
       {
           printf("%d\t",temp->data);
           temp=temp->link;
       } while (temp!=front);
       printf("\n");
    }
}
void insert_last()
{
    printf("Enter the value:\t");
    int value;
    scanf("%d",&value);
    node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = value;
	temp->link = NULL;
    if(front==NULL && rear==NULL)
    {
        front=temp;
        rear=temp;
        rear->link=front;
    }
    else
    {
        rear->link=temp;
        rear=temp;
        temp->link=front;
    }
}
void delete_begin()
{
    node_t* temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("The queue is empty");
    }
    else if(front->link==NULL) //When only 1 node is present
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->link;
        rear->link=front;
    }
    printf("Deleted data is %d\t",temp->data);
    free(temp);
    temp=NULL;
}

int main()
{
    node_t* front=NULL;
    node_t* rear=NULL;
    int n,c,ch;
    do
{
	printf("enter the choice :\n 1-display\n 2-insert at last\n 3-delete from beginning \n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("entered choice is 1-display\n");
			display();
			break;
		
		case 2: printf("entered choice is 3-insert at last\n");
			insert_last();
			break;

		
		case 3: printf("entered choice is 5-delete at beginning\n");
			delete_begin();
			break;
	}

}while(1);
}