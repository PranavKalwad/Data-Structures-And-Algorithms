#include<stdio.h>
#include<stdlib.h>
#include "ordered_list.h"
void init(list_t *p)
{
	p->head=NULL;
}
void deinit(list_t* p)
{
	if(p->head==NULL)
	{
		printf("List is alread empty!");
	}
	else
	{
		node_t *pres=p->head;
		node_t *prev=NULL;
		while(pres!=NULL)
		{
			prev=pres;
			pres=pres->link;
			free(prev);
		}
		p->head=NULL;
		prev=NULL;
	}
}
void disp(const list_t *p)
{
	if(p->head==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		node_t* pres=p->head;
		while(pres!=NULL)
		{
			printf("%d\t",pres->key);
			pres=pres->link;
		}
		printf("\n");
	}
}


node_t* Createnode(int ele)
{
	node_t* temp=malloc(sizeof(node_t));
	temp->key=ele;
	temp->link=NULL;
	return temp;
}

void ordered_list(list_t *p,int key)
{
	node_t* temp=Createnode(key);
	node_t *pres=p->head;
	node_t *prev=NULL;
	if(p->head==NULL) //Inserting the first node of the list.
	{
		p->head=temp;
	}
	else
	{
		while(pres!=NULL && pres->key<temp->key) //Traversing the linked list.
		{
			prev=pres;
			pres=pres->link;
		}
		if(prev==NULL) //Insertion in the begining
		{
			temp->link=pres;
			p->head=temp;
		}
		else //Insertion at the middle or the end
		{
			temp->link=pres;
			prev->link=temp;
			
		}
	}	
}



void del_key(list_t *p,int key)
{
	node_t *pres=p->head;
	node_t *prev=NULL;
	if(p->head==NULL) //empty list
	{
		printf("Empty list\n");
	}
	else if(pres->key==key) //single node
	{
		p->head=pres->link;
		free(pres);
		pres=NULL;
	}
	else
	{
		while(pres!=NULL && pres->key!=key) //traverse thru
		{
			prev=pres;
			pres=pres->link;
		}
		if(pres!=NULL) //key matched
		{
			prev->link=pres->link;
			free(pres);
			pres=NULL;
		
		}
		else
		{
			printf("Key not found\n");
		}
	}
}









