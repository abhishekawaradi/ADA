#include<stdio.h>
#define MAX 50

int p[MAX],w[MAX],x[MAX];
double maxprofit;
int n,m,i;

void greedyKnapsack(int n,int w[],int p[],int m)
{
    double ratio[MAX];
    int j;

    for(i=0;i<n;i++)
        ratio[i]=(double)p[i]/w[i];

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                double t=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=t;

                int t2=w[i];
                w[i]=w[j];
                w[j]=t2;

                t2=p[i];
                p[i]=p[j];
                p[j]=t2;
            }
        }
    }

    int currentWeight=0;
    maxprofit=0.0;

    for(i=0;i<n;i++)
    {
        if(currentWeight+w[i]<=m)
        {
            x[i]=1;
            currentWeight+=w[i];
            maxprofit+=p[i];
        }
        else
        {
            x[i]=(m-currentWeight)/(double)w[i];
            maxprofit+=x[i]*p[i];
            break;
        }
    }

    printf("Optimal profit = %.1f\n",maxprofit);
    printf("Solution vector: ");

    for(i=0;i<n;i++)
        printf("%d ",x[i]);
}

int main()
{
    printf("Enter number of objects: ");
    scanf("%d",&n);

    printf("Enter weights: ");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("Enter profits: ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("Enter capacity: ");
    scanf("%d",&m);

    greedyKnapsack(n,w,p,m);

    return 0;
}
