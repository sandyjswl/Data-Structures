#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *ptr;
} node;

int main()
{
    int ch,n,f,m;
    node *start=NULL,*temp,*recent,*previous,*last;
    for(;;)
    {
        system("cls");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert after\n");
        printf("4.Insert before\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    printf("Enter the NUMBER:\n");
                    scanf("%d",&n);
                    temp=(node*)malloc(sizeof(node));
                    temp->data=n;
                    temp->ptr=start;
                    if (start==NULL)
                    {
                        start=temp;
                        temp->ptr=start;
                    }
                    else
                    {
                        recent=start;
                        while(recent->ptr!=start)
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
                        while(recent->ptr!=start)
                        {
                            printf("\n%d\n",recent->data);
                            recent=recent->ptr;
                        }
                        printf("\n%d\n",recent->data);

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
                        printf("ENter the number you want to insert:\n");
                        scanf("%d",&n);
                        printf("Enter the number after which you want to insert:\n");
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
                            while(recent->ptr!=start)
                            {
                                if(recent->data==m)
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
                        recent=start;
                        if(recent->data==m)
                        {
                            temp->ptr=recent;
                            while (recent->ptr!=start)
                            {
                                recent=recent->ptr;

                            }
                            last=recent;
                            start=temp;
                            last->ptr=start;

                        }

                    }
                    break;
                }






        }
    }

    return 0;
}