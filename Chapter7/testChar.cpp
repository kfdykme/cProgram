#include <stdio.h>

int main(void){
	char c = 'a';
	printf("%c\n", c);
	
	c = c - 'a' + 'A';
	printf("c = c - 'a' + 'A': %c\n",c);
	
	c = c - 2;
	printf("c = c - 2: %c\n",c);
	
	c = c * 2;
	printf("c = c *2 : %c\n", c);
	printf("c = c *2 %%d : %d\n", c);
	
	c = 'a' * 2 - 1;
	printf("c = 'a' * 2 - 1 ：%c\n",c);
	printf("c = 'a' * 2 - 2 %%d：%d\n",c);
	
	int i = 26;
	printf("int i = 26 %%d: %d\n",i);
	printf("int i = 26 %%c: %c\n",i);
	
}