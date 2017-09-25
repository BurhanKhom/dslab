#include<stdio.h>
#define MAX 3
int top=-1;
int s[MAX];

void push(int ele)
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




void display()
{
	int i;
	printf("The Elements of the Stack are :\n");
	if(top==-1)
		printf("Stack is Empty!!\n");
	else
		{
			for(i=top; i>=0; i--)
			printf("%d\n", s[i]);
		}

}

void palindrome()
{	

	int n;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements : ");
	
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(int i=0; i<n; i++)
		push(a[i]);
		
		
	int x, i, flag=0;
	for(x=0, i=n-1; x<n; x++, i--)
	{
		if(s[x]!=pop())	
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
	int x, ele;


	while(1){
	printf("__________________\n");
	printf("|STACK OPERATIONS|\n");
	printf("|1. Push         |\n|2. Pop          |\n|3. Display      |\n|4. Palindrome   |\n|5. Exit         |\n");
	printf("|________________|\n");
	printf("Enter your choice : ");
	scanf("%d", &x);
	switch(x){
		case 1 : printf("Enter the Element to be pushed : ");
					scanf("%d", &ele);
					push(ele);
					break;
		case 2 :	ele = pop();
					printf("Deleted Element = %d\n", ele);
					break;
		case 3 : display();
					break;
		case 4 : palindrome();
					break;
		case 5 : return 0;
					break;
		default : printf("Invalid Choice!\n");			

	}
	
	
	}

}
