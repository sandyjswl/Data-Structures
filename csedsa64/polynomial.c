#include<stdio.h>
#include<stdlib.h>
struct node
{
        int coeff;
	int expo;
        struct node *next;
};

struct node *create(struct node *head,int);
void traverse (struct node *head);
struct node *add(struct node *head1, struct node *head2, struct node *head3);
struct node *multiply(struct node *head1, struct node *head2, struct node *head4);

int main()
{
        int n,ch,item,pos;
        struct node *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
        while (1)
        {

                printf("\nMenu...\n1.Create\n2.Add\n3.Multiply\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 0:
                                exit(0);
                                break;
			case 1:
				printf("Enter the number of nodes for 1st poly: \n");
				scanf("%d",&n);
				head1=create(head1,n);
				printf("Enter the number of nodes for 2nd poly: \n");
				scanf("%d",&n);
				head2=create(head2,n);
				traverse(head1);
				traverse(head2);
				break;
			case 2:

			
				head3=add(head1,head2,head3);
				printf("\nResultant poly:\n");
				traverse(head3);
				break;
			case 3:
				head4=multiply(head1,head2,head4);
				printf("\nResult after Multiply:\n");
				traverse(head4);
				break;
			
		}
	}
}

struct node *create(struct node *head,int n)
{
	struct node *newnode,*temp;
	int i,c,e;
	if(head!=NULL)
	{
		printf("Listalready  don't exist");
		return(head);
	}
	for(i=1; i<=n; i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the Coefficient:\n");
		scanf("%d",&c);
		printf("Enter the exponent:\n");
		scanf("%d",&e);
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
	
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
		}
		temp=newnode;
	}	
		return(head);
	
}

void traverse(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->coeff);
		printf("x%d  ",temp->expo);
		temp=temp->next;
	}
		printf("\n");
}

struct node *append(struct node *head, int c, int e)
{
	struct node *newnode,*temp;
	temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	temp->next=newnode;
	}
	newnode->coeff=c;
	newnode->expo=e;
	newnode->next=NULL;
	return(head);
}

struct node *add(struct node *head1, struct node *head2, struct node *head3)
{
	struct node *temp1 , *temp2, *temp3; 
	int x;
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->expo==temp2->expo)
		{
			x=temp1->coeff+temp2->coeff;
			if(x!=0)
			{
				head3=append(head3,x,temp1->expo);
			}
		temp1=temp1->next;
		temp2=temp2->next;
		}
		else if(temp1->expo<temp2->expo)
		{
			head3=append(head3,temp2->coeff,temp2->expo);
			temp2=temp2->next;
		}
		else if(temp1->expo>temp2->expo)
                {
                        head3=append(head3,temp1->coeff,temp1->expo);
                        temp1=temp1->next;
                }
	}
	while(temp1!=NULL)
	{
		head3=append(head3,temp1->coeff,temp1->expo);
		temp1=temp1->next;
	}		
	  while(temp2!=NULL)
        {
                head3=append(head3,temp2->coeff,temp2->expo);
                temp2=temp2->next;
        }
	return(head3);
}

struct node *multiply(struct node *head1, struct node *head2, struct node *head4)
{
	struct node *newnode,*temph1,*temph2,*currh4;
	temph1=head1;
	temph2=head2;
	if(head1==NULL)
	{
		return(head1);
	}
	while(temph1!=NULL)
	{
		while(temph2!=NULL)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->next=NULL;
		newnode->coeff=temph1->coeff * temph2->coeff;
		newnode->expo=temph1->expo + temph2->expo;
		currh4=head4;
		head4=NULL;
		head4=add(currh4,newnode,head4);
		temph2=temph2->next;
	}
	temph2=head2;
	temph1=temph1->next;
	}
	return(head4);
}
