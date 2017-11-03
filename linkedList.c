#include<stdio.h>
#include<stdlib.h>

struct node
{
	char name[20];
	char usn[20];
	char branch[20];
	int sem;
	int mob;
	struct node *next;

};

struct node *first=NULL;

struct node * create()
{
	struct node *student;
	student = (struct node *) malloc(sizeof(struct node));
	if(student==NULL)
	{
		printf("Memory couldn't be allocated!");
		return NULL;	
	}
	
	printf("\nEnter Name :");
	scanf("%s", student->name);
	printf("Enter USN :");
	scanf("%s", student->usn);
	printf("Enter Branch :");
	scanf("%s", student->branch);
	printf("Enter Sem :");
	scanf("%d", &student->sem);
	printf("Enter Phone No. :");
	scanf("%d", &student->mob);

	student->next=NULL;

	return student;

}
void createList()
{
	int n;
	struct node *new;
	
	printf("Enter the number of students : ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
	{
		printf("\nEnter the details of the student %d", i);
		new=create();

		if(first==NULL)
			first=new;
		else
		{
			new->next=first;
			first=new;		
		}
		
		
	}

}
void push()
{
	struct node *new;
	new = create();
	if(first==NULL)
		first=new;
	else
	{

			new->next=first;
			first=new;
	}

}
void pop()
{
	
	struct node *temp;
	temp=first;

	if(first==NULL)
	{
		printf("\nList is Empty!\n");
		return;
	}

	printf("The deleted student's USN is : %s\n", temp->usn);
	
	if(temp->next==NULL)
	{
		free(temp);
		first=NULL;
	}
	else
	{
		first = temp->next;
		free(temp);	
		
	}
	
}

void insertEnd()
{
	struct node *new, *temp;
	new = create();
	if(first==NULL)
	{
		first=new;
		return;
	}

	temp=first;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=new;

}
void deleteEnd()
{
	struct node *temp, *prev;
	temp=first;
	
	if(first==NULL)
	{
		printf("\n\nList is Empty!\n\n");
		return;
	}

	if(temp->next==NULL)
	{
		printf("The deleted student's USN is : %s\n", temp->usn);
		free(temp);
		first=NULL;
	}
	else
	{
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	
	printf("The deleted student's USN is : %s\n", temp->usn);
	prev->next=NULL;
	free(temp);
	}

}
void display()
{
	struct node *temp;
	int count=0;
	temp=first;
	if(first==NULL)
	{
		printf("List is Empty!\n");
		return;

	}

	printf("\nThe Student details are : \n");
	while(temp!=NULL)
	{
		
		printf("Name          : %s\n", temp->name);
		printf("USN           : %s\n", temp->usn);
		printf("Branch        : %s\n", temp->branch);
		printf("Sem           : %d\n", temp->sem);
		printf("Phone No.     : %d\n\n", temp->mob);
		count++;
		temp=temp->next; 


	}
	printf("\nThe number of students (nodes) are : %d\n", count);

}
int main()
{
	int i;
	while(1)
	{
		printf("\nLinked List Operations : \n");
		printf("\n1. Create List\n2 .Display\n3. Push\n4. Pop\n5. Insert End\n6. Delete End\n7. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &i);		
		switch(i)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : push();
					 break;
			case 4 : pop();
					 break;
			case 5 : insertEnd();
					 break;
			case 6 : deleteEnd();
					 break;
			case 7 : return 0;
		
			default : printf("Invalid Choice!\n");


		}
	




	}









}

























