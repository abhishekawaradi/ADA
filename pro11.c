#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void fnGenRandInput(int [], int);
void fnDispArray(int [], int);
void fnMerge(int [], int ,int ,int);
void fnMergeSort(int [], int , int);

int main()
{
    FILE *fp,*gp;
    struct timeval tv;
    double start,end;
    int a[500000],n,i,choice;

    for(;;)
    {
        printf("\n1.Plot Graph\n2.MergeSort\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                fp=fopen("MergePlot.dat","w");

                for(i=100;i<100000;i+=100)
                {
                    fnGenRandInput(a,i);

                    gettimeofday(&tv,NULL);
                    start=tv.tv_sec+(tv.tv_usec/1000000.0);

                    fnMergeSort(a,0,i-1);

                    gettimeofday(&tv,NULL);
                    end=tv.tv_sec+(tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",i,end-start);
                }

                fclose(fp);

                /* Automatically create gnuplot script */
                gp=fopen("MergePlot.gpl","w");

                fprintf(gp,"set terminal png\n");
                fprintf(gp,"set title 'Time Complexity for Merge Sort'\n");
                fprintf(gp,"set xlabel 'Input Size'\n");
                fprintf(gp,"set ylabel 'Time Taken'\n");
                fprintf(gp,"set grid\n");
                fprintf(gp,"set output 'MergePlot.png'\n");
                fprintf(gp,"plot 'MergePlot.dat' title 'Merge Sort' with lines\n");

                fclose(gp);

                printf("\nMergePlot.dat and MergePlot.gpl created\n");
                printf("Run: gnuplot MergePlot.gpl\n");
                break;

            case 2:
                printf("\nEnter number of elements: ");
                scanf("%d",&n);

                fnGenRandInput(a,n);

                printf("\nUnsorted Array\n");
                fnDispArray(a,n);

                fnMergeSort(a,0,n-1);

                printf("\nSorted Array\n");
                fnDispArray(a,n);
                break;

            case 3:
                exit(0);
        }
    }
}

void fnMerge(int a[], int low,int mid,int high)
{
    int i,j,k,b[500000];

    i=k=low;
    j=mid+1;

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

    for(i=low;i<k;i++)
        a[i]=b[i];
}

void fnMergeSort(int a[],int low,int high)
{
    int mid;

    if(low<high)
    {
        mid=(low+high)/2;
        fnMergeSort(a,low,mid);
        fnMergeSort(a,mid+1,high);
        fnMerge(a,low,mid,high);
    }
}

void fnGenRandInput(int X[], int n)
{
    int i;

    srand(time(NULL));

    for(i=0;i<n;i++)
        X[i]=rand()%10000;
}

void fnDispArray(int X[], int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%d\n",X[i]);
}
