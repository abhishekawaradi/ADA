#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void selection(int a[],int n)
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void randominput(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%10000;
}

int main()
{
    FILE *fp,*gp;
    struct timeval tv;
    double start,end;
    int a[100000],i,n,choice;

    while(1)
    {
        printf("\n1.Plot Graph\n2.Selection Sort\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                fp=fopen("SelectPlot.dat","w");

                for(n=5000;n<=50000;n+=5000)
                {
                    randominput(a,n);

                    gettimeofday(&tv,NULL);
                    start=tv.tv_sec+(tv.tv_usec/1000000.0);

                    selection(a,n);

                    gettimeofday(&tv,NULL);
                    end=tv.tv_sec+(tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",n,end-start);
                }

                fclose(fp);

                gp=fopen("SelectPlot.gpl","w");

                fprintf(gp,"set terminal png\n");
                fprintf(gp,"set title 'Selection Sort Time Complexity'\n");
                fprintf(gp,"set xlabel 'Input Size'\n");
                fprintf(gp,"set ylabel 'Time Taken'\n");
                fprintf(gp,"set grid\n");
                fprintf(gp,"set output 'SelectPlot.png'\n");
                fprintf(gp,"plot 'SelectPlot.dat' with lines title 'Selection Sort'\n");

                fclose(gp);

                printf("Graph data generated.\nRun: gnuplot SelectPlot.gpl\n");
                break;

            case 2:
                printf("Enter number of elements: ");
                scanf("%d",&n);

                randominput(a,n);

                printf("\nUnsorted Array:\n");
                for(i=0;i<n;i++)
                    printf("%d ",a[i]);

                selection(a,n);

                printf("\n\nSorted Array:\n");
                for(i=0;i<n;i++)
                    printf("%d ",a[i]);

                printf("\n");
                break;

            case 3:
                exit(0);
        }
    }
}
