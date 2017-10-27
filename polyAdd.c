#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	
int c, x, y, z;
struct node *next;

};
struct node * insertEnd(struct node *head, int c, int x, int y, int z)
{
	struct node *new, *temp;
	new=(struct node *)malloc(sizeof(struct node));
	new->c=c;
	new->x=x;
	new->y=y;
	new->z=z;
	if(head->next==head)
	{
		head->next=new;
		new->next=head;
		return head;
	}

	temp=head->next;
	while(temp->next!=head)
		temp=temp->next;
	
	temp->next=new;
	new->next=head;
	
	return head;
	
}

void input(struct node *head)
{
	struct node *new, *temp;
	int c, x, y, z;
	
	while(1){
	printf("Enter coeff : ");
	scanf("%d", &c);
	if(c==0)
		{
			break;
			return;
		}
	
	
	printf("Enter power of x : ");
	scanf("%d", &x);
	printf("Enter power of y : ");
	scanf("%d", &y);
	printf("Enter power of z : ");
	scanf("%d", &z);

	insertEnd(head, c, x, y, z);
	}

}

void display(struct node *head)
{
	struct node *temp;
	temp=head->next;
	while(temp->next!=head)
	{
		printf("%d(x)^%d(y)^%d(z)^%d + ", temp->c, temp->x, temp->y, temp->z);
		temp=temp->next;	
	}
	printf("%d(x)^%d(y)^%d(z)^%d\n", temp->c, temp->x, temp->y, temp->z);
}
struct node * polynomialAdd(struct node *head1, struct node *head2, struct node *head3)
{
	struct node *temp1, *temp2;
	int flag;

	temp1=head1->next;
	while(temp1!=head1)
	{	
		flag=0;
		temp2=head2->next;	
		while(temp2!=head2)
		{
			if((temp1->x == temp2->x) && (temp1->y == temp2->y) && (temp1->z == temp2->z))
			{
				head3 = insertEnd(head3, (temp1->c)+(temp2->c), temp1->x, temp1->y, temp1->z);
				temp2->c=0;
				flag=1;
				break;
			}
			else
				temp2=temp2->next;
		}
		if(flag==0)
			head3=insertEnd(head3, temp1->c, temp1->x, temp1->y, temp1->z);

		temp1=temp1->next;
	}
	temp2=head2->next;
	while(temp2!=head2)
	{
		if(temp2->c!=0)
			head3=insertEnd(head3, temp2->c, temp2->x, temp2->y, temp2->z);

		temp2=temp2->next;
	}
	return head3;
}
int main()
{	
	printf("\n\n*****ENTER COEFFICIENT AS 0 TO END POLYNOMIAL*****\n\n");
	struct node *head1, *head2, *head3;
	head1 = (struct node *) malloc(sizeof(struct node));
	head1->next=head1;
	head2 = (struct node *) malloc(sizeof(struct node));
	head2->next=head2;
	head3 = (struct node *) malloc(sizeof(struct node));
	head3->next=head3;
	
	printf("Enter Polynomial 1 \n");
	input(head1);
	printf("Entered Polynomial 1 : ");
	display(head1);
	printf("\nEnter Polynomial 2 \n");
	input(head2);
	printf("Entered Polynomial 2 : ");
	display(head2);
	head3 = polynomialAdd(head1, head2, head3);
	printf("\n\nPolynomial 1 + Polynomial 2 = ");
	display(head3);
	printf("\n");

}



