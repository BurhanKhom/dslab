#include <stdio.h>
#include <stdlib.h>

struct node
{
	char usn[20];
	char name[20];
	char branch[20];
	int sem;
	int mob;
	struct node *next;
};

struct node *first = NULL;

struct node* create()
{
	struct node *new;

	new = (struct node *) malloc(sizeof(struct node));

	if(new==NULL)
		{
			printf("Memory couldn't be allocated!\n");
			return NULL;
		}
		else
		{
		printf("Enter the details of the student : \n");
		printf("USN : ");
		scanf("%s", new->usn);
		printf("Name : ");
		scanf("\n%s", new->name);
		printf("Branch : ");
		scanf("\n%s", new->branch);
		printf("Sem : ");
		scanf("\n%d", &new->sem);
		printf("Phone No. : ");
		scanf("\n%d", &new->mob);

		new->next=NULL;

		return new;
		}
}
void createList()
{
	int n;
	struct node *student;

	printf("Enter the number of students : ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		student=create();
		if(first==NULL)
			first=student;
		else
		{
			student->next=first;
			first=student;
		}
	}

}
void display()
{
	struct node *temp;
	if(first==NULL)
	{
		printf("List is Empty!\n");
		return;
	}
	
	temp=first;
	printf("The student details are : \n");
	while(temp!=NULL)
	{
		printf("\nName      : %s\n", temp->name);
		printf("USN       : %s\n", temp->usn);
		printf("Branch    : %s\n", temp->branch);
		printf("Sem       : %d\n", temp->sem);
		printf("Phone No. : %d\n\n", temp->mob);
		temp=temp->next;
	}
}
void push()
{
	struct node *new;
	new=create();
	if(first==NULL)
	{
		first=new;
		return;
	}

	new->next=first;
	first=new;

}
void pop()
{
	struct node *temp;
	temp=first;

	if(first==NULL)
		printf("List is Empty!\n");
	else if(temp->next==NULL)
		{
			printf("The delete student's USN is : %s\n", temp->usn);
			free(temp);
			first=NULL;
		}
	else
	{
		first=temp->next;
		printf("The delete student's USN is : %s\n", temp->usn);
		free(temp);
	}
}
void InsertEnd()
{
	struct node *new, *temp;
	temp=first;
	
	new=create();

	if(first==NULL)
	{
		first=new;
		new->next=NULL;
	}	
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=new;
	}

}
void deleteEnd()
{
	struct node *temp, *prev;
	temp=first;

	if(first->next==NULL)
		printf("List is Empty\n");
	else
	{
		temp=first;
		while(temp->next!=NULL)
			{	prev=temp;
				temp=temp->next;
			}
			prev->next=NULL;
			printf("The delete student's USN is : %s\n", temp->usn);
			free(temp);
	}
}
int main()
{
	int i;

	while(1)
	{
		printf("1.Create\n2.Status\n3.Insert End\n4.Delete End\n5.Push\n6.Pop\n7.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &i);
		switch(i)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : InsertEnd();
					 break;
			case 4 : deleteEnd();
					 break;
			case 5 : push();
					 break;
			case 6 : pop();
					 break;
			case 7 : return 0;

		}
	}
}
