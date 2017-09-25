#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[n], count[101]={0}, result=0;
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
		count[a[i]]++;

	}

	for (int i=0; i<=100; ++i)
		if(count[i]!=0)
		result=result+(count[i]/2);
	
	printf("%d\n", result);
}