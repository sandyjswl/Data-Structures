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
    int ch,n,m,f,c=0;
    node *start=NULL,*temp,*recent,*previous;
    for(;;)
    {
        system("cls");
        printf("1.Create Nodes\n");
        printf("2.Display Nodes\n");
        printf("3.Insert Before:\n");
        printf("4.Insert After:\n");
        printf("5.Delete:\n");
        printf("6.Count:\n");
        printf("7.Exit\n");
        printf("Select a choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("enter number ");
                    scanf("%d",&n);
                    temp=(node*)malloc(sizeof(node));   /*create a tempraray node*/
                    temp->data=n;   		/*put n on the infor part of the temp node*/
                    temp->ptr=NULL;			/*put null on the ptr part of temp node*/

                    if(start==NULL)
                    {
                        start=temp;  /*when list is empty put temp on start to point to the temp node*/
                    }
                    else       /*when first node is inserted*/
                    {
                        recent=start;    /*recent means the node currently visited*/
                        while(recent->ptr!=NULL)   
                        {
                            recent=recent->ptr;
                        }
                        recent->ptr=temp;
                    }
                    break;
                }

            case 2:
                {
                    if(start==NULL)
                    {
                        printf("list is empty");
                        getch();
                    }
                    else
                    {
                        recent=start;
                        while(recent!=NULL)
                        {
                            printf("%d\n",recent->data);
                            recent=recent->ptr;
                        }
                        getch();
                    }
                    break;
                }

            case 3:
                {
                    if(start==NULL)
                    {
                        printf("list is empty");
                        getch();
                    }
                    else
                    {
                        f=0;
                        printf("Enter the number to insert:\n");
                        scanf("%d",&n);
                        printf("Enter the number before which you wish to insert:\n");
                        scanf("%d",&m);
                        temp=(node*)malloc(sizeof(node));
                        temp->data=n;
                        temp->ptr=NULL;
                        recent=start;    /*to select the first node->since start contains the adress of first nodee*/
                        if(recent->data==m)
                        {

                            temp->ptr=recent;   /*adress of recent in ptr part of temp*/
                            start=temp;     /*so that start now points to temp */
                            f=1;
                        }
                        else
                        {
                            while(recent->ptr!=NULL)
                            {
                                if(recent->data==m)
                                {
                                    temp->ptr=previous->ptr;
                                    previous->ptr=temp;
                                    f=1;
                                    break;
                                }
                                previous=recent;
                                recent=recent->ptr;
                            }

                            if(f==0)
                            {
                                if(recent->data==m)
                                {
                                    temp->ptr=previous->ptr;
                                    previous->ptr=temp;
                                    f=1;
                                }
                            }

                            if(f==0)
                            {
                                printf("numberf not found");
                                getch();
                            }
                        }
                    }
                    break;
                }

            case 4:
                {
                    if (start==NULL)
                    {
                        printf("List is empty");
                        getch();
                    }
                    else
                    {
                        f=0;
                        printf("Enter the number to insert:\n");
                        scanf("%d",&n);
                        printf("Enter the number after which you wish to insert:\n");
                        scanf("%d",&m);
                        temp=(node*)malloc(sizeof(node));
                        temp->data=n;
                        temp->ptr=NULL;
                        recent=start;
                        if(recent->data==m)
                        {
                            temp->ptr=recent->ptr;
                            recent->ptr=temp;
                            f=1;
                        }
                        else
                        {
                            while(recent->ptr!=NULL)
                            {
                                if (recent->data==m)
                                {
                                    temp->ptr=recent->ptr;
                                    recent->ptr=temp;
                                    f=1;
                                    break;
                                }
                            }
                            if(f==0)
                            {
                                if(recent->data==m)
                                {
                                    temp->ptr=recent->ptr;
                                    recent->ptr=temp;
                                    f=1;
                                    f=1;
                                }

                            }
                        }
                    }
                    break;
                }

            case 5:
                {
                    printf("ENter the number to delete:\n");
                    scanf("%d",&n);
                    if(start==NULL)
                    {
                        printf("List is empty");
                    }
                    else
                    {
                        f=0;
                        recent=start;

                        if (recent->data==n)
                        {
                            start=recent;
                            start=recent->ptr;
                            free(recent);
                            f=1;

                        }
                        else
                        {
                            while(recent->ptr!=NULL)
                            {

                                if(recent->data==n)
                                {
                                    previous->ptr=recent->ptr;
                                    free(recent);
                                    f=1;
                                    break;
                                }
                                previous=recent;
                                recent=recent->ptr;

                            }
                            if(f==0)
                            {
                                if(recent->data==n)
                                {
                                    previous->ptr=recent->ptr;
                                    free(recent);
                                    f=1;
                                }
                            }
                            if(f==0)
                            {
                                printf("Number not found");
                            }

                        }

                    }

                    break;
                }

            case 6:
                {
                    if(start==NULL)
                    {
                        printf("list is empty");
                        getch();
                    }
                    else
                    {
                        recent=start;
                        while(recent!=NULL)
                        {

                            recent=recent->ptr;
                            c++;
                        }
                        printf("The number of nodes in the List is %d",c);
                        getch();
                    }


                    break;

                }

            case 7:
                {
                    exit(0);
                    break;
                }













        }
    }

    return 0;

}