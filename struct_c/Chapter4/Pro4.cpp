#include <stdio.h>

int strcmp(char *s1,char *s2);
int strcmp(char *s1,char *s2){
	
	int pos =0;

	int len1 = 0,len2 = 0;
	
	while (*(s1+len1)!='\0')len1++;
	while (*(s2+len2)!='\0')len2++;

	printf("len1 %d len2 %d\n",len1, len2);
	
	if (len1 != len2) return  0;
	
	for (; pos <=len1;pos++)
	{
		if (*(s1+pos) != *(s2+pos))
			return 0;
	}
	return 1;
}

int main(void)
{
	char s[100] = "abc";
	char s2[100] = "abc";
	
	printf("%c",strcmp(s,s2) ? 't':'f');
	
	return 0;
}