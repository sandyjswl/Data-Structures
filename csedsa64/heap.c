#include<stdio.h>
#define max 20

void display(int [],int);
void exchange(int *, int *);
void buildmaxheap(int [],int);
void heapsort(int [],int);
void maxheapify(int [], int ,int);
main()
{
        int a[20];
        int i,n,ch;
        printf("ENter Index of the Array:\n");
        scanf("%d",&n);
        printf("Enter the Elemets:\n");
        for(i=1; i<=n; i++)
        {
                scanf("%d",&a[i]);
        }
        printf("Before SOrting:\n");
        display(a,n);
        heapsort(a,n);
        printf("\nAfter Sorting:\n");
        display(a,n);
}

void display(int a[],int n)
{
        int i;
        for(i=1; i<=n; i++)
        {
                printf("%d   ",a[i]);
        }
}

void heapsort(int a[],int n)
{
	int i,t;
	buildmaxheap(a,n);
	for(i=n; i>=2; i--)
	{
		t=a[1];
		a[1]=a[i];
		a[i]=t;
		maxheapify(a,i-1,1);
	}
}
void buildmaxheap(int a[],int n)
{
	int i;
	for(i=n/2; i>=1; i--)
	{
		maxheapify(a,n,i);
	}
}
void maxheapify(int a[], int n,int i)
{
	int l,r,largest,t;
	l=2*i;
	r=(2*i)+1;
	if(l<=n && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if (r<=n && a[r]>a[largest])
		largest=r;
	if (largest!=i)
	{
		t=a[i];
		a[i]=a[largest];
		a[largest]=t;
		maxheapify(a,n,largest);
	}
}
/*void exchange(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	temp=*b;
}*/
