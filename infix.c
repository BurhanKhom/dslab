#include<stdio.h>
#define MAX 100
int top=-1;
char s[MAX];

int isOperand(char c)
{
	if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-')
		return 0;
	else
		return 1;

}

int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return 0;

}


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


char pop()
{
	char del;
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
	int i, j=0;
	char infix[100], postfix[100], p;
	printf("Enter the infix Expression : ");
	scanf("%s", infix);
	for(i=0; infix[i]!='\0'; i++)
		{
		
			char c=infix[i];
			
			if(c=='(')
				push(c);
			
			else if(c==')')
				{	
					
					while(s[top]!='(')
						{
							postfix[j++]=pop();
							
						}
						top--;
					
				}
			else if(isOperand(c)==1)
			{
				postfix[j++]=c;
				
				
			}
			else
			{
				if(precedence(s[top])>=precedence(c))
					postfix[j++]=pop();
					
					
				push(c);
			
			
			}		
			
		
		
		
		}


while(top!=-1){
postfix[j++]=pop();}

postfix[j]='\0';

printf("%s\n", postfix);





return 0;





}