#include<stdio.h>
#include<stdlib.h>

struct node
{
	char ssn[20];
	char name[20];
	char dept[20];
	char desg[20];	
	int salary;
	int mob;
	struct node *next, *prev;

};

struct node *first=NULL;

struct node * create()
{
	struct node *new;
	new = (struct node *) malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Memory couldn't be allocated!");
		return NULL;	
	}
	
	printf("\nEnter Name :");
	scanf("%s", new->name);
	printf("Enter SSN :");
	scanf("%s", new->ssn);
	printf("Enter Department :");
	scanf("%s", new->dept);
	printf("Enter Designation :");
	scanf("%s", new->desg);
	printf("Enter Salary :");
	scanf("%d", &new->salary);
	printf("Enter Phon No. : ");
	scanf("%d", &new->mob);

	new->next=NULL;

	return new;

}
void createList()
{
	int n;
	struct node *new, *temp;
	
	printf("Enter the number of employees : ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
	{
		printf("\nEnter the details of the employee %d", i);
		new=create();
		new->next=NULL;
		new->prev=NULL;
	
		if(first==NULL)
			first=new;
			
		else
		{
			temp=first;
			while(temp->next!=NULL)
				temp=temp->next;
			
			new->prev=temp;			
			temp->next=new;
					
		}
		
		
	}

}
void insertBegin()
{
	struct node *new;
	new = create();
	new->next=NULL;
	new->prev=NULL;

	if(first==NULL)
		first=new;
	else
	{
			new->next=first;
			first->prev=new;
			first=new;
	}

}
void deleteBegin()
{
	
	struct node *temp;
	temp=first;

	if(first==NULL)
	{
		printf("\nList is Empty!\n");
		return;
	}

	printf("The deleted employee's SSN is : %s\n", temp->ssn);
	
	if(temp->next==NULL)
	{
		free(temp);
		first=NULL;
	}
	else
	{
		first = temp->next;
		first->prev=NULL;
		free(temp);	
		
	}
	
}

void insertEnd()
{
	struct node *new, *temp;
	new = create();
	new->next=NULL;
	new->prev=NULL;
	if(first==NULL)
	{
		first=new;
		return;
	}

	temp=first;

	while(temp->next!=NULL)
		temp=temp->next;
	
	new->prev=temp;	
	temp->next=new;
	

}
void deleteEnd()
{
	struct node *temp;
	temp=first;
	
	if(first==NULL)
	{
		printf("\n\nList is Empty!\n\n");
		return;
	}

	if(temp->next==NULL)
	{
		printf("The deleted employee's SSN is : %s\n", temp->ssn);
		free(temp);
		first=NULL;
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
		
		printf("Name        : %s\n", temp->name);
		printf("SSN         : %s\n", temp->ssn);
		printf("Department  : %s\n", temp->dept);
		printf("Desgination : %s\n", temp->desg);
		printf("Salary      : %d\n", temp->salary);
 		printf("Phone No.   : %d\n\n", temp->mob);
		count++;
		temp=temp->next; 


	}
	printf("\nThe number of employees (nodes) are : %d\n", count);

}
/*void queue()
{
	int ch;
	while(1)
	{
		printf("Double Ended Queue Operations: \n");
		printf("1. Insert Front\n2. Delete Front\n3. Insert Rear\n4. Delete Rear\n5. Display\n6. Go Back\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : insertBegin();
					 break;
			case 2 : deleteBegin();
					 break;
			case 3 : insertEnd();
					 break;
			case 4 : deleteEnd();
					 break;
			case 5 : display();
					 break;
			case 6 : return;

		}
	}
}*/
void insert_or_delete_E()
{
	int ch;
	printf("   1. Insert\n   2. Delete\n");
	printf("Enter your choice : ");
	scanf("%d", &ch);
	if(ch==1)
		insertEnd();
	else if(ch==2)
		deleteEnd();
	else
		printf("Invalid Choice!\n");

	return;


}
void insert_or_delete_F()
{
	int ch;
	printf("   1. Insert\n   2. Delete\n");
	printf("Enter your choice : ");
	scanf("%d", &ch);
	if(ch==1)
		insertBegin();
	else if(ch==2)
		deleteBegin();
	else
		printf("Invalid Choice!\n");

	return;


}
int main()
{
	int i;
	while(1)
	{
		printf("\nDoubly Linked List Operations : \n");
		printf("\n1. Create\n2. Display\n3. Insert/Delete at End\n4. Insert/Delete at Front\n5. Exit\n\n");    
		printf("Enter your choice : ");
		scanf("%d", &i);		
		switch(i)
		{
			case 1 : createList();
					 break;
			case 2 : display();
					 break;
			case 3 : insert_or_delete_E();
					 break;
			case 4 : insert_or_delete_F();
					 break;
			case 5 : return 0;
		
			default : printf("Invalid Choice!\n");
		}
	}
}




