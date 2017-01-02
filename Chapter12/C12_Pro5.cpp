#include <stdio.h>
#include <string.h>

#define LEN 999 
#define DEFAULT -10
#define CANCUT *c == '.'||*c == ','||*c == '!'||*c == '?'||*c == ':'||*c == ';'||*c == ' '
int main(void){
	char str[LEN],  *c = str;
	char word[LEN]; 
	char lastChar;
	
	
	printf("Enter a sentence: ");

///////////////////////////////////////////////////	读取句子	
	while((*c++ = getchar()) != '\n');
	c-=2 ;
	if (CANCUT){
		lastChar = *c;
		*c = '\0';
	}
	else{
		lastChar = ' '; 
		*++c = '\0';}
//	printf("%s\n",str);

///////////////////////////////////////////////////	切分成单词数组 对单词进行倒序

char *s = str , *e = str;
char *w = word;
while (1){
	
	if ( *e == ' ' || *e == '\0' || *e == '?'|| *e == '.'|| *e == '!' || *e == ':' ||*e == ';'){
	
	strcpy(w,s);
	*(w + (e -s) +1) = '\0';
	//printf("%s\n",w); 	
	for ( int i = e - s-1;i  >=0; i--){
		//printf("*w[%d] = %c\n", i , *(w+i));
		*s++ = *(w+i);
		//printf("*s[%d] = %c\n", i , *(s-1));
	}
	s++;
	}
	
	
	if( *e == '\0')
		break;
	*e++;
	
}



///////////////////////////////////////////////////	反向打印句子

	
	printf("Reversal of sentence: ");

	while (c-- > str)
	printf("%c",*c);
	
	if ( lastChar != ' ') printf("%c",lastChar);
	return 0;
	
}