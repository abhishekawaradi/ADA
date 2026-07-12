#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
void randominput(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%10000;
}
void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,b[100000];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int a[100000],size[20];
    int t,n,i;
    struct timeval tv;
    double start,end;
    srand(time(NULL));
    printf("Enter number of test cases: ");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        do
        {
            printf("Enter number of elements %d (>5000): ",i+1);
            scanf("%d",&size[i]);
            if(size[i]<=5000)
                printf("Please enter n greater than 5000.\n");
        }while(size[i]<=5000);
    }
    printf(" No. of Elements\tTime Taken(sec)\n");
    for(i=0;i<t;i++)
    {
        n=size[i];
        randominput(a,n);
        gettimeofday(&tv,NULL);
        start=tv.tv_sec+tv.tv_usec/1000000.0;
        mergesort(a,0,n-1);
        gettimeofday(&tv,NULL);
        end=tv.tv_sec+tv.tv_usec/1000000.0;
        printf("%10d\t\t%.6lf\n",n,end-start);
    }
    return 0;
}

import matplotlib.pyplot as plt
n_values = [6000,7000,8000,9000,10000]
time_taken = [0.001352,0.001571,0.001809,0.002036,0.002261]
plt.plot(n_values, time_taken, marker='o')
plt.title("Merge Sort Time Complexity")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()
