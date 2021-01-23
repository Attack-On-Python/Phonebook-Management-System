#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *f;
	f=fopen("file.csv","r");
	const char s[2]=", ";
	char *token;
	char str[70];
	for (int i=0;i<3;i++)
	{
		if (fgets(str,60,f)!=NULL)
		{
			puts(str);
		}
		token=strtok(str,s);
	}
	while(token!=NULL)
	{
		printf("%s\n",token);
	}
	fclose(f);
	return 0;
}
