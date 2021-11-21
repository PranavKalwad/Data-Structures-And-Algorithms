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

int component_count(int a[max][max],int visited[max],int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i,a,visited,n);
        }
    }
    return count;
}

int main()
{
    int n,a[max][max]={0},visited[max]={0};
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    read_graph(a,n);
    int src=0; //This is the first vertex of the graph.
    dfs(src,a,visited,n);
    int compo=component_count(a,visited,n);
    printf("\nThe number of components of the graph are: %d",compo);
    return 0;
}