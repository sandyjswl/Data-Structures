#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *next;
};
struct node *create(struct node *head,int n);
void traverse(struct node *head);
struct node *insertbefore(struct node *head);
void insertend(struct node *head);
struct node *insertany(struct node *head);
void count(struct node *head);
struct node *deletefirst(struct node *head);
struct node *deletelast(struct node *head);
struct node *deleteany(struct node *head);
struct node *deleteinfo(struct node *head);
struct node *reverse(struct node *head);
struct node *sorting(struct node *head);
void search(struct node *head);

int main()
{
	int n,ch,p;
	struct node *head=NULL;
	do{
	printf("\nMenu.\n1.Create\n2.Traverse\n3.Insert Before\n4.Insert End\n5.Insert Any\n6.Count\n7.Delete First\n8.Delete Last\n9.Delete Any\n10.Delte Info\n11.Reverse\n12.Sorting\n13.Searching\n0.Exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:
			exit(0);
		case 1:
			printf("\nEnter number of nodes");
			scanf("%d",&n);
			head=create(head,n);
			break;
		case 2:
			traverse(head);
			break;
		case 3:
			head=insertbefore(head);
			break;
		case 4:
			insertend(head);
			break;
		case 5:
			head=insertany(head);
			break;
		case 6:
			count(head);
			break;	
		case 7:
			head=deletefirst(head);
			break;
		case 8:
			head=deletelast(head);
			break;
		case 9:
			head=deleteany(head);
			break;
		case 10:
			head=deleteinfo(head);
			break;
		case 11:
			head=reverse(head);
			break;
		case 12:
			head=sorting(head);
			break;
		case 13:
			search(head);
			break;
		default:
			printf("Invalid Choice");
	}
	printf("\nPress 1 to continue, 0 to exit");
	scanf("%d",&p);
	}while (p=1);
	return(0);
		
}

struct node *create(struct node *head, int n)
{
	struct node *temp, *ptr;
	int i,item;
	if(head!=NULL)
	{
		printf("List already exists");
		return (head);
	}
	else
	{
		for(i=1; i<=n; i++)
		{
		printf("\nENter the info of the nodes");
		scanf("%d",&item);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=item;
		ptr->next=NULL;
		if(head==NULL)
			{
			head=ptr;
			}
		else
			{
				temp->next=ptr;
			}		
				temp=ptr;
			
		}
		return (head);
	}
}
void traverse(struct node *head)
{
	struct node *loc;
	loc=head;
	while (loc!=NULL)
	{
		printf("-> %d",loc->info);
		loc=loc->next;
	}
		
}	
struct node *insertbefore(struct node *head)
{
	struct node *newnode;
	int item;	
	if(head==NULL)
	{
		printf("List doesn't exist");
	}
	else
	{
		printf("Enter ITEM");
		scanf("%d",&item);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->info=item;
		newnode->next=head;
		head=newnode;
	}
return(head);
}

void insertend(struct node *head)
{
	struct node *newnode,*temp;
	int item;
	if(head==NULL)
		printf("List doesn't exist");
	else
	{
		printf("Enter ITEM");
		scanf("%d",&item);
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
	        newnode->info=item;
	        newnode->next=NULL;
		
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newnode;
	}
}	
struct node *insertany(struct node *head)
{
	struct node *temp=head,*ptr;
	int item,pos,i=1;
	if (head==NULL)
		printf("List doesn't exixt");
	else
	{
		printf("ENter ITEM");
		scanf("%d",&item);
		printf("ENter position");
		scanf("%d",&pos);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=item;
		if(i==pos)
		{
			ptr->next=head;
			head=ptr;	
		}
		else
		{
			while(i!=pos-1)
			{
				temp=temp->next;
				i++;
			}
		ptr->next=temp->next;
		temp->next=ptr;
		}
		return(head);
	}		
}			
void count(struct node *head)
{
struct node *loc;
int c=0;
        loc=head;
        while (loc!=NULL)
        {
                c++;
        }
	printf("The number of nodes in the List is %d",c);
}

struct node *deletefirst(struct node *head)
{
struct node *ptr;
if (head==NULL)
	printf("List is empty");
else
{
	ptr=head;	
	head=head->next;
	free(ptr);
	return (head);

}
}

struct node *deletelast(struct node *head)
{
struct node *ptr,*preptr;
if(head==NULL)
	printf("list is empty");
else
{
	ptr=head;
	while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
	preptr->next=NULL;
	free(ptr);
	return(head);	
}

}

struct node *deleteany(struct node *head)
{
struct node *temp,*q;
int i=1,pos;
if (head==NULL)
	printf("list is empty");
else
{
	printf("Enter position to delete:\n");
	scanf("%d",&pos);	
	temp=head;
	while (i!=pos)
	{
		q=temp;
		temp=temp->next;
		i++;
	}
	if(temp==head)
	{
		head=temp->next;
		free(temp);
	}
	else
	{
		q->next=temp->next;
		free(temp);
	}
	return(head);
}
}

struct node *deleteinfo(struct node *head)
{
	struct node *temp,*old;
	int key;	
	if(head==NULL)
		printf("List is empty bro");
	else
	{
		printf("Enter element to delete:\n");
		scanf("%d",&key);
		temp=head;
		while(temp!=NULL && temp->info!=key)
		{
			old=temp;
			temp=temp->next;
		}
		if (temp==head)
		{
			head=temp->next;
			free(temp);
		}
		else
		{
			old->next=temp->next;
			free(temp);
		}
		return(head);
	}
}

struct node *reverse(struct node *head)
{
	struct node *temp,*loc,*locp,*locn;
	if(head==NULL)
		printf("List is enmpty");
	else
	{
		loc=head;
		locp=NULL;
		locn=loc->next;
		loc->next=locp;
		while(locn!=NULL)
			{
				locp=loc;
				loc=locn;
				locn=loc->next;
				loc->next=locp;
			}
		head=loc;
		return(head);
	}
}

struct node *sorting(struct node *head)
{
	struct node *loc1,*loc2;
	int item;
	if(head==NULL)
		printf("List is empty");
	else
	{
		loc1=head;
		for(;loc1!=NULL; loc1=loc1->next)
		{
			for(loc2=loc1; loc2!=NULL; loc2=loc2->next)
				{
					if(loc1->info>loc2->info)
					{
						item=loc1->info;
						loc1->info=loc2->info;
						loc2->info=item;
					}
				}
		}
		
	}
	return(head);
}



void search(struct node *head)
{
	struct node *ptr,*loc;
	int key;
	if(head==NULL)
		printf("list is empty");
	else
	{
		printf("Enter the ITEM you want to search:\n");
		scanf("%d",&key);
		ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->info==key)
			{
				printf("Search is succesful");
			//	break;
				return;
			
			}
			else 
			{
				ptr=ptr->next;
			}
		
		
		}
		printf("search is unsuccesful");
		
		
	}
}
				
