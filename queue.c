//QUEUE-Sample Program

#include <stdio.h>
#include <conio.h>
#define size 10

int main()
{
    int a[size],c,r=-1,i,f=0;
    for(;;)
    {
        system("cls");
        printf("1 Insert\n");
        printf("2 Delete\n");
        printf("3 Display\n");
        printf("Enter choice ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                if(r==size-1)
                {
                    printf("queue is full");
                    getch();
                }
                else
                {
                    r++;

                    printf("enter number in the queue: ");
                    scanf("%d",&a[r]);
                }
                break;

            case 2:
                if(f>r)
                {
                    printf("queue is empty");
                    getch();
                }
                else
                {
                    printf("deleted no %d",a[f]);
                    f++;

                    getch();
                }
                break;

            case 3:
                if(f>r)
                {
                    printf("queue is empty");
                    getch();
                }
                else
                {
                    for(i=f; i<=r; i++)
                    {
                        printf("%d\n",a[i]);
                    }
                    getch();
                }
                break;

            default:
                printf("invalid choice");
                getch();
        }

    }

    return 0;
}

