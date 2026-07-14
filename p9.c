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
void selection(int a[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
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
    selection(a,n);
    gettimeofday(&tv,NULL);
    end=tv.tv_sec+tv.tv_usec/1000000.0;
    printf("Time Taken = %.6lf seconds\n",end-start);
    return 0;
}


import matplotlib.pyplot as plt
n_values = [6000,7000,8000,9000,10000]
time_taken = [0.025524,0.033522,0.040417,0.048598,0.064520]
plt.plot(n_values, time_taken, marker='o')
plt.title("Selection Sort Time Complexity")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()
