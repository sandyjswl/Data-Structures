#include<stdio.h>

void display(int [],int );
void quicksort(int [], int , int);
int partition(int [], int , int );
void exchange(int *, int* );

main()
{
        int a[20];
        int i,n,ch;
        int p=1;
	int r=n;
        printf("ENter Index of the Array:\n");
        scanf("%d",&n);
        printf("Enter the Elemets:\n");
        for(i=1; i<=n; i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Before SOrting:\n");
        display(a,n);
        quicksort(a,p,n);
        printf("After Sorting:\n");
        display(a,n);
}

void display(int a[],int n)
{
        int i;
        for(i=1; i<=n; i++)
        {
                printf("%d   ",a[i]);
        }
}

void quicksort(int a[], int p, int r)
{
	int q;
	if (p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}		
}
int partition(int a[], int p, int r)
{
	int x;
	int i,j;
	
	x=a[r];
	i=p-1;
	for(j=p; j<=r-1; j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			exchange(&a[i],&a[j]);
		}
	}
	exchange(&a[i+1],&a[r]);
	return(i+1);
}
void exchange(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
} 	
