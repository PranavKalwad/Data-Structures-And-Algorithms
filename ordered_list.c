#include<stdio.h>
#include "ordered_list.h"
#include<stdlib.h>	
int main()
{
	list_t l;
	init(&l);
	int choice,key,ele,n;
	printf("1.Insert into list\t2.Display\t3.Delete\n");
	printf("Enter your choice:\t");
	scanf("%d",&choice);
	while(choice)
	{
		switch(choice)
		{
			case 1:	
					printf("Enter the key:\n");
					scanf("%d",&key);			
					ordered_list(&l,key);
					break;
			case 2:
					disp(&l);
					break;
			case 3:
					printf("Enter the key to be deleted:\t");
					scanf("%d",&key);
					del_key(&l,key);
					break;
		}
		printf("Enter your choice:\t");
		scanf("%d",&choice);
	}
	return 0;
}