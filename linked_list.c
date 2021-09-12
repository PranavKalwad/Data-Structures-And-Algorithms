#include<stdio.h>
#include<stdlib.h>
//This struture stores the info and the link to the next node.

typedef struct node
{
	int info;
	struct node* next;
}NODE;

//Seperate structure to store the head of the linked list.
//Head of the linked list is the pointer of type Node to the linked list.

typedef struct llist
{
	NODE* head;
}LLIST;

//Functions of the linked lists
//In all the functions we pass a pointer to the head and access all the nodes of the linked list.Depending on the function we send other parameters.


//Initalise the list.Intializsing head to null.
void Int_List(LLIST*);
//To delete the elements of the list.
void DestroyList(LLIST*);
//Front insertion
void InsertFront(LLIST*,int);
//Insertion towards the end.
void InsertLast(LLIST*,int);
//Insertion at a specific position.
void InsertAtPos(LLIST*,int,int);
//Display the list
void Display(LLIST*);
//Deletion from the front.
void DeleteFront(LLIST*,int*);
//Deletion from the last.
void DeleteLast(LLIST*,int*);
//Deletion at a particular position.
int DeleteAtPos(LLIST*,int*,int);


int main()
{
	//Creating a variable of type LLIST.To store the head.
	LLIST lobj;
	Int_List(&lobj);
	int choice,ele,pos;
	do{
		printf("1.Insert Front 2.Insert Last 3.Insert At Pos 4.Display 5.Delete Front 6.Delete Last 7.Delete At Pos\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter an element:\n");
					scanf("%d",&ele);
					InsertFront(&lobj,ele);
					break;
			case 2: printf("Enter an element:\n");
					scanf("%d",&ele);
					InsertLast(&lobj,ele);
					break;
			case 3:
					printf("Enter element");
					scanf("%d",&ele);
					printf("Enter at pos:\n");
					scanf("%d",&pos);
					InsertAtPos(&lobj,ele,pos);
					break;
			case 4:
					Display(&lobj);
					break;
			case 5:
					DeleteFront(&lobj,&ele);
					printf("del ele from the front is %d\n",ele);break;
			case 6:
					DeleteLast(&lobj,&ele);
					printf("del ele from the last is %d\n",ele);break;
			case 7:
					printf("Enter the pos to be deleted:\n");
					scanf("%d",&pos);
					if(DeleteAtPos(&lobj,&ele,pos)==1)
						printf("ele is deleted successfully\n");
					else
						printf("List empty or invalid pos\n");break;
			
		}
	}while(choice<8);
	//DestroyList(&lobj);
	return 0;
}


void Int_List(LLIST* pl)
{
	pl->head=NULL;
}


//function to create node. 
NODE* GetNode(int ele)
{
	//Memory is allocated dynamically so this does not become a dangling pointer.
	NODE* temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
}

void InsertFront(LLIST* pl,int ele)
{
	NODE *temp=GetNode(ele);
	if(temp==NULL)
		return;
	else
		temp->next=pl->head; 
		pl->head=temp;
}
void InsertLast(LLIST* pl,int ele)
{
	NODE *temp=GetNode(ele);
	if(temp==NULL)
		return;
	//Check List empty
	if(pl->head==NULL)
	{
		pl->head=temp;
		return;
	}
	//One or more nodes
	NODE *p=pl->head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}

//Count the number of nodes
int CountNode(LLIST* pl)
{
	int count=0;
	if(pl->head==NULL)
	{
		count=0;
	}
	else
	{
		NODE *p=pl->head;
		while(p!=NULL) //If we use p->link!=NULL we will get 1 node less
		{
			count++;
			p=p->next;
		}
		return count;
	}
}

void InsertAtPos(LLIST* pl,int ele,int pos)
{
	NODE* temp=GetNode(ele);
	if(temp==NULL)
	{
		return;
	}
	int n=CountNode(pl);
	if(pos<0||pos>n)
	{
		return;
	}
	if(pos==0)
	{
		temp->next=pl->head;
		pl->head=temp;
		return;
	}
	NODE *p=pl->head;
	NODE* q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}

void Display(LLIST* pl)
{
	if(pl->head==NULL)
	{
		printf("Empty List");
	}
	else
	{
		NODE *p=pl->head;
		while(p!=NULL)
		{
			printf("%d\t",p->info);
			p=p->next;
		}
		printf("\n");
	}
}


void DestroyList(LLIST* pl)
{
	if(pl->head==NULL)
		return;
	NODE *p=pl->head;
	NODE *q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	pl->head=NULL;
	q=NULL;
}


void DeleteFront(LLIST* pl,int* pe)
{
	if(pl->head==NULL)
	{
		return;
	}
	else
	{
		NODE* p=pl->head;
		pl->head=p->next;
		*pe=p->info;
		free(p);
	}
}


void DeleteLast(LLIST* pl,int* pe)
{
	if(pl->head==NULL)
	{
		return;
	}
	else
	{
		NODE* p=pl->head,*q=NULL;
		//Single node
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		*pe=p->info;
		free(p);
	}
}

int DeleteAtPos(LLIST *pl,int* pe,int pos)
{
	if(pl->head==NULL)
	{
		return -1;
	}
	int n=CountNode(pl);
	if(pos<0||pos>n)
	{
		return -1;
	}
	NODE *p=pl->head,*q=NULL;
	if(pos==0)
	{
		pl->head=p->next;
		*pe=p->info;
		free(p);
		return 1;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	*pe=p->info;
	free(p);
	return 1;
}

