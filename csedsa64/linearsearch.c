#include<stdio.h>
#include<stdlib.h>
void linear(int a[],int,int);
void binary(int a[], int n, int item);

main()
{
	int a[20];
	int d,loc,item,k,i,n,ch;
	printf("ENter Index of the Array:\n");
	scanf("%d",&n);
	printf("Enter the Elemets:\n");
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("1.Linear Search\n2.Binary Search\nEnter the type of search:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the element to search:\n");
			scanf("%d",&item);
			linear(a,n,item);
			break;
		case 2: printf("Enter the element to search:\n");
			scanf("%d",&item);
			binary(a,n,item);
			break;
	}
			
}

void linear(int a[],int n,int item)
{
	int k,loc;
	k=1;
	loc=0;
	while(loc==0 && k<=n)
	{
		if(item==a[k])
		{
			loc=k;	
			
		}
		k=k+1;
	}
	if(loc==0)
		printf("Search is UNSUCCESFUL");
	else
		printf("Search is succesful and the location is %d",loc);
}

void binary(int a[], int n, int item)
{
	int beg=1;
	int end=n;
	int mid,loc;
	mid=((beg+end)/2);
	while(beg<=end && a[mid]!=item)	
	{
		if(item<a[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
		mid=((beg+end)/2);
	}
	if(a[mid]==item)
	{
		loc=mid;
		printf("Search is succesful and Item is found at location %d",loc);
	}
	else
	{	loc=0;
		printf("Seach was UNSUCCESFUL");
	}
}

