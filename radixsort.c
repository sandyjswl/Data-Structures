//Bucket Sort

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *ptr;
} node;


//finding the number of pass
int numofpass(int a[],int s)
{
	int i,nop=0,dc,n;
	for(i=0; i<s; i++)
	{
		dc=0;
		n=a[i];
		while(n>0)
		{
			dc++;
			n=n/10;
		}
		if(dc>nop)
		{
			nop=dc;
		}
	}

	return nop;
}

int extractdigit(int num,int dp)
{
	int d,i;
	for(i=1; i<=dp; i++)
	{
		d=num%10;
		num=num/10;
	}
	return d;
}



void main()
{
	int arr[10],i,s,nop,j,d,x;
	node *bucket[10],*temp,*last;


	//initilazation of bucket
	for(i=0; i<10; i++)
	{
		bucket[i]=NULL;
	}

	//enter number into array
	printf("enter total number ");
	scanf("%d",&s);

	for(i=0; i<s; i++)
	{
		scanf("%d",&arr[i]);
	}

	nop=numofpass(arr,s);
	
	//radix sort start
	for(i=1; i<=nop; i++)
	{
		for(j=0; j<s; j++)
		{
			d=extractdigit(arr[j],i);
			temp=(node*)malloc(sizeof(node));
			temp->data=arr[j];
			temp->ptr=NULL;
			if(bucket[d]==NULL)
			{
				bucket[d]=temp;
			}
			else
			{
				last=bucket[d];
				while(last->ptr!=NULL)
				{
					last=last->ptr;
				}
				last->ptr=temp;
			}
		}
		
		
		/*//testing buckets
		for(j=0;j<10;j++)
		{
			printf("\n%d=",j);
			if(bucket[j]!=NULL)
			{
				last=bucket[j];
				while(last!=NULL)
				{
					printf("%d ",last->data);
					last=last->ptr;
				}
			}
		}
		printf("\n\n");*/
		
	
		//collecting the buckets
		x=0;
		for(j=0; j<10; j++)
		{
			if(bucket[j]!=NULL)
			{
				last=bucket[j];
				while(last!=NULL)
				{	
					temp=last;
					arr[x]=last->data;
					last=last->ptr;
					free(temp);
					x++;
				}
				bucket[j]=NULL;
			}
		}
	}
	
	//printing the sorted array
	for(i=0; i<s; i++)
	{
		printf("%d ",arr[i]);
	}
}