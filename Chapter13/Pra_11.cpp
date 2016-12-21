#include <stdio.h>
/*
		用数组下标的方法实现strcmp
*/
int strcmp(char *s, char *t)
{
	int i;
	
	for ( i = 0; s[i] == t[i];i++)
		if (s[i] == '\0')
			return 0;
			
	return s[i]  - t[i];
}
/*
		用指针算术运算的方法实现strcmp
*/
int strcmp2(char *s, char *t)
{
	
	for ( ; *s == *t;s++,t++)
		if (*s == '\0')
			return 0;
			
	return *s - *t;
}

int main(void){
	

	printf("%d\n",strcmp("abaaa","ab"));
	printf("%d\n",strcmp2("abaaa","ab"));
	
		return 0;
		
			}	