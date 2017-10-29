#include <stdio.h>
#include <stdlib.h>

struct node
{
	char ssn[20], name[20], dept[20], desg[20];
	int salary, mob;
	struct node *next, *prev;
};

struct node *first = NULL;

struct node * create()
{
	struct node *new;
	new = (struct node *) malloc(sizeof(struct node));
	if(new==NULL)
		printf("Memory couldn't be allocated!\n");
	else
	{
		printf("Enter SSN : ");
		scanf("%s", new->ssn);
		printf("Enter Name : ");
		scanf("%s", new->name);
		printf("Enter Department : ");
		scanf("%s", new->dept);
		printf("Enter Designation : ");
		scanf("%s", new->desg);
		printf("Enter Salary : ");
		scanf("%d", &new->salary);
		printf("Enter Phone No. : ");
		scanf("%d", &new->mob);

		new->next=NULL;
		new->prev=NULL;
	}
	return new;

}
void createList()
{
	int n;
	struct node *employee, *temp;
	printf("Enter the no. of Employees : ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		printf("Enter the Details of Employee %d\n", i);
		employee=create();
		if(first==NULL)
			first=employee;
		else
		{
			temp=first;
			while(temp->next!=NULL)
				temp=temp->next;

			temp->next=employee;
			employee->prev=temp;
		}
	}
}
void insertEnd()
{
	struct node *new, *temp;
	temp=first;
	new=create();	
	if(temp==NULL)
		first=new;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=new;
		new->prev=temp;
	}
}

void display()
{	int count=0;
	struct node *temp;
	temp=first;
	if(temp==NULL)
		printf("List is Empty!\n");
	else
	{
		printf("The Employee Details are : \n");
		while(temp!=NULL)
		{
			printf("SSN         : %s\n", temp->ssn);
			printf("Name        : %s\n", temp->name);
			printf("Department  : %s\n", temp->dept);
			printf("Designation : %s\n", temp->desg);
			printf("Salary      : %d\n", temp->salary);
			printf("Phone No.   : %d\n", temp->mob);
			printf("\n\n");
			count++;
			temp=temp->next;
		}
		printf("\nTotal No. of Employee(s) are : %d\n", count);
	}
}
void deleteEnd()
{
	struct node *temp;
	temp=first;
	if(temp==NULL)
		printf("List is Empty!\n");
	else if(first->next==NULL)
	{
		printf("The deleted employee's SSN is : %s\n", first->ssn);
		first=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		temp->prev->next=NULL;
		free(temp);
	}
}
void insertFront()
{
	struct node *new;
	new=create();
	if(first==NULL)
		first=new;
	else
	{
		new->next=first;
		new->next->prev=new;
		new->prev=NULL;
		first=new;
	}
}
void deleteFront()
{
	struct node *temp;
	if(first==NULL)
		printf("List is Empty!\n");
	else if(first->next==NULL)
	{
		printf("The deleted employee's SSN is : %s\n", first->ssn);
		first=NULL;
		free(temp);
	}
	else
	{
		temp=first;
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		temp->next->prev=NULL;
		first=temp->next;
		free(temp);
	}
}
void queue()
{
	int ch;
	while(1)
	{
		printf("Double Ended Queue Operations : \n");
		printf("1. Insert Rear\n2. Delete Rear\n3. Insert Front\n4. Delete Front\n5. Display\n6. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : insertEnd();
					 break;
			case 2 : deleteEnd();
					 break;
			case 3 : insertFront();
					 break;
			case 4 : deleteFront();
					 break;
			case 5 : display();
					 break;
			case 6 : return;
		}
	}
}
int main()
{
	int i;
	while(1)
	{
		printf("Doubly Linked List Operations : \n");
		printf("1. Create\n2. Status\n3. Insert End\n4. Delete End\n5. Insert Front\n6. Delete Front\n7. Double Ended Queue\n8. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &i);

		switch(i)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : insertEnd();
					 break;
			case 4 : deleteEnd();
					 break;
			case 5 : insertFront();
					 break;
			case 6 : deleteFront();
					 break;
			case 7 : queue();
					 break;
			case 8 : return 0;
		}
	}
}