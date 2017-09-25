#include<stdio.h>
int top=-1;
#define MAX 100
int s[MAX];
void push(char ele)
{	
	
	
	if(top==MAX-1)
		printf("Stack Overflow!!\n");
	else
	{
		top=top+1;
		s[top]=ele;
		
	}

}


int pop()
{
	int del;
	if(top==-1)
		printf("Stack Undeflow!!\n");
	else
	{
		del=s[top];
		top=top-1;
	
	}

	return del;

}

int main()
{

	int a[100];
	for(int i=0; i<7; i++)
	{
		scanf("%d", &a[i]);
		push(a[i]);
	}
	int x=pop();
	int min=x, max=x;
	for(int i=0; i<6; i++, x=pop())
	{
		
		if(x<min)
		{
			min=x;

		}
		else if(x>max)
			max=x;
		else
			continue;


	}

	printf("Max= %d Min=%d\n", max, min);
	return 0;



}





















