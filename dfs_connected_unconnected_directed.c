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

void init_visited(int visited[max],int n) //This function checks whether every node is visited from a particular node.
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0; //After every iteration we make the elements of the visited array again 0.
    }
}


int dfs(int src,int a[max][max],int visited[max],int n)
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

int connected(int a[max][max],int visited[max],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        init_visited(visited,n);
        dfs(i,a,visited,n);
        for(j=0;j<n;j++)
        {
            if(!visited[j])
            {
                return 1;
            }
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
    int res=connected(a,visited,n);
    if(res) 
    {
        printf("Unconnected\n");
    }
    else
    {
        printf("connected\n");
    }
    return 0;
}
