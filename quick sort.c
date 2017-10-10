#include <stdio.h>
#include <conio.h>

int main()
{
    int a[10],i;
    printf("Enter 10 Numbers into the array:\n");
    for(i=0; i<9; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<10; i++)
    {
    	if(a[i]>10)
    	{
    		break;
    	}	
    	else
    	{
    		printf("%d  ",a[i]);
    	}
    		
    }	
    	
    	
    
    

}


