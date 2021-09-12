 //In this method we are not creating a seperate structure for head.
//We are simply making a pointer of type node in the main function.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* link;
}NODE;


//We change the return type for the DestroyList,InsertFront and GetNode because we are making changes.
NODE* DestroyList(NODE* phead);
NODE* InsertFront(NODE* phead,int);
void Display(NODE* phead); //We are not making changes inside the display function so we keep it void.
NODE* GetNode(int ele);
int main()
{
	int choice,ele;
	NODE* head=NULL; //We are creating a head pointer of type node in the main fucntion
	do{
		printf("1.Insert Front\t2.Display\t3.Delete\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the ele:\n");
					scanf("%d",&ele);
					head=InsertFront(head,ele);
					break;
			case 2:Display(head);
					break;
			
			case 3:head=DestroyList(head); //We are returning back the head pointer.
				   printf("List is deleted successfully\n");
				   break;
		}	
	}while(choice<4);
	return 0;
}

NODE* GetNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->link=NULL;
	return temp;
}

NODE* InsertFront(NODE* phead,int ele)
{
	NODE* temp=GetNode(ele);
	temp->link=phead;
	phead=temp;
	return temp;
}


NODE* DestroyList(NODE* phead)
{
	if(phead==NULL)
	{
		return 0;
	}
	else
	{
		NODE *p=phead;
		NODE *q=NULL;
		while(p!=NULL)
		{
			q=p;
			p=p->link;
			free(q);
		}
		phead=NULL;
		return phead;
	}
}


void Display(NODE* phead)
{
	if(phead==NULL)
		return;
	NODE *p=phead;
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->link;
	}
	printf("\n");
}