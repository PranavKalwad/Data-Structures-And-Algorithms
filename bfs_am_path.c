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


int bfs(int src,int dest,int a[max][max],int visited[max],int n)
{
    int queue[max],f=0,r=-1,i,j;
    queue[++r]=src;
    visited[src]=1;
    int x=queue[f++];
    if(x==dest)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(a[x][i] && !visited[i])
        {
            queue[++r]=i;
            visited[i]=1;    
        }
    }
    return 0;
}

int main()
{
    int n,a[max][max]={0},visited[max]={0};
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    read_graph(a,n);
    int src=0; //This is the first vertex of the graph.
    printf("Enter the source and destination vertices\n");
    int dest;
    scanf("%d\t%d",&src,&dest);
    int res=bfs(src,dest,a,visited,n);
    if(res==1)
    {
        printf("Path exists");
    }
    else
    {
        printf("Path doesnt exists");
    }
    return 0;
}