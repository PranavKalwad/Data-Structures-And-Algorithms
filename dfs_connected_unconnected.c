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


void dfs(int src,int a[max][max],int visited[max],int n)
{
    printf("%d\t",src);
    visited[src]=1;
    for(int i=0;i<n;i++)
    {
        if(a[src][i] && !visited[i])
        {
            dfs(i,a,visited,n);
        }
    }
}

int main()
{
    int n,a[max][max]={0},visited[max]={0};
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    read_graph(a,n);
    int src=0; //This is the first vertex of the graph.
    dfs(src,a,visited,n);
    int i;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            break;
        }
    }
    if(i<n) //Graph not fully traversed
    {
        printf("Unconnected");
    }
    else
    {
        printf("Connected");
    }
    return 0;
}