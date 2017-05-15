#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void StrDelete(char *s,int i, int m);

void StrDelete(char *s,int i , int m)
{
	int len = strlen(s);
	
	
	printf("s %s\n",s);
	printf("len %d i %d m %d\n",len,i,m);
	if (len < i) return ;
	char *t;
	t = (char *)malloc(sizeof(char) * len);
	if (len < i + m)
	{
		strcpy(t,"");
	} else {			
	strcpy(t,s+i+m);
	}
	printf("t %s\n",t);
	*(s+i) = '\0';
	strcat(s,t);
	printf("s %s\n",s);
	
	
}

int main(void)
{

	char s1[100];
	strcpy(s1,"abcdefghijklmn");
	StrDelete(s1,6,3);
		
	return 0;
}