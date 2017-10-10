#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
void push(struct node **head,int);
void pop(struct node **head);
void display(struct node *head);
int main()
{
	int ch,item;
	struct node *head=NULL;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ENter ITEM to push:\n");
				scanf("%d",&item);
				push(&head,item);
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				display(head);
				break;
			case 0:exit(0);
				
		}	
	}
}
void push(struct node **head,int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->info=item;
	ptr->next=(*head);
	(*head)=ptr;
}
void pop(struct node **head)
{
	       struct node *temp;

	if(*head==NULL)
		printf("STack Underflow");
	else
	{
		
		temp=*head;
		printf("Deleted item is %d",temp->info);
		*head=(*head)->next;
		free(temp);
	}
}
void display(struct node *head)
{
 	       struct node *temp;
		temp=head;
		while(temp!=NULL)
			{
				printf("\n%d\n",temp->info);
				temp=temp->next;
			}
}			
