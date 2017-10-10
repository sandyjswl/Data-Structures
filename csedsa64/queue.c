#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct que
{
	int a[max];
	int front,rear;
}queue;
int queue_full(queue *);
int queue_empty(queue *);
void enque(queue *, int);
int deque(queue *);

main()
{
	queue s,*ptr;
	int item,ch;
	ptr=&s;
	ptr->front=-1;
	ptr->rear=-1;
	while(1)
{

	printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter CHoice");
	scanf("%d",&ch);
	
	
		switch(ch)
		{
		case 1:
			printf(" Enter number to Enqueue\n");
			scanf("%d",&item);
			enque(ptr,item);
			break;
		case 2:
			item=deque(ptr);
			if(item!=-9990)
			printf("\nItem Deleted is %d",item);
			break;
		case 3:
			exit(0);
			break;
			
		}
	
}
}

int queue_full(queue *ptr)
{
	if(ptr->front==0 && ptr->rear==max-1)
		return 1;
	else
		return 0;
}
				
int queue_empty(queue *ptr)
{
	if (ptr->front==-1 && ptr->rear==-1)
		return 1;
	else
		return 0;
}
void enque(queue *ptr,int item)
{
	if(queue_full(ptr))
		printf("Overflow");
	else{
		if(ptr->front==-1 && ptr->rear==-1)
		{
			ptr->front=0;
			ptr->rear=0;
		}
		else
			ptr->rear=ptr->rear+1;
	ptr->a[ptr->rear]=item;		
		
	}	
}
int deque(queue *ptr)
{
	int item;
	if(queue_empty(ptr))
	{	
		printf("Underflow");
		return (-9999);
	}
	else
	{
		item=ptr->a[ptr->front];
		if (ptr->rear==ptr->front)
		{
			ptr->front=-1;
			ptr->rear=-1;
		}
		else
		ptr->front=ptr->front+1;
	return item;
	}
}

	
					
