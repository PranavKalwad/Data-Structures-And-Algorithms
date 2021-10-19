#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}NODE;

typedef struct bst
{
    NODE* root;
}BST;

void init(BST* pbst)
{
    pbst->root=NULL;
}

NODE* getNode(int ele)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void insert(BST* pbst,int ele)
{
    NODE* temp=getNode(ele);
    NODE* p,*befp;
    if(pbst->root==NULL) //When the binary search tree is empty.
    {
        pbst->root=temp;
    }
    else // When there are nodes present in the tree
    {
        p=pbst->root;
        befp=NULL;
        while(p!=NULL)
        {
            if(p->data>temp->data) //We need to go to the left of the node when the data of the node to be inserted is less than the data that is present in the node pointing to p.
            {
                befp=p;
                p=p->left;
            }
            else //We need to go to the right of the node when the data of the node to be inserted is greater than the data that is preset in the node pointing to p.
            {
                befp=p;
                p=p->right;
            }
        }
        if(befp->data>temp->data) //We insert the node to a tree only after we have come out of the while loop when the pointer p points to null.
        {
            befp->left=temp;
        }
        else
        {
            befp->right=temp;
        }
    }
}


NODE* recursive_insert(NODE* ph,int x)
{
    NODE* temp=getNode(x);
    NODE* p,*befp;
    if(ph==NULL)
    {
        return temp;
    }
    else
    {
        if(ph->data>x)
        {
            ph->left=recursive_insert(ph->left,x);
        }
        else
        {
            ph->right=recursive_insert(ph->right,x);
        }
    }
    return ph;
}


void inorder(NODE* ph) //Passing a pointer to the node and not a pointer to the root.
{
    NODE* p=ph;
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->data); 
        inorder(p->right);
    }
}


void preorder(NODE* ph)
{
    NODE* p=ph;
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(NODE* ph)
{
    NODE* p=ph;
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->data);
    }
}

int recursive_search(NODE* ph,int ele)
{
    NODE* p=ph;
    if(p==NULL)
    {
        return  0;  
    }
    if(p->data==ele)
    {
        return 1;
    }
    if(p->data>ele)
    {
        return (recursive_search(p->left,ele));
    }
    else
    {
        return (recursive_search(p->right,ele));
    }
}


int count_node(NODE* ph)
{
    NODE* p=ph;
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        int lc=count_node(p->left);
        int rc=count_node(p->right);
        return lc+rc+1;
    }

}

int max(NODE* ph)
{
    if(ph->right==NULL)
    {
        return (ph->data);
    }
    else
    {
        max(ph->right);
    }
}


int min(NODE* ph)
{
    if(ph->left==NULL)
    {
        return(ph->data);
    }
    else
    {
        min(ph->left);
    }
}


NODE* delete(NODE* r,int ele)
{
    NODE* curr,*prev,*p,*q,*temp;
    curr=r;
    prev=NULL;
    while((curr!=NULL) && (curr->data!=ele)) //Traversing the tree to reach till the node that has to be deleted.
    {
        prev=curr;
        if(ele<curr->data)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
        if(curr==NULL)
        {
            printf("Number not found");
            return r;
        }
        if((curr->left==NULL)||(curr->right==NULL)) //Zero or one node condition.
        {
            if((curr->left==NULL))
            {
                q=curr->right;
            }
            else
            {
                q=curr->left;
            }
            if(prev==NULL) //root node with one child
            {
                free(curr);
                return q;
            }
            if(curr==prev->left)
            {
                prev->left=q;
            }
            else
            {
                prev->right=q;
            }
            free(curr);
        }

        else
        {
            p=NULL;
            temp=curr->right;
            while(temp->left!=NULL)
		{
			p = temp;
			temp = temp->left;
		}
		curr->data = temp->data;
		if(p!=NULL)
		{
			p->left = temp->right;
		}
		else
		{
			curr->right = temp->right;
		}
		free(temp);
        }
    return r;
}    


int main()
{
    BST pbst;
	init(&pbst);
	int ch,ele, x,pos;
	do
	{
		printf("\nenter a choice: 1-insert 0- rinsserst  2- inorder 3- preorder 4-postorder 5- search a key 6- No. of nodes 7- Maximum element 8- Minimum element 9-deletion 10- exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1: printf("enter an element\n");
			scanf("%d", &ele);
			insert(&pbst, ele);
			break;
		case 0: printf("enter an element\n");
			scanf("%d", &ele);
			recursive_insert(pbst.root, ele);
			break;
		case 2: inorder(pbst.root); 
			break;
		case 3: preorder(pbst.root);
			break;
		case 4: postorder(pbst.root);
			break;
		case 5: printf("enter the key to be searched\n");
			scanf("%d", &x);
			pos = recursive_search(pbst.root, x);
			if (pos == 0)
				printf("Key not found\n");
			else
				printf("key found \n");
			break;
		case 6: printf("No. of nodes = %d\n", count_node(pbst.root));
			break;
		case 7: printf("Maximum element = %d\n", max(pbst.root));
			break;
		case 8: printf("Minimum element = %d\n", min(pbst.root));
			break;
		case 9: printf("enter the element to be deleted\n");
			scanf("%d", &ele);
			pbst.root = delete(pbst.root, ele);
			break;
		}
	}while(ch!=10);
    return 0;
}