/*
formula for checking if two queens attack each other
if previous_queen_position!=current_queen_position &&
    previous_queen_position!=current_queen_position - (current_queen_number - previous_queen_no) &&
       previous_queen_position!=current_queen_position + (current_queen_number - previous_queen_no) then

       current_queen_position is safe
*/


#include<stdio.h>
const int n=4;
int pos[5];

int isSafe(int cqn,int cqp)
{
    int i,safe=0,pqp,pqn;
    for(i=1;i<cqn;i++)
    {
        pqp=pos[i];
        pqn=i;
        if(pqp!=cqp  &&  pqp!=cqp-(cqn-pqn)  &&  pqp!=cqp+(cqn-pqn))
        {
            safe++;
        }
    }
    if(safe==cqn-1)
    {
        return 1;
    }

    return 0;
}


display(int p)
{
    int i;
    for(i=1;i<=p;i++)
    {
        printf("%d ",pos[i]);
    }
    printf("\n");

}



void main()
{
    int a,b,c,d;

    //first queen
    for(a=1;a<=n;a++)
    {

        if(isSafe(1,a)==1)
        {
            pos[1]=a;


            //second queen
            for(b=1;b<=n;b++)
            {
                if(isSafe(2,b)==1)
                {
                    pos[2]=b;


                    //third queen
                    for(c=1;c<=n;c++)
                    {
                        if(isSafe(3,c)==1)
                        {
                            pos[3]=c;


                            //fourth queen
                            for(d=1;d<=n;d++)
                            {
                                if(isSafe(4,d)==1)
                                {
                                    pos[4]=d;
                                    display(4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

