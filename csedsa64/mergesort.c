#include<stdio.h>
#include<stdlib.h>

void display(int a[],int );
void mergesort(int a[], int, int);
void merge(int a[],int ,int ,int );


main()
{
        int a[20];
        int i,n,ch;
	int p=1;
        printf("ENter Index of the Array:\n");
        scanf("%d",&n);
        printf("Enter the Elemets:\n");
        for(i=1; i<=n; i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Before SOrting:\n");
        display(a,n);
        mergesort(a,p,n);
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

void mergesort(int a[],int p, int r)
{
	
	
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q+1,r);
	}
}
void merge(int a[],int ls,int rs,int re)
{
	int k=0;
	int i=ls;
	int j=rs;
	int le=rs-1;
	int temp[20];
	while (i<=le && j<=re)
	{
		if(a[i]<=a[j])
		{
			k++;
			temp[k]=a[i];
			i++;
		}
		else
		{
			k++;
			temp[k]=a[j];
			j++;
		}
	}
	while (i<=le)
	{
			k++;
		temp[k]=a[i];
		i++;
	}
	while (j<=re)
	{
			k++;
		temp[k]=a[j];
		j++;
	}
	for(i=1; i<=k; i++)
	{
		a[ls-1+i]=temp[i];
	}
}	

