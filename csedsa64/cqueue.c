#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int info;
	struct queue *next;
};
struct queue *front=NULL,*rear=NULL;
void enque( int);
void deque();
main()
{

	int n,ch,item;
	while (1)
	{	printf("\n1.Enque\n2.Deque\n3.Exit\n");
		scanf("%d",&ch); 
		switch(ch)
		{
		case 1:
			printf("Enter number");
			scanf("%d",&item);
			enque(item);
			break;
		case 2:	
			deque();
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
void enque( int item)
{
	struct queue *ptr;
	ptr=(struct queue *)malloc(sizeof(struct queue));
	ptr->info=item;
	ptr->next=NULL;
	if(front==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void deque ()
{
	struct queue *ptr,*temp;
	if (front==NULL)
		printf("Queue Underflow");
	else
	{
		temp=front;
		printf("%d was deleted",temp->info);
		front=front->next;

		if (rear==temp)
			rear=NULL;
		free(temp);
	}
}
	
