#include<stdio.h>
void tower(int n, char src, char temp, char dest)
{
	if(n==1)
	{
		printf("Move %d peg from %c to %c position\n", n, src, dest);
		return;

	}

	tower(n-1, src, dest, temp);

	printf("Move %d peg from %c to %c position\n", n, src, dest);

	tower(n-1, temp, src, dest);


}

int main()
{
	int n;
	printf("Enter n : ");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');



}