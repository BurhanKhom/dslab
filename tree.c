#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node * create(int data)
{
	struct node *new;
	new=(struct node *) malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Memory couldn't be allocated!\n");
		return NULL;
	}
	
	new->data=data;
	new->left=NULL;
	new->right=NULL;

	return new;
}

struct node * createTree(struct node *root)
{
	int n, x;
	struct node *new, *temp, *prev;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	while(n--)
	{
		printf("Enter the element : ");
		scanf("%d", &x);
		new=create(x);
		
		if(root==NULL)
		{
			root=new;
		}
		else
		{
		
		temp=root;
		prev=NULL;
		
		while(temp!=NULL)
		{
			prev=temp;
			if(temp->data > new->data)
				temp=temp->left;
			else
				temp=temp->right;

		}
		
		if(prev->data < new->data)
			prev->right=new;
		else
			prev->left=new;
		}
	}
	return root;
}
void inOrder(struct node *root)
{
	if(root==NULL)
		return;
	
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);

}
void preOrder(struct node *root)
{
	if(root==NULL)
		return;
	
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);

}
void postOrder(struct node *root)
{
	if(root==NULL)
		return;
	
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}
void search(struct node *root)
{
	int key, flag;
	printf("Enter the element to search : ");
	scanf("%d", &key);

	struct node *temp;
	temp=root;
	flag=0;
	if(root==NULL)
		{
			printf("Tree doesn't Exist!\n\n");
			return;
		}
	while(temp!=NULL)
	{
		if(temp->data==key)
			{
				flag=1;
				break;
			}
		else if(temp->data > key)
			temp=temp->left;
		else if(temp->data < key)
			temp=temp->right;
	
	}
	if(flag==1)
		printf("Element Found!\n");
	else
		printf("Element NOT Found!\n");

}
int main()
{
	int ch, ch2;
	struct node *root;
	root=NULL;
	
	while(1)
	{
		printf("\nBinary Search tree Operations : ");
		printf("\n1.Create\n2.Traversal\n3.Search\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1 : root = createTree(root);
					 break;
			case 2 : printf("1.In Order\n2.Pre Order\n3.Post Order\n");
					 printf("Enter your choice :");
					 scanf("%d", &ch2);
					 switch(ch2)
					 {
					 	case 1 : inOrder(root);
					 			 break;
					 	case 2 : preOrder(root);
					 			 break;
					 	case 3 : postOrder(root);
					 			break;
					 }
					 break;
			case 3 : search(root);
					 break;
			case 4 : return 0;
				
		}	
	}
}
