#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 100
int top=-1;
char s[MAX];

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
	char del;
	if(top==-1)
		printf("Stack Undeflow!!\n");
	else
	{
		del=s[top--];
		
	
	}

	return del;

}


int main()
{
	int i, result, op1, op2;
	char postfix[100];
	printf("Enter the postfix Expression : ");
	scanf("%s", postfix);
	
	for(i=0; postfix[i]!='\0'; i++)
		{
		
			char c=postfix[i];
			
			if(isdigit(c))
				push(c-'0');
			
			else
			{	
				op2=pop();
				op1=pop();	

				if(c=='+')
					result=op1+op2;
				else if(c=='-')
					result=op1-op2;
				else if(c=='*')
					result=op1*op2;
				else if(c=='/')
					result=op1/op2;
				else 
					result=pow(op1, op2);
					
				push(result);
			
			}	
				
				
			
		
		
		
		}


printf("%d\n", result);





return 0;
}




