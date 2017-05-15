#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char origin[27] = "abcdefghijklmnopqrstuvwxyz";
char passw[27] = "ngzqtcobmuhelkpdawxfyivrsj";

void toPassword(char *s);
void toOrigin(char *s);

void toPassword(char *s)
{
	int len = strlen(s);
	int i =0;
	char c = *s;
	char *t;
	t = (char*) malloc(sizeof(char) * len);
	while(c != '\0')
	{
		int pos;
		for (pos= 0; pos < 26;pos++)
			 if (c == origin[pos])
			 	break;
		
		if (pos == 27) return ;
 		
 	   *(t+i) = passw[pos];	 	
		i++;
		c = *(s+i); 
	}
	strcpy(s,t);
//	printf("t %s \ns %s",t,s); 
}

void toOrigin(char *s)
{
	int len = strlen(s);
	int i =0;
	char c = *s;
	char *t;
	t = (char*) malloc(sizeof(char) * len);
	while(c != '\0')
	{
		int pos;
		for (pos= 0; pos < 26;pos++)
			 if (c == passw[pos])
			 	break;
		
		if (pos == 27) return ;
 		
 	   *(t+i) = origin[pos];	 	
		i++;
		c = *(s+i); 
	}
	strcpy(s,t);
//	printf("t %s \ns %s",t,s); 
}

int main(void)
{
	char s[100];
	strcpy(s,"encrypy");
	printf("%s\n",s);
	toPassword(s);
	printf("%s\n",s);
	toOrigin(s);
	printf("%s\n",s);
	return 0;
}