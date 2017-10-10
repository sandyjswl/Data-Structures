#include <stdio.h>
#include <conio.h>
#define size 10
void insert(int item);
void del();
void display();

int a[size];
int r=-1;
int f=0;
int main()
{
    int a[size],ch,item;
    printf("Enter your choice:\n");
    printf("1.Push\n");
    printf("2.POP\n");
    printf("3.Display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter the element to PUSH\n");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;


    }
}

void insert(int item)
{
    if(r==size-1)
    {
        printf("Queue Overflow");
        getch();
    }
    else
    {
        r++;
        a[r]=item;

    }

}
void del()
{
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
}
void display()
{
    int i;
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
}


