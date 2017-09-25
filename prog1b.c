#include<stdio.h>
#include<string.h>
int n;
void create(char a[50][50])
{
	printf("Enter the no. of strings : ");
	scanf("%d", &n);
	printf("Enter the strings : ");
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);
}

void display(char a[50][50])
{
	for(int i=0; i<n; i++)
		{
			printf("%s ", a[i]);		

		}
	printf("\n");
}

void insert(char a[50][50])
{	char key[50];
	int pos;
	printf("Enter the String : ");
	scanf("%s", key);
	printf("Enter the index : ");
	scanf("%d", &pos);
	
	for(int i=n; i>=pos; i--)
		{
			strcpy(a[i+1],a[i]);

		}
	strcpy(a[pos],key);
	n = n+1;

}

void delete(char a[50][50])
{	int pos;
	printf("Enter the index of string to be deleted : ");
	scanf("%d", &pos);
	
	for(int i=pos; i<n; i++ )
		{
			strcpy(a[i], a[i+1]);

		}
	n = n-1;

}

int main()

{
	char a[50][50];
	

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
