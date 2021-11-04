#include<stdio.h>
int main()
{
    int n,a[50],p,c,heap,v,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);                     
    for(i=n/2-1;i>=0;i--) //Starting from the child node of the root
    {
        p=i;
        v=a[i];
        heap=0;
        while(!heap && 2*p+1<=n-1) //Perform this operation until the parent node value is greater than the child node.
        {
            c=2*p+1; //The index c will be the child node.
            if(c+1<=n-1 && a[c+1]>a[c]) //The first expression is checking for the end of the tree.The 2nd expression we are comparing the two child nodes.
            {
                c=c+1; //If the right child is greater than we swap the right child with the parent.
            }
            if(v>a[c]) //Comparing the value of parent node and child node.When the parent node is greater than the child node.
            {
                heap=1; //We have do not  swap the values of the nodes.
            }
            else
            {
                a[p]=a[c];
                p=c;
            }
            a[p]=v;
        }
        printf("\n");
    }
    for(int j=0;j<n;j++)
    {
        printf("%d\t",a[j]);
    }
    return 0;
}