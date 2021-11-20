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

int dfs(int s,int a[max][max],int visited[max],int n,int p)
{
    visited[s]=1;
    for(int i=0;i<n;i++)
    {
        if(a[s][i])
        {
            if(i!=p)
            {
                if(visited[s])
                {
                    return 1;
                }
                int k=dfs(i,a,visited,n,s); //Parent is updated here.
                if(k)
                    return 0;
            }
        }
    }
    return 0;
}

int main()
{
    int n,a[max][max],visited[max],p=-1; //Initally the parent node of the root node is set to -1.
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    read_graph(a,n);
    int res=dfs(0,a,visited,n,p);
    if(res)
    {
        printf("cycle is present\n");
    }
    else
    {
        printf("Cycle is not present\n");
    }
    return 0;
}