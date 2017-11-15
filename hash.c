#include<stdio.h>
#define MAX 20
int f[MAX], ht[MAX], l;

void linear(int k, int key)
{
	l=k%MAX;
	if(ht[l]==0)
		ht[l]=key;
	else
		linear(k+1, key);
}
void display()
{
	int i;
	printf("Hash Table : \n");
	for(i=0; i<MAX; i++)
		printf("%d\n", ht[i]);
}
int main()
{	
	FILE *fp;
	int i=0;
	char buff[100];
	fp=fopen("data.txt", "r");
	while(fscanf(fp, "%d", &f[i]) != EOF)
		{
			fscanf(fp, "%[^\n]s", buff);
			i++;
		}
	for(i=0; i<MAX; i++)
	{
		l=f[i]%MAX;
		if(ht[l]==0)
			ht[l]=f[i];
		else
			linear(f[i]+1, f[i]);
	}
	display();
	return 0;
}