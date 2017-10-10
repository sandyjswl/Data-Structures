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
    for(i=0; i<9; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    for(i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }



}