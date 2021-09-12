typedef struct node
{
	int key;
	struct node* link;
}node_t;

typedef struct list
{
	node_t* head;
}list_t;

//We pass to all the functions the pointer to head.
void init(list_t *p);
void deinit(list_t *p);
void disp(const list_t *p);
void ordered_list(list_t *p,int key);
node_t* CreateNode(int ele);
void del_key(list_t *p,int key);