#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct cq
{
	int front,rear,a[max];
}cq;
int cq_full(cq *);
int cq_empty(cq *);
void deque(cq *);
int enque(cq *, int item);

main()	
{
	cq s,*ptr;
	ptr=&s;
	ptr->front=-1,ptr->rear=-1;
	int item,ch;
	while (1)
	{
		printf("\n0.Exit\n1.Enque\n2.Dequeue\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter number to enque:\n");
				scanf("%d",&item);
				enque(ptr,item);
				break;
			case 2:
				deque(ptr);
				break;
		}	
	}
}

int cq_full(cq *ptr)
{
	if (ptr->front==-1 && ptr->rear==max || ptr->front==ptr->rear+1)
		return 1;
	else 
		return 0;
}
int cq_empty(cq *ptr)
{
	if (ptr->front==-1 && ptr->rear==-1)
		return 1;
	else 
		return 0;		
}
int enque(cq *ptr, int item)
{
	
	if(cq_full(ptr))
		printf("Queue Overflow");
		
	else
	{
		if(cq_empty(ptr))
		{
			ptr->front=0;
			ptr->rear=0;
		}
		else if (ptr->rear==max-1)
			ptr->rear=0;
		else
			ptr->rear=ptr->rear+1;
	ptr->a[ptr->rear]=item;		
	}
}
void deque(cq *ptr)
{
	if (cq_empty(ptr))
		printf("Queue Underflow");
	else
	{
		printf("%d was deleted",ptr->a[ptr->front]);
		if(ptr->front==ptr->rear)
		{
			ptr->front=-1;
			ptr->rear=-1;
		}
		else if(ptr->front==max-1)
			ptr->front=0;
		else
			ptr->front=ptr->front+1;
	}
}	
