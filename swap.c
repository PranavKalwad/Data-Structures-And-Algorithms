#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* link;
}node_t;

typedef struct list
{
	node_t* head;
}list_t;

void init(list_t* p);
void insert(list_t* p,int ele);
node_t* create_node(int ele);
void display(list_t *p);
void destroy_list(list_t* p);
void swap_node(list_t *p,int nd1,int nd2); 
int count_node(list_t* p);
int main()
{
	list_t lt;
	init(&lt);
	int choice,ele,nd1,nd2,count=0,res,del;
	do
	{
		printf("1.Insert\t2.Display\t3.Delete\t4.swap 2 nodes\t5.Count the nodes\t6.delete alternate nodes\n");
		printf("Enter your choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element:\t");
					scanf("%d",&ele);
					insert(&lt,ele);
					break;
			case 2:printf("The list is:\n");
					display(&lt);
					break;
			case 3:printf("Deleting the list....\n");
					destroy_list(&lt);
					break;
			case 4:
					printf("Enter the node_ts to be swapped:\t");
					scanf("%d %d",&nd1,&nd2);
					swap_node(&lt,nd1,nd2);
					printf("After swapping the node_ts list is\n");
					display(&lt);
					break;
			case 5:
					printf("The number of nodes of the linked list is %d\n",count_node(&lt)); 
					display(&lt);
					break;
		}
	}while(choice<4);
	return 0;
}

void init(list_t* p)
{
	p->head=NULL;
}


void display(list_t *p)
{
	if(p->head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		node_t* q=p->head;
		while(q!=NULL)
		{
			printf("%d\t",q->info);
			q=q->link;
		}
		printf("\n");
	}
}

node_t* create_node(int ele)
{
	node_t* temp=malloc(sizeof(node_t));
	temp->info=ele;
	temp->link=NULL;
	return temp;
}

void destroy_list(list_t* p)
{
	if(p->head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		node_t* q=p->head;
		node_t* r=NULL;
		while(q!=NULL)
		{
			r=q;
			printf("Deleted node_t has info %d\n",(q->info));
			q=q->link;
			free(r);
		}
		p->head=NULL;
		r=NULL;
	}
}

void insert(list_t* p,int ele)
{
	node_t* temp=create_node(ele);
	if(temp==NULL)
	{
		return;
	}
	if(p->head==NULL)
	{
		temp->link=p->head;
		p->head=temp;
	}
	else
	{
		node_t* q=p->head;
		while(q->link!=NULL)
		{
			q=q->link;
		}
		q->link=temp;
		temp->link=NULL;
	}
}

void swap_node(list_t *p,int nd1,int nd2)
{
	if(p->head==NULL)
	{
		printf("Nothing to swap");
	}
	else
	{
		if(nd1==nd2)
		{
			return;
		}
		else
		{
			//Searching for nd1 in the linked list 
			node_t* prev_nd1=NULL;
			node_t* pres_nd1=p->head;
			while(pres_nd1 && pres_nd1->info!=nd1)
			{
				prev_nd1=pres_nd1;
				pres_nd1=pres_nd1->link;
			}
			
			//Searching for nd2 in the linked list
			node_t* prev_nd2=NULL;
			node_t* pres_nd2=p->head;
			while(pres_nd2 && pres_nd2->info!=nd2)
			{
				prev_nd2=pres_nd2;
				pres_nd2=pres_nd2->link;
			}
			if(pres_nd1==NULL || pres_nd2==NULL)
			{
				return;
			}
			
			//If nd1 is not the head of the linked list 
			if(prev_nd1!=NULL)
			{
				prev_nd1->link=pres_nd2;
			}
			else //Making nd2 the new head of the linked list
			{
				p->head=pres_nd2;
			}
			
			//If nd2 is not the head of the linked list
			if(prev_nd2!=NULL)
			{
				prev_nd2->link=pres_nd1;
			}
			else //Making nd1 as the new head of the linked list
			{
				p->head=pres_nd1;
			}
			//Swaping the pointers
			node_t* temp=pres_nd2->link;
			pres_nd2->link=pres_nd1->link;
			pres_nd1->link=temp;
		}
	}
}

int count_node(list_t* p)
{
	int count=0;
	if(p->head==NULL)
	{
		count=0;
	}
	else
	{
		node_t* pres=p->head;
		while(pres!=NULL)
		{
			count++;
			pres=pres->link;
		}
		return count;
	}
}


