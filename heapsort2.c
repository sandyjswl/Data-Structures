/*
Heap Sort using Max Heap
For any node in position i,
-> its left child (if any) is in position 2i
-> its right child (if any) is in position 2i + 1
-> its parent (if any) is in position i/2
*/


#include<stdio.h>
#include<conio.h>


void max_heap(int arr[],int n)
{
    int i,root,c,temp;

    for (i = 1; i <= n; i++)
    {
        c = i;
        do
        {
            root = (c-1)/2;
            if (arr[root] < arr[c])   /* to create MAX heap array */
            {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        }
        while (c != 0);
    }
}


void main()
{
    int arr[10],i,size=9,temp;
    printf("enter 10 numbers\n");
    for(i=0; i<10; i++)
    {
        scanf("%d",&arr[i]);
    }


    //arrange the array
    for(i=0; i<10; i++)
    {
        max_heap(arr,size-i);

        //replace 1st element with last element
        temp=arr[0];
        arr[0]=arr[size-i];
        arr[size-i]=temp;
    }

    for(i=0; i<10; i++)
    {
        printf("%d ",arr[i]);
    }



}
