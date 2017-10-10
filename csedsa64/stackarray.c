#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stack
{
	int top;
	int a[MAX];
} stack;	
int stack_empty(stack *);
int stack_full(stack *);	
void push(stack *,int); 
void  pop(stack *);
void display(stack *);
main()
{
	int ch,item;
	stack s,*ptr;
	ptr=&s;
	ptr->top=-1;
	while(1)
	{

		printf("\n1.Push\n2.Pop\n3.Display\n0.Exit\nSelect a choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("Enter Number to Push\n");
				scanf("%d",&item);
				push(ptr,item);
				break;
			case 2:
				pop(ptr);
				break;
			case 3:
				display(ptr);
				break;	
			case 0:
				exit(0);
		}
	}
}
 int stack_empty(stack *ptr)
{
	if (ptr->top==-1)
		return 1;
	else 
		return 0;
}

int stack_full(stack *ptr)
{
	if (ptr->top==MAX-1)
		return 1;
	else
		return 0;
}
void push(stack *ptr,int item)
{
	if(stack_full(ptr))
	{
		printf("Overflow");
	}
	else
	{
		(ptr->top)++;
		ptr->a[ptr->top]=item;
	}
}	
void  pop(stack *ptr)
{
	int item;	
	if(stack_empty(ptr))
		printf("Underflow");
	else
	{
		item=ptr->a[ptr->top];
		ptr->top=ptr->top-1;
		printf("Item popped %d",item);
	}
	
}	
void display(stack *ptr)
{
	int i;
	for (i=ptr->top;i>=0;i--)
		printf("\n%d\n",ptr->a[i]);
}				
