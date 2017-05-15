#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
void StrInsert(char *S,char *T,int i);

void StrInsert(char *S, char *T, int i)
{
	printf("S is %s\n"
	       "T is %s\n",S,T);
	int len = strlen(S);
	if (len < i ) return ;
	char *temps;
	temps =  (char*)malloc(sizeof(char)* len);
	strcpy(temps,S+i);
	printf("temps is %s\n",temps);
	printf("%d %c\n",i, *(S+i));
	*(S+i) = '\0';
	
	
	printf("S is %s\n",S);
	strcat(S,T);
	printf("S is %s\n",S);
	strcat(S,temps);
	printf("S is %s\n",S);
	
}
int main(void)
{
	char s1[M], s2[M];
	strcpy(s1,"abcdefghijklmn");
	strcpy(s2,"****");
	StrInsert(s1,s2,4);
	return 0;
}