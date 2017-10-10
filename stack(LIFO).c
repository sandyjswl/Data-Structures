//STACK(LIFO<--Last In First Out) Program

#include <stdio.h>
#include <conio.h>
#define size 8  

int main()
{
    int a[size],c,p=-1,i;
    for(;;)
    {
        system("cls");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Display\n");
        printf("Enter choice ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                if(p==size-1)
                {
                    printf("stack overflow");
                    getch();
                }
                else
                {
                    p++;
                    printf("enter number ");
                    scanf("%d",&a[p]);
                }
                break;

            case 2: 
                if(p==-1)
                {
                    printf("stack underflow");
                      getch();
                }
                else
                {
                    printf("deleted no %d",a[p]);
                    p--;
                   getch();
                }
				break;
					
            case 3:
				if(p==-1)
                {
                    printf("stack underflow");
                    getch();
                }
                else
                {
                    for(i=p; i>=0; i--)
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

//int a[size],c,p=-1,i;//here a[size] means array size,'i'for loop to print all tag numbers if tag is filled at last
//for(;;)//infinite type loop,it runs runs and runs,never ends, non-stop not like 0 to 10 like this--> (z=0;z<=10).(not runs query type) 
    //printf("1 Push\n");//<--menu
 //       printf("2 Pop\n");//<--menu
 //       printf("3 Display\n");//<--menu
 //       printf("Enter choice ");//<--menu
//c<--for choice
//case 1: for push if this tag is filled than it cant be push or insert
//case 2: for pop, if this tag is nil than you can pop or delete(remove).
//case 3: check tag is empty or not ,if tag is filled than show numbers using for loop 
     
//i for loop, showing all tag numbers using loop 