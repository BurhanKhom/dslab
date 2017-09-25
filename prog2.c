#include<stdio.h>
#include<string.h>
void read(char str[], char pat[], char rep[])
{
	printf("Enter the Main String : ");
	scanf("%s", str);
	printf("Enter the Pattern String : ");
	scanf("%s", pat);
	printf("Enter the Replace String : ");
	scanf("%s", rep);



}

void patMatch(char str[], char pat[], char rep[])
{	
	int flag=0, count=0, strLen, patLen, i, j, k, z=0;
	strLen=strlen(str);
	patLen=strlen(pat);
	char result[100];
	for(i=0; i<strLen;)
		{		
				j=0;

				while((str[i+j]==pat[j])&&(j<patLen))
					j++;
		
				if(j==patLen)					
				{
					flag=1;
					count++;			
					for(k=0; rep[k]!='\0'; k++, z++)
						result[z]=rep[k];
						
						i+=patLen;
						
				}
				
				
				else
					{
					result[z]=str[i];
					z++;
					i++;
					}



		}
	result[z]='\0';
	
	if(flag==0)
	printf("No matches found!\n");
	else
	{
	
	printf("%d matches found \n", count);
	printf("Replaced String is : %s\n", result);	
	
	
	}
}

int main()
{
	char str[100], pat[100], rep[100];

	read(str, pat, rep);
	patMatch(str, pat, rep);

	return 0;

}

