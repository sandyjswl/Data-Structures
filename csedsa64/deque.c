#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct dq
{
	int left,right,a[max];
}dq;

int right_delete(dq *ptr);
int dq_full(dq *ptr);
int dq_empty(dq *ptr);
int left_insert(dq *ptr,int item);
int left_delete(dq *ptr);
int right_insert(dq *ptr,int item);

main()
{
	dq s,*ptr;
	ptr=&s;
	ptr->left=-1,ptr->right=-1;
	int item,ch;
	while(1)
	{
		printf("\n0.Exit\n1.Insert from left\n2.Insert from right\n3.Delete from left\n4.Delete from right\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter number to insert:\n");
				scanf("%d",&item);
				left_insert(ptr,item);
				break;
			case 2:
				 printf("Enter number to insert:\n");
                                scanf("%d",&item);
                                right_insert(ptr,item);
                                break;
			case 3:
				left_delete(ptr);
				break;
			case 4:
				right_delete(ptr);
				break;
		}
	
	}
}

int dq_full(dq *ptr)
{
	if (ptr->left==0 && ptr->right==max-1 || ptr->left==ptr->right+1)
		return 1;
	else 
		return 0;
}
int dq_empty(dq *ptr)
{
	if (ptr->left==-1 && ptr->right==-1)
		return 1;
	else
		return 0;
}
int left_insert(dq *ptr,int item)
{
	if (dq_full(ptr))
		printf("Deque Overflow");
	else
	{
		if (ptr->left==-1)
		{
			ptr->left=max-1;
			ptr->right=max-1;
		}
		else if(ptr->left==0)
			ptr->left=max-1;
		else
			ptr->left=ptr->left-1;
	ptr->a[ptr->left]=item;	
	}
}
int left_delete(dq *ptr)
{
	if(dq_empty(ptr))
		printf("Deque Underflow");
	else
	{
		printf("Number deleted %d",ptr->a[ptr->left]);
		if (ptr->left==ptr->right)
		{
			ptr->left=-1;
			ptr->right=-1;
		}
		else if (ptr->left==max-1)
			ptr->left=0;
		else
			ptr->left=ptr->left+1;
	}
}

int right_insert(dq *ptr,int item)
{
	if(dq_full(ptr))
		printf("Deque Overflow");
	else
	{
		if(ptr->right==-1)
		{
			ptr->left=0;
			ptr->right=0;
		}
		else if (ptr->right==max-1)
			ptr->right=0;
		else
			ptr->right=ptr->right+1;
	ptr->a[ptr->right]=item;
	}
}
int right_delete(dq *ptr)
{
	if (dq_empty(ptr))
		printf("Deque Underflow");
	else
	{
		printf("Number deleted %d",ptr->a[ptr->right]);
		if (ptr->right==ptr->left)
		{
			ptr->left=-1;
			ptr->right=-1;
		}
		else if(ptr->right==0)
			ptr->right=max-1;
		else
			ptr->right=ptr->right-1;
	}
}			
