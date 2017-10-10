#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n);
void selection(int a[], int n);


main()
{
        int a[20];
        int i,n,ch;
        printf("ENter Index of the Array:\n");
        scanf("%d",&n);
        printf("Enter the Elemets:\n");
        for(i=0; i<n; i++)
        {
                scanf("%d",&a[i]);
        }
	printf("Before SOrting:\n");
	display(a,n);
	selection(a,n);
	printf("After Sorting:\n");
	display(a,n);
}

void display(int a[],int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d   ",a[i]);
	}
}

void selection(int a[], int n)
{
	int k,j,loc,temp;
	for(k=0; k<n-1; k++)
	{
		loc=k;
		for(j=k+1; j<n; j++)
		{
			if(a[j]<a[loc])
			{
				loc=j;
			}
		}
		if(loc!=k)
		{
			temp=a[k];
			a[k]=a[loc];
			a[loc]=temp;
		}
	}
}
		
