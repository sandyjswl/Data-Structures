#include <stdio.h>
#include <conio.h>
#define MAX 10
int main()
{
	int a[MAX],i,j,n,temp,min;
	printf("Enter the Number of elements:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the ELEMENTS:\n");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)   /*selection sorting*/
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			   {
			   	min=j;
			   }
		}
		if(i!=min)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
		printf("The sorted list is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
		
	}
	
	
	
		
		
		


	return 0;
}