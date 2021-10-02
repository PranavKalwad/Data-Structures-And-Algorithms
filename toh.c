#include<stdio.h>
void th(int n, char src, char dest, char aux);
int main()
{
	printf("enter n\n");
	int n;
	scanf("%d",&n);

	th(n,'A','B','C');
	return 0;
}
void th(int n, char src, char dest, char aux)
{
	if(n==1)
	{
		printf("Move 1 from %c to %c\n",src,dest);
		return;
	}
	th(n-1,src,aux,dest);
	printf("move %d from %c to %c\n",n,src, dest );
	th(n-1,aux,dest,src);
}

