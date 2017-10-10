#include<stdio.h>
#include<con
#include<process.h>
#define size 8

		int main()
		{
			int arr[size],r=-1,f=0,nc=0,c,x,p;		
			for(;;)
			{
				 system("cls");
				printf("1. Insert Rear\n");
				printf("2. Delete Front\n");
				printf("3. Display\n");
				printf("4. Exit\n");
				printf("Enter Choice : ");
				scanf("%d",&c);

				switch(c)
				{
					case 1:
						if(nc==size)
						{
							printf("queue is full");
							getch();
						}
						else
						{
							r=(r+1)%size;
							printf("enter no ");
							scanf("%d",&arr[r]);
							nc=nc+1;
						}
						break;

					case 2:
						if(nc==0)
						{
							printf("queue is empty");
							getch();
						}
						else
						{
							printf("deleted no=%d",arr[f]);
							f=(f+1)%size;
							nc=nc-1;
							getch();
						}
						break;

					case 3:
						if(nc==0)
						{
							printf("queue is empty cannot display");
							getch();
						}
						else
						{
							p=f;
							for(x=1;x<=nc;x++)
							{
								printf("%d ",arr[p]);
								p=(p+1)%size;
							}
							getch();
						}
						break;

					case 4:
						exit(0);

					default:
						printf("wrong choice");
						getch();
				}
			}
		}
							
						
					
