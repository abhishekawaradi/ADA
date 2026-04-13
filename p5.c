#include<stdio.h>
int temp[10],k=0;
void sort(int a[10][10],int id[10],int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(id[i]==0)
        {
            id[i]=-1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1 && id[j]!=-1)
                    id[j]--;
            }
            i=0;
        }
    }
}
int main()
{
    int a[10][10],id[10],n,i,j;
    printf("Enter n value: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        id[i]=0;
    printf("Enter graph data:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                id[j]++;
        }
    sort(a,id,n);
    if(k!=n)
        printf("Topological ordering not possible");
    else
    {
        printf("Topological ordering is: ");
        for(i=1;i<=k;i++)
            printf("%d ",temp[i]);
    }
    return 0;
}
