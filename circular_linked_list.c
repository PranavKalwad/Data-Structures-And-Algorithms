//Addition of 2 numbers using circular linked list.
typedef struct node
{
	int key;
	struct node* link;
}node_t;

typedef struct clist
{
	node_t* head;
}clist_t;

void init(clist_t *p);
void disp(const clist_t* p);
void create(clist_t *p);
void add(clist_t *p1,clist_t *p2,clist_t *p3);
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	clist_t n1;
	clist_t n2;
	clist_t n3;
	init(&n1);
	init(&n2);
	init(&n3);
	create(&n1);
	disp(&n1);
	create(&n2);
	disp(&n2);
	add(&n1,&n2,&n3);
	printf("The sum of the two numbers is:\n");
	disp(&n3);
	return 0;
}

void init(clist_t *p)
{
	p->head=NULL;
}
void disp(const clist_t* p)
{
	if(p->head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		node_t *pres=p->head->link;
		while(pres->key!=-1)
		{
			printf("%d\t",pres->key);
			pres=pres->link;
		}
		printf("\n");
	}
}

void create(clist_t* p)
{
	//Creation of Header node.
	node_t* temp=(node_t*)malloc(sizeof(node_t));
	temp->key=-1;
	temp->link=temp;
	p->head=temp;
	
	char ch;
	printf("Enter the number:\n");
	node_t *p1;
	//insertion of the node.
	while((ch=getchar())!='\n')
	{
		node_t* temp=(node_t*)malloc(sizeof(node_t));
		temp->key=ch-'0'; //Input is taken as a character.
		p1=p->head;
		temp->link=p1->link;
		p1->link=temp;
	}
}

void add(clist_t *p1,clist_t *p2,clist_t *p3)
{
	//Pointers x and y are used to traverse each and every node of the list.
	node_t *x;
	node_t *y;
	
	//Creation of Header node.
	node_t* temp=(node_t*)malloc(sizeof(node_t));
	//node_t *p1;
	temp->key=-1;
	temp->link=temp;
	p3->head=temp;
	
	x=p1->head->link;
	y=p2->head->link; 
	
	//Only applicable when two numbers have equal number of nodes.
	int carry=0;
	int sum=0;
	while(x->key!=-1 && y->key!=-1)
	{
		sum=(x->key+y->key)+carry;
		node_t* temp=(node_t*)malloc(sizeof(node_t));
		temp->key=sum%10;
		temp->link=p3->head->link;
		p3->head->link=temp;
		carry=sum/10;
		x=x->link;
		y=y->link;
	}
	//When 1st has more nodes than y then we will have to traverse till the end of 1st node.
	while(x->key!=-1)
	{
		sum=(x->key)+carry;
		node_t* temp=(node_t*)malloc(sizeof(node_t));
		temp->key=sum%10;
		temp->link=p3->head->link;
		p3->head->link=temp;
		carry=sum/10;
		x=x->link;
	}
	//When 2nd list has more nodes than x then we will have to traverse till the end of 2nd node.
	while(y->key!=-1)
	{
		sum=(y->key)+carry;
		node_t* temp=(node_t*)malloc(sizeof(node_t));
		temp->key=sum%10;
		temp->link=p3->head->link;
		p3->head->link=temp;
		carry=sum/10;
		y=y->link;
	}
	if(carry) //When carry is non zero we must create a seperate node and store it
	{
		node_t* temp=(node_t*)malloc(sizeof(node_t));
		temp->key=carry;
		temp->link=p3->head->link;
		p3->head->link=temp;
		
	}
}

