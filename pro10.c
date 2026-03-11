#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void fnGenRandInput(int [], int);
void fnDispArray(int [], int);
int fnPartition(int [], int , int );
void fnQuickSort(int [], int , int );
void fnSwap(int*, int*);

void fnSwap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main()
{
    FILE *fp,*gp;
    struct timeval tv;
    double start,end;
    int a[500000],n,i,choice;

    for(;;)
    {
        printf("\n1.Plot Graph\n2.QuickSort\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                fp=fopen("QuickPlot.dat","w");

                for(i=100;i<100000;i+=100)
                {
                    fnGenRandInput(a,i);

                    gettimeofday(&tv,NULL);
                    start=tv.tv_sec+(tv.tv_usec/1000000.0);

                    fnQuickSort(a,0,i-1);

                    gettimeofday(&tv,NULL);
                    end=tv.tv_sec+(tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",i,end-start);
                }

                fclose(fp);

                /* automatically create gnuplot script */
                gp=fopen("Quick.gpl","w");

                fprintf(gp,"set terminal png\n");
                fprintf(gp,"set title 'Time Complexity for Quick Sort'\n");
                fprintf(gp,"set xlabel 'Input Size'\n");
                fprintf(gp,"set ylabel 'Time Taken'\n");
                fprintf(gp,"set grid\n");
                fprintf(gp,"set output 'QuickPlot.png'\n");
                fprintf(gp,"plot 'QuickPlot.dat' title 'Quick Sort' with lines\n");

                fclose(gp);

                printf("\nQuickPlot.dat and Quick.gpl created\n");
                printf("Run: gnuplot Quick.gpl\n");
                break;

            case 2:
                printf("\nEnter number of elements: ");
                scanf("%d",&n);

                fnGenRandInput(a,n);

                printf("\nUnsorted Array\n");
                fnDispArray(a,n);

                fnQuickSort(a,0,n-1);

                printf("\nSorted Array\n");
                fnDispArray(a,n);
                break;

            case 3:
                exit(0);
        }
    }
}

int fnPartition(int a[], int l, int r)
{
    int i,j,p;

    p=a[l];
    i=l;
    j=r+1;

    do
    {
        do{i++;}while(a[i]<p);
        do{j--;}while(a[j]>p);

        fnSwap(&a[i],&a[j]);
    }while(i<j);

    fnSwap(&a[i],&a[j]);
    fnSwap(&a[l],&a[j]);

    return j;
}

void fnQuickSort(int a[], int l, int r)
{
    int s;

    if(l<r)
    {
        s=fnPartition(a,l,r);
        fnQuickSort(a,l,s-1);
        fnQuickSort(a,s+1,r);
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
