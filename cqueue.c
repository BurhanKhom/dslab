#include<stdio.h>
#define MAX 5

int front=-1, rear=-1;
char cq[MAX];

void insert(char elem)
{	
	
	if((front==0 && rear==MAX-1) || (front==rear+1))
	{
		printf("Queue Overflow!\n");
		return;
	}

	
		if(rear==-1)
			{
				front=0;
				rear=0;
			}
		else if(rear==MAX-1)
			rear=0;
		else
			rear++;

		cq[rear]=elem;
	
}

void delete()
{
	char del;

	if(front==-1)
	{
		printf("Queue Underflow!\n");
		return;
		
	}
	
		printf("The deleted element is : %c\n", cq[front]);
		
		if(front==rear)
		{
			front=-1;
			rear=-1;

		}
		else if(front==MAX-1)
			front=0;
		
		else
			front++;



}

void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue Empty\n");
		return;
	}

	printf("The elements of the queue are :\n");

	if(front<=rear)
	{
		for(i=front; i<=rear; i++)
			printf("%c\n", cq[i]);

	}
	else
	{
		for(i=front; i<MAX; i++)
			printf("%c\n", cq[i]);
		for(i=0; i<=rear; i++)
			printf("%c\n", cq[i]);
			
	}

}

int main()
{
	int n;
	char ele, del;
	
	while(1)
	{
		printf("Circular Queue Operation :\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &n);
		switch(n)
		{
			case 1 : printf("Enter element to insert :");
					 scanf("\n%c", &ele);
					 insert(ele);
					 break;
			case 2 : delete();
					 break;
			case 3 : display();
					 break;
			case 4 : return 0;

			default : printf("Invalid choice!\n");
		}



	}

return 0;

}
