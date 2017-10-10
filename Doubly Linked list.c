#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *prv,*nxt;
} node;


int main()
{
    int ch,n,f,m;
    node *start=NULL,*temp,*recent,*previous,*next;
    for(;;)
    {
        system("cls");
        printf("1.Create Nodes\n");
        printf("2.Display Nodes\n");
        printf("3.Insert After\n");
        printf("4.Insert Before\n");
        printf("5.Delete\n");
        printf("6.Reverse\n");

        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("Enter NUMBER:\n");
                    scanf("%d",&n);
                    temp=(node*)malloc(sizeof(node));
                    temp->prv=NULL;
                    temp->data=n;
                    temp->nxt=NULL;
                    if(start==NULL)
                    {
                        start=temp;
                    }
                    else
                    {
                        recent=start;
                        previous=NULL;
                        while(recent->nxt!=NULL)
                        {
                            previous=recent;
                            recent=recent->nxt;
                        }
                        recent->nxt=temp;
                        temp->prv=recent;
                    }
                    break;
                }

            case 2:
                {
                    if(start==NULL)
                    {
                        printf("List is empty");
                        getch();
                    }
                    else
                    {
                        recent=start;
                        while(recent!=NULL)
                        {
                            printf("\n%d\n",recent->data);
                            recent=recent->nxt;
                        }
                        getch();
                    }
                    break;
                }

            case 3:
                {
                    if(start==NULL)
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
                        temp->prv=NULL;
                        temp->data=n;
                        temp->nxt=NULL;
                        recent=start;
                        if(recent->data==m)
                        {
                            temp->nxt=recent->nxt;
                            temp->prv=recent;
                            recent->nxt=temp;
                            f=1;
                        }
                        else
                        {
                            while(recent->nxt!=NULL)
                            {
                                if(recent->data==m)
                                {
                                    temp->nxt=recent->nxt;
                                    temp->prv=recent;
                                    recent->nxt=temp;
                                    temp->nxt->prv=temp;
                                    f=1;

                                }
                                recent=recent->nxt;


                            }
                            if(f==0)
                            {
                                if (recent->data==m)
                                {
                                    temp->nxt=recent->nxt;
                                    temp->prv=recent;
                                    recent->nxt=temp;
                                    f=1;
                                }
                            }
                        }



                    }
                    break;
                }

            case 4:
                {
                    if(start==NULL)
                    {
                        printf("List is empty");
                    }
                    else
                    {
                        f=0;
                        printf("Enter the number you want to insert:\n");
                        scanf("%d",&n);
                        printf("Enter the number before which you want to insert:\n");
                        scanf("%d",&m);
                        temp=(node*)malloc(sizeof(node));
                        temp->prv=NULL;
                        temp->nxt=NULL;
                        temp->data=n;
                        recent=start;
                        if(recent->data==m)
                        {
                            temp->nxt=recent;
                            recent->prv=temp;
                            start=temp;
                        }
                        else
                        {
                            while(recent->nxt!=NULL)
                            {
                                if (recent->data==m)
                                {
                                    temp->nxt=previous->nxt;
                                    temp->prv=previous;
                                    previous->nxt=temp;
                                    recent->prv=temp;
                                    f=1;
                                }
                                previous=recent;
                                recent=recent->nxt;
                            }
                            if(f==0)
                            {
                                if(recent->data==m)
                                {
                                    temp->nxt=previous->nxt;
                                    temp->prv=previous;
                                    previous->nxt=temp;
                                    recent->prv=temp;
                                    f=1;
                                }
                            }
                            if(f==0)
                            {
                                printf("Number not found");
                                getch();
                            }
                        }
                    }


                    break;
                }

            case 5:
                {
                    printf("Enter number to delete:\n");
                    scanf("%d",&n);
                    if(start==NULL)
                    {
                        printf("List is empty");
                    }
                    else
                    {
                        f=0;
                        recent=start;
                        if(recent->data==n)
                        {
                            start=recent;
                            start=recent->nxt;
                            free(recent);
                            f=1;
                        }
                        else
                        {
                            while(recent->nxt!=NULL)
                            {
                                if (recent->data==n)
                                {
                                    previous->nxt=recent->nxt;
                                    recent->nxt->prv=previous->nxt;
                                    free(recent);
                                    f=1;
                                }
                                previous=recent;
                                recent=recent->nxt;

                            }
                            if(f==0)
                            {
                                if (recent->data==n)
                                {
                                    previous->nxt=recent->nxt;
                                    free(recent);
                                    f=1;
                                }
                            }
                        }

                    }
                    break;
                }

            case 6:
                {

                    if(start==NULL)
                    {
                        printf("List is empty");
                        getch();
                    }
                    else
                    {
                        recent=start;
                        while(recent->nxt!=NULL)
                        {
                            /*printf("\n%u|%d|%u| %u\n",recent->prv,recent->data,recent->nxt,recent);*/
                            recent=recent->nxt;
                        }


                        while(recent->prv!=NULL)
                        {
                            printf("\n%d\n",recent->data);
                            recent=recent->prv;
                        }
                        printf("\n%d\n",recent->data);

                    }
                    getch();
                    break;

                }

        }


    }

    return 0;
}