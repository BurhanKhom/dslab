#include<stdio.h>
#define MAX 3
void palindrome()
{
	printf("Enter the elements : ");
	int a[MAX];
	for(int i=0; i<MAX; i++)
		scanf("%d", &a[i]);
		
		
	int x, i, flag=0;
	for(x=0, i=MAX-1; x<MAX; x++, i--)
	{
		if(a[x]!=a[i])	
			{
				flag=1;
				break;
			}
	}		
	
	if(flag==0)
		printf("It's a Palindrome!\n");
	else
		printf("It's Not a Palindrome!\n");
		
}
int main()
{

palindrome();

}
