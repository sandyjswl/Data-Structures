#include<stdio.h>
#include<stdlib.h>
int cnt;
void toh(int,char,char,char);
main()
{
	
	int n;
	printf("\n ENter the number of disks");
	scanf("%d",&n);
	toh(n,'s','a','d');
	printf("\n Total number of steps : %d\n",cnt);
}
void toh(int n, char s, char a, char d)
{
	if (n==1)
	{
		printf("\n Number of steps %d: %c->%c",++cnt,s,d);
		return;
	}
	toh(n-1,s,d,a);
	  printf("\n Number os fteps %d: %c->%c",++cnt,s,d);
	toh(n-1,a,s,d);
}
	
