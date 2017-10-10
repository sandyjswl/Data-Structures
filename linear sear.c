#include <stdio.h>
#include <conio.h>

int main()
{
    int a[10],c=0,p,i,n;
    printf("Enter 10 numbers into the array:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);

    }
    printf("\nNow ENter the Number you want to search:\n");
    scanf("%d",&n);
    for(i=0; i<10; i++)
    {
        if (a[i]==n)
        {
            p=i;
            c++;
            break;
        }
    }
    if (c==0)
    {
        printf("\n\nSorry!! Number was not found in the array\n\n");
    }
    if(c==1)
    {
        printf("\n\n The Number  was found on the POSITION %d\n\n",p+1);
    }
    return 0;
}