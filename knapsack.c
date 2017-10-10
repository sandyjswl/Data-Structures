/*5 items
w   v
2   10
3   8
5   12
6   11
4   7
max wt.
15*/

#include<stdio.h>

void main()
{
    int arr[20][2],temp[20][2],result[20][2];
    int maxwt,tv=0,tw=0,ti;
    int r,c,n,i,j,f,w,v;

    printf("enter maximum weight capacity of knapsack: ");
    scanf("%d",&maxwt);

    printf("Enter total no of item: ");
    scanf("%d",&n);

    for(r=0; r<n; r++)
    {
        printf("\nitem no %d",r+1);

        printf("\nitem weight= ");
        scanf("%d",&arr[r][0]);

        printf("item value= ");
        scanf("%d",&arr[r][1]);
    }


    for(i=0; i<n; i++)
    {
        f=i;
        r=0;
        w=0;
        v=0;
        for(j=1; j<=n; j++)
        {
            //if current item weight + previous total weight is less than maximum weight then take the item
            if(arr[f][0]+w<=maxwt)
            {
                temp[r][0]=arr[f][0];
                temp[r][1]=arr[f][1];
                w=w+arr[f][0];
                v=v+arr[f][1];
                r=r+1;
            }
            f=(f+1)%n; //for forward movement
        }

        //check if the current total value is greater than prevoius total value
        if(v>tv)
        {
            tv=v;
            tw=w;
            for(c=0; c<r; c++)
            {
                result[c][0]=temp[c][0];
                result[c][1]=temp[c][1];
            }
            ti=r;
        }

        //printing summary
        printf("\nsl \t wt \t va\n");
        for(c=0; c<r; c++)
        {
            printf("%d \t %d \t %d\n",c+1,temp[c][0],temp[c][1]);
        }
        printf("total\t %d \t %d",w,v);
        printf("\n\n");

    }


    //printing final result
    printf("\n\n*************************\nsl \t wt \t va\n");
    for(c=0; c<ti; c++)
    {
        printf("%d \t %d \t %d\n",c+1,result[c][0],result[c][1]);
    }
    printf("*************************\ntotal\t %d \t %d\n*************************\n\n",tw,tv);


}
