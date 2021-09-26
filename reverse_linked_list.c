typedef struct node
{
    int info;
    struct node* link;
}node_t; 

typedef struct llist
{
    node_t* head;
}llist_t;

node_t* create_node(int ele);
void init(llist_t* p);
void insert_beg(llist_t* p,int ele);
void reverse(llist_t* p);
void display(llist_t* p);
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int choice,ele;
    llist_t t;
    init(&t);
    do
    {
        printf("1.Insert in the begining\t2.Reverse the list\t3.display\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter the element to be inserted:\n");
                    scanf("%d",&ele);
                    insert_beg(&t,ele);
                    break;
            case 2:
                    reverse(&t);
                    break;
            case 3:
                    printf("The list is:\n");
                    display(&t);
                    break;

        }
        
    } while (choice<4);
    
    return 0;
}

void init(llist_t* p)
{
    p->head=NULL;
}
node_t* create_node(int ele)
{
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    temp->info=ele;
    temp->link=NULL;
    return temp;
}
void insert_beg(llist_t* p,int ele)
{
    node_t* temp=create_node(ele);
	if(temp==NULL)
		return;
	temp->link=p->head;
	p->head=temp;
}
void reverse(llist_t* p)
{
    if(p->head==NULL)
    {
        printf("List is empty");
    }
    else if(p->head->link==NULL)
    {
        printf("The list is:\n");
        display(p);
    }
    else
    {
        node_t* pres=p->head;
        node_t* prev=NULL;
        node_t* next=NULL;
        while(pres!=NULL)
        {
            //Store the next link.
            next=pres->link;
            //Reversing the current link
            pres->link=prev;
            //Moving the pointers ahead by 1 position
            prev=pres;
            pres=next;
        }
        //Changing the head pointer
         p->head=prev; 
    }
}


void display(llist_t* p)
{
    if(p->head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node_t* pres=p->head;
        while(pres!=NULL)
        {
            printf("%d\t",pres->info);
            pres=pres->link;
        }
        printf("\n");
    }
}