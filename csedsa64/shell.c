#include<stdio.h>
#include<math.h>

void display(int [],int );
void shellsort(int [], int );


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
        printf("Before SOrting:\n");
        display(a,n);
        shellsort(a,n);
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

void shellsort(int a[], int n)
{
	int gap,i=1,swap=1,temp;
	gap=n/2;
	

	while (gap>0)
	{
		printf("gap=%d",gap);
		i=1;
		swap=1;
		while(swap==1)
		{
			//i=0;
			swap=0;
		
			while (i<=(n-gap))
			{
				printf("%d ",i);
				if(a[i]>=a[i+gap])
				{
					temp=a[i];
					a[i]=a[i+gap];
					a[i+gap]=temp;
					swap=1;
					i++;

				}

				else{i++;
				//	break;
					
					}	

					
			}
			
			
		}
		gap=ceil(gap/2);
	}
}
