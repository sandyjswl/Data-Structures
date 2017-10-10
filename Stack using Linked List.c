#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *ptr;
} node;

int main()
{
	int n,ch;
	node *start=NULL,*ptr,*temp;
	for(;;)
	{
		  system("cls");
		  printf("1.Push\n");
		  printf("2.Pop\n");
		  printf("3.Display\n");
		  printf("Select a choice\n");
		  scanf("%d",&ch);
		  switch(ch)
		  {
		  	case 1:
		  		{
		  			printf("Enter ITEM to Push:\n");
		  			scanf("%d",&n);
		  			temp=(node*)malloc(sizeof(node));
		  			temp->data=n;
		  			temp->ptr=start;
		  			start=temp;
		  			
		  			break;
		  		}
		  	case 2:
		  		{
		  			if(start==NULL)
		  			{
		  				printf("stack underflow\n");
		  			}
		  	
		  			
		  			break;
		  		}
		  	case 3:
		  		{
		  	
		  			printf("Elements are:\n");
		  			while(start->ptr!=NULL)
		  			{
		  				printf("%d\n",start->data);
		  				start=start->ptr;
		  				
		  			}
		  			printf("%d\n",start->data);
		  			getch();
		  			break;
		  		}
		  }
	}
	
	
	
	return 0;
}