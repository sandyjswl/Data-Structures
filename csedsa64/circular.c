#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *create(struct node *head);
void traverse(struct node *head);
struct node *insertbegin(struct node *head,int item);
struct node *insertend(struct node *head,int item);
struct node *deletebegin(struct node *head);
struct node *deleteend(struct node *head); 


 main()
{
	int ch,item;
	struct node *head=NULL;	
	while (1)
	{
		printf("\n0.Exit\n1.Create\n2.Traverse\n3.Insert Begin\n4.Insert End\n5.Delete Begin\n6.Delete End\nSelect your choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:exit(0);
			case 1:
				head=create(head);
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				printf("Enter the number to insert:\n");
				scanf("%d",&item);
				head=insertbegin(head,item);
				break;
			case 4:
				printf("Enter number :\n");
				scanf("%d",&item);
				insertend(head,item);
				break;
			case 5:
				
				head=deletebegin(head);
				break;
			case 6:
				head=deleteend(head);
				break;

		}
	}
}
struct node *create(struct node *head)
{
	struct node *temp,*newnode;
	int n,i,item;
	if (head!=NULL)
		printf("List Exists");
	else
	{
		printf("Enter the number of nodes:\n");
		scanf("%d",&n);
		for(i=1; i<=n; i++)
		{
		printf("ENter the item");
		scanf("%d",&item);
		
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
		if (head==NULL)
		{
		head=newnode;
		newnode->next=head;
		}
		else
		{
		temp->next=newnode;
		newnode->next=head;
		}
		temp=newnode;
		}
	}
	return (head);
				
}
void traverse(struct node *head)
{
	struct node *loc=head;
	while (loc->next!=head)
	{
		printf("->%d",loc->info);
		loc=loc->next;
	}
		printf("->%d",loc->info);
}
struct node *insertbegin(struct node *head,int item)
{
	struct node *temp,*newnode;
	newnode= (struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=head;
	head=newnode;
	return(head);
}	

struct node *insertend(struct node *head,int item)
{
        struct node *temp,*newnode;
        newnode= (struct node*)malloc(sizeof(struct node));
        newnode->info=item;
        temp=head;
        while(temp->next!=head)
        {
                temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        
        return(head);
}

struct node *deletebegin(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=head->next;
	free(head);
	head=temp->next;
	return(head);
}
struct node *deleteend(struct node *head)
{
	struct node *temp,*old;
	temp=head;
	while(temp->next!=head)
	{
		old=temp;
		temp=temp->next;
	}
	old->next=temp->next;
	free(temp);
	return(head);
}		
