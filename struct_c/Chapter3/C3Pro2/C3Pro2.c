#include <stdio.h>


#include <string.h>
int main(void)
{
	char s[100], *c;
	gets(s);
	c = s;
	int l = strlen(s)/2 ;
	
	LinkedStack L;
	LinkedStackInit(&L);
		printf("%d",l);
	while (*c != '\0')
	{
		if ((c-s) < l)
		{
			LinkedStackPush(&L,(int)*c);
		} 
	
		c++;
	}
	
	while (L.top != NULL)
	{
		printf("%c",LinkedStackPop(&L));
	}
	
	return 0;
}