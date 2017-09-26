#include<stdio.h>
#include<math.h>
#define MAX 100
int top=-1;
float s[MAX];

float evaluate(float op1, float op2, char operator)
{
	
	switch(operator)
	{
		case '+' : return op1+op2;
					  break;
					  
		case '-' : return op1-op2;
					  break;
					  
		case '*' : return op1*op2;
					  break;
					  
		case '/' : return op1/op2;
					  break;
					  
		case '^' : return pow(op1, op2);
					  break;
		
		case '%' : return fmod(op1, op2);
					  break;
	
	
	}



}



int isOperand(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^')
		return 0;
	else
		return 1;

}

void push(float ele)
{	
	
	
	if(top==MAX-1)
		printf("Stack Overflow!!\n");
	else
	{
		top=top+1;
		s[top]=ele;
		
	}

}

float pop()
{
	float del;
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
	int i;
	float result, op1, op2;
	char postfix[100];
	printf("Enter the postfix Expression : ");
	scanf("%s", postfix);
	
	for(i=0; postfix[i]!='\0'; i++)
		{
		
			char c=postfix[i];
			
			if(isOperand(c))
				{
					float x;
					printf("Enter the value of %c : ", c);
					scanf("%f", &x);
					push(x);
				
				}
			
			else
			{	
				op2=pop();
				op1=pop();
				result = evaluate(op1, op2, c);
				push(result);
				
			
			}
		}


printf("Result = %.2f\n", result);


return 0;


}



