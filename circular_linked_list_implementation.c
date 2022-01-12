#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *link;
} node_t;

typedef struct cslist
{
    node_t *head;
    node_t *tail;
} cslist_t;

void init(cslist_t *p);
node_t *create_node(int ele);
void insert_front(cslist_t *p, int ele);
void insert_last(cslist_t *p, int ele);
void display(cslist_t *p);
void destroyList(cslist_t *p);
int count_nodes(cslist_t *p);
int delete_front(cslist_t *p, int *ele);
int delete_last(cslist_t *p, int *ele);

int main()
{
    cslist_t csl;
    init(&csl);
    int ch, ele, res;
    do
    {
        printf("1.Insert at the start\t2.Insert at the end\t3.Display\t4.Destroy list\t5.Count the nodes\t6.Delete Front\t7.Delete Last.");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            insert_front(&csl, ele);
            break;

        case 2:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            insert_last(&csl, ele);
            break;

        case 3:
            printf("The list is:\n");
            display(&csl);
            break;
        case 4:
            destroyList(&csl);
            printf("List is destroyed successfully\n");
            break;
        case 5:
            res = count_nodes(&csl);
            printf("The number of nodes of the list are:%d\t", res);
            break;
        case 6:
            if (delete_front(&csl, &ele))
                printf("Deleted element is %d\n", ele);
            else
                printf("Deletion failed!");
            break;
        case 7:
            if (delete_last(&csl, &ele))
                printf("Deleted element is %d\n", ele);
            else
                printf("Deletion at the end failed\n");
            break;
        default:
            exit(0);
        }
    } while (ch < 8);
    return 0;
}

void init(cslist_t *p)
{
    p->head = NULL;
}

node_t *create_node(int ele)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->info = ele;
    temp->link = NULL;
    return temp;
}

void insert_front(cslist_t *p, int ele)
{
    node_t *temp = create_node(ele);
    if (p->head == NULL) //If the list is empty.
    {
        p->head = temp;
        temp->link = temp;
    }
    node_t *pres = p->head;
    while (pres->link != p->head)
    {
        pres = pres->link;
    }
    node_t *tail = pres;
    //When one or more nodes are present
    temp->link = p->head;
    p->head = temp;
    tail->link = temp;
}

void insert_last(cslist_t *p, int ele)
{
    node_t *temp = create_node(ele);
    if (p->head == NULL) //If the list is empty.
    {
        p->head = temp;
        temp->link = temp;
    }
    node_t *pres = p->head;
    while (pres->link != p->head)
    {
        pres = pres->link;
    }
    node_t *tail = pres;
    //One or more nodes are present
    tail->link = temp;
    temp->link = p->head;
}

void display(cslist_t *p)
{
    if (p->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node_t *pres = p->head;
        while (pres->link != p->head)
        {
            printf("%d\t", pres->info);
            pres = pres->link;
        }
        printf("%d\t", pres->info);
        printf("\n");
    }
}

void destroyList(cslist_t *p)
{
    if (p->head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        node_t *pres = p->head;
        node_t *prev = NULL;
        while (pres->link != p->head)
        {
            pres = pres->link;
        }
        node_t *tail = pres;
        while (pres->link != p->head)
        {
            prev = pres;
            pres = pres->link;
            tail->link = pres;
            p->head = pres;
            free(prev);
        }
        free(pres);
        p->head = NULL;
    }
}

int count_nodes(cslist_t *p)
{
    int count = 0;
    node_t *pres = p->head;
    if (p->head == NULL)
    {
        return count;
    }
    do
    {
        count++;
        pres = pres->link;
    } while (pres->link != p->head);
    count++;
    return count;
}

int delete_front(cslist_t *p, int *ele)
{

    if (p->head == NULL) //Empty list.
    {
        return 0;
    }
    node_t *pres = p->head;
    while (pres->link != p->head)
    {
        pres = pres->link;
    }
    node_t *tail = pres;
    if (p->head == tail->link) //Single node is present.
    {
        *ele = p->head->info;
        free(p->head);
        p->head = NULL;
        tail->link = NULL;
        return 1;
    }
    else //Multiple nodes are present.
    {
        node_t *temp = p->head;
        tail->link = p->head;
        temp->link = NULL;
        free(temp);
        p->head = p->head->link;
        return 1;
    }
}

int delete_last(cslist_t *p, int *ele)
{
    if (p->head == NULL)
        return 0;
    if (p->head == p->head->link)
    {
        *ele = p->head->info;
        free(p->head);
        p->head = NULL;
        return 1;
    }
    node_t *prev = NULL;
    node_t *pres = p->head;
    while (pres->link != p->head)
    {
        prev = pres;
        pres = pres->link;
    }
    node_t *tail = prev;
    *ele = pres->info;
    prev->link = p->head;
    free(pres);
    pres = NULL;
    return 1;
}