#include <stdio.h>
#include <conio.h>

void mergesort(int a[],int m);
void main()
{
    int a[5],b[5],c[10],n,m,i,j,k,l,q;
    printf("Enter the size of array 1\n");
    scanf("%d",&n);
    printf("Enter Elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    l=mergesort(a[],n);

    printf("Enter the size of array 2\n");
    scanf("%d",&m);
    printf("Enter Elements:\n");
    for(i=0; i<m; i++)
    {
        scanf("%d",&b[i]);
   	}
    q=mergesort(b[],m);
   
}
void mergesort(int a[],int m)
{
	int i,j,p=0,x=0,k,n;
	int c[10];
	for(i=0; i<n; i++)
    {
        x=0;
        for(j=0; j<p; j++)
        {
            if(a[i]>c[j])
            {
                continue;
            }
            else
            {
                for(k=p; k>j; k--)
                {
                    c[k]=c[k-1];
                }
                c[k]=a[i];
                p++;
                x=1;
                break;
            }
        }

        if(x==0)
        {
            c[p]=a[i];
            p++;
        }
    }
	
	 printf("\n\n\n\nMerge Array After Sorting\n");
    for(i=0; i<p; i++)
    {
        printf("%d ",c[i]);
    }
	
}

  


