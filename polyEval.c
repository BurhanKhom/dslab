#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	
int c, x, y, z;
struct node *next;

};

/*struct node * insertEnd(struct node *head)
{
	struct node *new, *temp;
	new = create();
	if(first==NULL)
	{
		first=new;
		return;
	}

	temp=head->next;

	while(temp!=head)
		temp=temp->next;
	
	temp->next=new;
	new->next=head;
	
	return head;
	
}
*/
void input(struct node *head)
{
	struct node *new, *temp;
	int c;
	
	while(1){

	new=(struct node *) malloc(sizeof(struct node));
	printf("Enter coeff : ");
	scanf("%d", &c);
	if(c==0)
		{
			break;
			return;
		}
	
	new->c=c;	
	printf("Enter power of x : ");
	scanf("%d", &new->x);
	printf("Enter power of y : ");
	scanf("%d", &new->y);
	printf("Enter power of z : ");
	scanf("%d", &new->z);

	if(head->next==head)
	{	head->next=new;
		new->next=head;
	}
	else{

	temp=head->next;
	while(temp->next!=head)
		temp=temp->next;

	temp->next=new;
	new->next=head;

	}
	}

}

void display(struct node *head)
{
	struct node *temp;
	temp=head->next;
	while(temp!=head)
	{
		printf("%dx^%dy^%dz^%d+", temp->c, temp->x, temp->y, temp->z);
		temp=temp->next;	
	}
	printf("0\n");
}
int evaluate(struct node *head)
{
	int x, y, z;
	printf("Enter the value of x : ");
	scanf("%d", &x);
	printf("Enter the value of y : ");
	scanf("%d", &y);
	printf("Enter the value of z : ");
	scanf("%d", &z);

	struct node *temp;
	temp=head->next;
	int sum=0;
	while(temp!=head)
	{
		sum=sum+(temp->c*pow(x, temp->x)*pow(y, temp->y)*pow(z, temp->z));
		temp=temp->next;

	}
	return sum;
}
int main()
{
	struct node *head;
	head = (struct node *) malloc(sizeof(struct node));
	head->next=head;
	
	input(head);

	display(head);
	int res = evaluate(head);
	printf("Polynomial evaluate to : %d\n", res);

}



