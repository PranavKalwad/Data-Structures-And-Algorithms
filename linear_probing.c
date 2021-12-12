#include<stdio.h>
#define size 7
#include<string.h>

typedef struct student
{
    int key;
    char name[30];
    int mark; //Indicates if record is entered by the user or not.
}NODE;

void init_table(NODE ht[size],int *n)
{
    for(int i=0;i<size;i++)
    {
        ht[i].mark = -1;
    }
    (*n)=0;
}

int insert(NODE ht[size],int key,char name[30],int *n)
{
    if(size==*n)
        return 0;
    int index = key % size;
    while(ht[index].mark != -1)
        index = (index + 1) % size;
    ht[index].key = key;
    ht[index].mark = 1;
    strcpy(ht[index].name,name);
    (*n)++;
    return 1;
}

int delete(NODE ht[size],int key,int* n)
{
    if(*n==0)
        return 0;
    int index = key % size;
    int i = 0;
    while(ht[index].key != key && i<*n)
        index = (index + 1) % size;
        if(ht[index].mark==1)
            i++;
    if(ht[index].key == key && ht[index].mark == 1)
    {
        ht[index].mark = -1;
        (*n)--;
        return 1;
    }
    return 0;
}



int search(NODE ht[size],int key,char name[30],int n)
{
    if(n==0)
        return 0;
    int index = key % size;
    int i = 0;
    while(ht[index].key != key && i<n)
        index = (index + 1) % size;
        if(ht[index].mark==1)
            i++;
    if(ht[index].key == key && ht[index].mark == 1)
    {
       strcpy(ht[index].name,name); 
        return 1;
    }
    return 0;
}


void display(NODE ht[size],int n)
{
    if(n == 0)
    {
        printf("Empty hash table");
    }
    for(int i = 0;i<size;i++)
    {
        if(ht[i].mark == 1)
        {
            printf("h[%d]: %d, %s\n",i,ht[i].key,ht[i].name);
        }
    }
}

int main()
{
    int n=0;
	NODE ht[size]; //create hashtable
	init_table(ht,&n);	
	
	int choice,key;
	char name[30];
	printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
	scanf("%d",&choice);
	do{
		switch(choice)
		{
			case 1: printf("Enter the key\n");
					scanf("%d",&key);
					printf("Enter the name\n");
					scanf("%s",name);
					if(!insert(ht,key,name,&n))
						printf("Table already full, cannot insert\n");
					break;
			case 2: printf("Enter the key\n");
					scanf("%d",&key);
					if(delete(ht,key,&n))
						printf("Record with key %d deleted\n",key);
					else
						printf("Record not found\n");
					break;
			case 3: printf("Enter the key\n");
					scanf("%d",&key);
					
					if(search(ht,key,name,n))
						printf("Record found: Details %d,%s\n",key,name);
					else
						printf("Record not found\n");
					break;
			case 4: display(ht,n);
					break;
			case 5: return 0;
		}
		printf("1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
		scanf("%d",&choice);
	}while(choice<6);
    return 0;
}