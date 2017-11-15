#include<stdio.h>
int n, g[20][20], visited[20], q[20], f=0, r=-1;

void dfs(int c)
{	
	int i;
	printf("%d ", c);
	visited[c]=1;
	for(i=0; i<n; i++)
		if(!visited[i] && g[c][i]==1)
			dfs(i);
}

void bfs(int c)
{
	int i;
	for (i=0; i<n; ++i)
		if(!visited[i] && g[c][i]==1)
			q[++r]=i;

	if(f<=r)
	{
		visited[q[f]]=1;
		printf("%d ", q[f]);
		bfs(c);
	}

}

int main()
{
	int i, j, ch, c;
	while(1)
	{
		printf("Enter the number of cities : ");
		scanf("%d", &n);
		printf("Enter the adjancency matrix \n");

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d", &g[i][j]);
		printf("Enter the starting city : ");
		scanf("%d", &c);

		for (i=0; i<n; i++)
			visited[i]=0;

		printf("1. DFS\n2.BFS\n3.Exit");
		scanf("%d", &ch);
		printf("Cities recheable : ");
		switch(ch)
		{
			case 1 : dfs(c);
					 break;
			case 2 : bfs(c);
					 break;
			case 3 : return 0;
		}
	}
}