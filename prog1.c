#include<stdio.h>

int n;
void create(int a[])
{
	printf("Enter the no. of elements : ");
	scanf("%d", &n);
	printf("Enter the elements : ");
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}

void display(int a[])
{
	for(int i=0; i<n; i++)
		{
			printf("%d ", a[i]);		

		}
	printf("\n");
}

void insert(int a[])
{	int key, pos;
	printf("Enter the Element : ");
	scanf("%d", &key);
	printf("Enter the index of the element : ");
	scanf("%d", &pos);
	
	for(int i=n; i>=pos; i--)
		{
			a[i+1] = a[i];

		}
	a[pos] = key;
	n = n+1;

}

void delete(int a[])
{	int pos;
	printf("Enter the index of element to be deleted : ");
	scanf("%d", &pos);
	
	for(int i=pos; i<n; i++ )
		{
			a[i] = a[i+1];

		}
	n = n-1;

}

int main()

{
	int a[50];
	

	while(1)
		{	
			int x;
			printf("1. Create Array\n");
			printf("2. Display Array\n");
			printf("3. Insert Element\n");
			printf("4. Delete Element\n");
			printf("5. Exit\n");
			scanf("%d", &x);
			switch(x)
				{
					case 1 : create(a);
								break;
					case 2 : display(a);
								break;
					case 3 : insert(a);
								break;
					case 4 : delete(a);
								break;
					case 5 : return 0;
					
					default : printf("Invalid Option!\n");


				}		


		}

}
