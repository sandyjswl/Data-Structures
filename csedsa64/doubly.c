#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *next,*prev;
};
void traverse(struct node *head);
struct node *create(struct node *head,int);
struct node *insertany(struct node *head, int,int);
struct node *deleteany(struct node *head, int pos);    

int main()
{
	int n,ch,item,pos;
	struct node *head=NULL;
	while (1)
	{
	
		printf("\nMenu...\n1.Create\n2.Traverse\n3.Insert ANy\n4.Delte ANy\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);		
				break;
			case 1:
				printf("Enter number of nodes:\n");
				scanf("%d",&n);
				head=create(head,n);
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				printf("ENter the number:\n");
				scanf("%d",&item);
				printf("ENter the position:\n");
				scanf("%d",&pos);
				head=insertany(head,item,pos);
				break;
			case 4:
				printf("Enter position:\n");
				scanf("%d",&pos);
				head=deleteany(head,pos);
				break;
		}
	}
}

struct node *create(struct node *head,int n)
{
	struct node *temp,*newnode;
	int item,i;
	if (head!=NULL)
	{
		printf("List already exists\n");
	}
	else
	{
		for(i=0; i<n; i++)
		{	printf("Enter the number:\n");
			scanf("%d",&item);
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->info=item;
			newnode->next=NULL;
			if(head==NULL)
			{
				head=newnode;
				newnode->prev=NULL;
			}
			else
			{
				temp->next=newnode;
				newnode->prev=temp;
			}
			temp=newnode;
		}
	}
	return (head);
}
void traverse(struct node *head)
{
	struct node *q,*temp,*rev;
	temp=head;
	printf("Forward Traverse\n");
	while (temp!=NULL)
	{
		rev=temp;	
		printf("->%d",temp->info);
		temp=temp->next;
	}
	printf("\nBackward Traverse\n");
	while(rev!=NULL)
	{
		printf("->%d",rev->info);
		rev=rev->prev;
	}
	

}
			
			
struct node *insertany(struct node *head, int item,int p)
{
	struct node *loc,*temp,*newnode;
	int i=1;
	if(head==NULL)
	{
		printf("List doesn't exist");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	if(i==p)
	{
		newnode->prev=NULL;
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		return(head);
	}
	temp=head;
	while(i!=p)
	{
		loc=temp;
		temp=temp->next;
		i=i+1;
	}
	if(temp->next==NULL)
	{
		temp->next=newnode;
		newnode->next=NULL;
		newnode->prev=temp;
	}
	else
	{
		loc->next=newnode;
		newnode->prev=loc;
		newnode->next=temp;
		temp->prev=newnode;
	}
	return(head);
}

struct node *deleteany(struct node *head, int pos)
{
	struct node *preptr,*ptr;
	int i=1;
	ptr=head;
	while(i!=pos)
	{
		preptr=ptr;
		ptr=ptr->next;
		i=i+1;
	}
	if(ptr->next==NULL)
	{
		preptr->next=NULL;
	}
	else
	{
		preptr->next=ptr->next;
		ptr->next->prev=preptr;
	}
	if(i==1)
	{
		ptr->next->prev=NULL;
		head=ptr->next;
	}
	free(ptr);
	return(head);
}				
