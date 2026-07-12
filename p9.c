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
    int a[100000], size[20];
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
        start=tv.tv_sec + tv.tv_usec/1000000.0;
        selection(a,n);
        gettimeofday(&tv,NULL);
        end=tv.tv_sec + tv.tv_usec/1000000.0;
        printf("%10d\t\t%.6lf\n",n,end-start);
    }
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
