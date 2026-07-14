#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
void randominput(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%10000;
}
void merge(int a[], int low, int mid, int high)
{
    int b[100000],i=low,j=mid+1,k=low;
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
void mergesort(int a[], int low, int high)
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
    int a[100000],n;
    struct timeval tv;
    double start,end;
    srand(time(NULL));
    do
    {
        printf("Enter number of elements (>5000): ");
        scanf("%d",&n);
    }while(n<=5000);
    randominput(a,n);
    gettimeofday(&tv,NULL);
    start=tv.tv_sec+tv.tv_usec/1000000.0;
    mergesort(a,0,n-1);
    gettimeofday(&tv,NULL);
    end=tv.tv_sec+tv.tv_usec/1000000.0;
    printf("Time Taken = %.6lf seconds\n",end-start);
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
