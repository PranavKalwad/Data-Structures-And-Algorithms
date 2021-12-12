#include<stdio.h>
#include<stdlib.h>
typedef struct trienode
{
    struct trienode * child[26];
    int EOW;
}NODE;

typedef struct triestack
{
    NODE* n;
    int index;
}STACK;

char word[100];
STACK s[100];
int length;
int top;

NODE* getNode()
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    for(int i=0;i<26;i++)
    {
        temp->child[i]=NULL;
    }
    temp->EOW=0;
    return temp;
}


void insert(NODE* root,char* key)
{
    NODE* curr;
    int i,index;
    curr=root;
    for(int i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index]=getNode();
        }
        curr=curr->child[index];
    }
    curr->EOW=1;
}

void display(NODE* curr)
{
    int i,j;
    for(i=0;i<26;i++)
    {
        if(curr->child[i]!=NULL)
        {
            word[length++]=i + 'a'; 
            if(curr->child[i]->EOW == 1)
            {
                printf("\n");
                for(j=0;j<length;j++)
                    printf("%c",word[j]);
            }
        display(curr->child[i]);
        }
    }
    length--; //This done because we have to display the words starting with all the letters.
    return;
}


void display_length(NODE* curr, int count)
{
    int i,j;
    for(i=0;i<26;i++)
    {
        if(curr->child[i]!=NULL)
        {
            word[length++]=i+'a'; 
            if((curr->child[i]->EOW==1) && (length==count))
            {
                printf("\n");
                for(j=0;j<length;j++)
                    printf("%c",word[j]);
            }
        display_length(curr->child[i],count);
        }
    }
    length--; //This done because we have to display the words starting with all the letters.
    return;
}


void display_prefix(NODE* root,char* key)
{
    NODE* curr=root;
    int i,j,index;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i] - 'a';
        if(curr->child[index] != NULL)
        {
            word[length++]=index + 'a';
            curr=curr->child[index];
        }
        else
            return;
    }
    if(curr->EOW == 1)
    {
        printf("\n");
        for(int j=0;j<length;j++)
        {
            printf("%c",word[j]);
        }
    }
    display(curr);
}


int search(NODE*root,char* key)
{
    NODE* curr = root;
    int i,index;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(curr->child[index] == NULL)
            return 0;
        else
            curr=curr->child[index];
    }
    if(curr->EOW == 1)
    {
        return 1;
    }
}


void push(NODE* x,int k)
{
    top++;
    s[top].n=x;
    s[top].index=k;
}

STACK pop()
{
    STACK temp;
    temp=s[top];
    top--;
    return temp;
}


int check(NODE* root)
{
    NODE* curr = root;
    int i,count=0;
    for(i=0;i<26;i++)
    {
        if(curr->child[i] != NULL)
            count++;
    }
    return count;
}

void delete(NODE* root,char* key)
{
    int i,index,k;
    STACK x;
    NODE* curr = root;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i]-'a';
        if(curr->child[index] == NULL)
        {
            printf("Word not found");
            return;
        }
        push(curr,index);
        curr=curr->child[index];
    }
    curr->EOW=0;
    push(curr,-1); //When we push the child node we keep the index as -1.

    while(1)
    {
        x=pop();
        if(x.index!=-1)
            x.n->child[x.index] = NULL;
        if(x.n==root)
            break;
        k=check(x.n);
        if(k>=1 || x.n->EOW == 1)
            break;
        else
            free(x.n);
            x.n=NULL;
    }
}   


int main()
{
    char key[100];
	NODE* root = getNode();
	int ch;
while(1)
{	
	printf("\nenter 1- insert, 2- display, 3-search, 4- display length 5-display_prefix, 6-delete\n");
	scanf("%d", &ch);	
	switch(ch)
	{
		case 1: printf("enter word\n");
			scanf("%s", key);
			insert(root,key);
			break;
		case 2: length =0 ;
			display(root);
			break;
		case 3: printf("\nenter word\n");
			scanf("%s", key);
			int r = search(root,key);
			if(r==1)
				printf("present\n");
			else
				printf("Not present\n");
			break;
		case 4: length =0 ;
			printf("enter the length of word to be displayed\n");
			int count;
			scanf("%d", &count);
			display_length(root, count);
			break;	
		case 5: length =0 ;
			printf("enter the word to be checked for\n");
			
			scanf("%s",key);
			display_prefix(root, key);
			break;	
		case 6: length =0 ;
			printf("enter the word to be deleted\n");
			
			scanf("%s",key);
			delete(root, key);
			break;	
	}
}
    return 0;
}