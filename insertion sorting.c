#include <stdio.h>
#include <conio.h>

int main()
{
    int a[10],i,p,l;
    printf("Enter the elements of array:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=1; i<10; i++)
    {
        l=a[i];
        p=i-1;
        
        while (a[p]>l)
        {
            a[p+1]=a[p];
            p--;
            if(p<0)
                break;

        }
        a[p+1]=l;
    }
    printf("\n\nThe Sorted Array is:\n");
    for(i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }   
}