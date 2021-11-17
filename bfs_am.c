#include<stdio.h>
#define max 10

void read_graph(int a[max][max],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void bfs(int a[max][max],int visited[max],int queue[max],int n,int f, int r)
{
    int x;
    while(f<=r) //till the queue is not empty we enter the while loop
    {
        x=queue[f++]; //First the value of queue[f] is stored in x and then f is incremented.
        printf("%d\t",x);
        //visited[x]=1; //Of no use.
        for(int i=0;i<n;i++)
        {
            if(a[x][i] && !visited[i])
            {
                queue[++r]=i;
                visited[i]=1;

            }
        }
    }
}

int main()
{
    int a[max][max]={0},visited[max]={0},queue[max],f=0,r=-1,n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    read_graph(a,n);
    queue[++r]=0; //first element of the queue is 0 vertex of the graph.
    visited[0]=1;
    bfs(a,visited,queue,n,f,r);
    return 0;
}