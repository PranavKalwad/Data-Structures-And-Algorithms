#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int key;
	struct node *llink;
	struct node *rlink;
} node_t;

typedef struct dlist
{
	node_t *head;
	node_t tail;
} dlist_t;

void init(dlist_t *p);
void disp(dlist_t *p);
void insert_front(dlist_t *p, int key);
void insert_end(dlist_t *p, int key);
node_t *create_node(int key);
void del_front(dlist_t *p);
void del_end(dlist_t *p);
void del_after(dlist_t *p, int key, int info);
void insert_after(dlist_t *p, int info, int key);
int main()
{
	dlist_t l;
	init(&l);
	int choice, ele, info;
	do
	{
		printf("1.Insert begining\t2.Display\t3.End insertion\t4.Delete Front\t5.Delete end\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the element:\n");
			scanf("%d", &ele);
			insert_front(&l, ele);
			break;
		case 2:
			printf("The list is:\n");
			disp(&l);
			break;
		case 3:
			printf("Enter the element:\n");
			scanf("%d", &ele);
			insert_end(&l, ele);
			break;
		case 4:
			del_front(&l);
			break;
		case 5:
			del_end(&l);
			break;
		default:
			exit(0);
		}
	} while (choice < 6);
	return 0;
}

void init(dlist_t *p)
{
	p->head = NULL;
}
void disp(dlist_t *p)
{
	if (p->head == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		node_t *pres = p->head;
		while (pres != NULL)
		{
			printf("%d\t", pres->key);
			pres = pres->rlink;
		}
		printf("\n");
	}
}

void insert_front(dlist_t *p, int key)
{
	node_t *temp = create_node(key);
	if (p->head == NULL)
	{
		p->head = temp;
	}
	else
	{
		p->head->llink = temp;
		temp->rlink = p->head;
		p->head = temp;
	}
}
void insert_end(dlist_t *p, int key)
{
	node_t *temp = create_node(key);
	if (p->head == NULL)
	{
		p->head = temp;
	}
	else
	{
		node_t *pres = p->head;
		while (pres->rlink != NULL)
		{
			pres = pres->rlink;
		}
		pres->rlink = temp;
		temp->llink = pres;
	}
}
node_t *create_node(int key)
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	temp->key = key;
	temp->llink = NULL;
	temp->rlink = NULL;
}

void del_front(dlist_t *p)
{
	if (p->head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		node_t *temp = p->head;
		p->head = temp->rlink;
		p->head->llink = NULL;
		temp->rlink = NULL;
		temp->llink = NULL;
		free(temp);
		temp = NULL;
	}
}

void del_end(dlist_t *p)
{
	if (p->head == NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		node_t *temp = p->head;
		while (temp->rlink != NULL)
		{
			temp = temp->rlink;
		}
		temp->llink->rlink = temp->rlink;
		temp->rlink = NULL;
		temp->llink = NULL;
		free(temp);
		temp = NULL;
	}
}
