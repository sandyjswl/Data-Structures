
#include<stdio.h>
#include<conio.h>
#define size 5

int main()
{
    int re=-1,fr=0,arr[size],x,c;

    for(;;)
    {
        system("cls");
        printf("1.Insert Rear\n");
        printf("2.Delete Rear\n");
        printf("3.Insert Front\n");
        printf("4.Delete Front\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                {
                    if(re==size-1)
                    {
                        printf("cannot insert from rear end");
                        getch();
                    }
                    else
                    {
                        re++;
                        printf("Enter No. ");
                        scanf("%d",&arr[re]);

                    }
                    break;
                }

            case 2:
                {
                    if(re==-1 || re<fr)
                    {
                        printf("cannot delete from rear end");
                        getch();
                    }
                    else
                    {
                        printf("no. delete from rear end %d",arr[re]);
                        re--;
                        getch();
                    }
                    break;
                }


            case 3:
                {
                    if(fr==0)
                    {
                        printf("cannot insert from front end");
                        getch();
                    }
                    else
                    {
                        fr--;
                        printf("enter no ");
                        scanf("%d",&arr[fr]);
                    }
                    break;
                }


            case 4:
                {
                    if(fr==size || fr>re)
                    {
                        printf("cannot delete from front end");
                        getch();
                    }
                    else
                    {
                        printf("no deleted from front end %d",arr[fr]);
                        fr++;
                        getch();
                    }
                    break;
                }

            case 5:
                {
                    if(fr<=re)
                    {
                        for(x=fr; x<=re; x++)
                        {
                            printf("%d ",arr[x]);
                        }
                        getch();
                    }
                    else
                    {
                        printf("Queue is empty cannot display");
                        getch();
                    }
                    break;
                }

            case 6:
                {
                    exit(0);
                }

            default:
                printf("Out of choice");
                getch();
        }
    }
    return 0;
}







