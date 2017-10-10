#include <stdio.h>
#include <conio.h>

int main()
{
    int a[10],c=0,i,j,n,min=0,max=9,mid,t;
    printf("Enter 10 numbers into the array:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("After sorting\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<9-i; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    
    printf("\n\n");
    for(i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\nNow ENter the Number you want to search:\n");
    scanf("%d",&n);
    
	//binary search
	while(min<=max)
	{
		mid=(min+max)/2;
		if(a[mid]==n)
		{
			c=1;
			break;
		}
		else if(n>a[mid])
		{
			min=mid+1;
		}
		else if(n<a[mid])
		{
			max=mid-1;
		}
	}
	
    if (c==0)
    {
        printf("\n\nSorry!! Number was not found in the array\n\n");
    }
    else
    {
        printf("\n\n The Number  was found on the POSITION %d\n\n",mid+1);
    }
    return 0;
}