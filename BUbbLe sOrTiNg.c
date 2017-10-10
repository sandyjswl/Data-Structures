//Bubble Sorting
#include <stdio.h>
#include <conio.h>

int main()
{
    int a[10],i,t,j;
    printf("eNTER 10 nUMBERS iNTO tHE aRRAY:\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<9-i; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    for(i=0; i<10; i++)
    {
        printf("%d ->\t",a[i]);
    }



}