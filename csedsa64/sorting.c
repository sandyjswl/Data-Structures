#include<stdio.h>
#include<stdlib.h>
void bubble(int a[],int);
void display(int a[],int n);
void insertion(int a[], int n);


main()
{
        int a[20];
        int i,n,ch;
        printf("ENter Index of the Array:\n");
        scanf("%d",&n);
        printf("Enter the Elemets:\n");
        for(i=1; i<=n; i++)
        {
                scanf("%d",&a[i]);
        }
	while(1)
       	{
	 printf("\n1.Bubble Sorting\n2.DIsplay\n3.Insertion Sort\nEnter CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
	{
		case 1:
			bubble(a,n);
			break;
		case 2:
			display(a,n);
			break;
		case 3:
			insertion(a,n);
			break;
	}
	}
}
void bubble(int a[], int n)
{
	
	int swap=1;
	int i=1,j,temp;
	while(swap==1 && i<n)
	{
		swap=0;
		j=0;
		while( j<n-i)
		{
			if(a[j]>a[j+1])	
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
			j=j+1;
		}
		i=i+1;	
	}
}	
void display(int a[],int n)
{
	int i;
	printf("After Sorting the ARRAY is:\n");
	for(i=1; i<=n; i++)
	{
		printf("%d  ",a[i]);
	}			
}
void insertion(int a[], int n)
{
	int i,j,temp;
	for(i=1; i<=n; i++)
	{
		temp=a[i];
		for(j=i-1; j>=0  && temp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}	
