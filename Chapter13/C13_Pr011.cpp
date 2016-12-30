#include <stdio.h>
#include <string.h>

int read_line(char str[]);

double compute_average_word_length(char *sentence);

int main(void){
	char s[1000], *sp = s;
	double l ;
	printf("Enter sentence: ");
	
	read_line(sp);

	l  = compute_average_word_length(s);

	printf("%lf",l);	
	return 0;
}

int  read_line(char str[]){
	char ss[1000];
	char c;
	int i = 0;
	do{
		c = getchar();
		str[i++] = c;
	}while(c != '\n');
	 str[i] = '\0';
	
	return 0;
}

double compute_average_word_length(char *sentence){
	double l = 0;
	char *p = sentence;
	bool isBlanking = false;
	double a =-1;
	double b = 1;
	while (*p++ !='\0'){
		if (*p == ' '
						||*p == '!'
						||*p == '?'
						||*p == '.'
						||*p == ','
						||*p == ';'
						||*p == '/' ){
			if (!isBlanking){
				b++;
				isBlanking = !isBlanking;
			}
						
		} else if (*p != ' '){
			a++;
			isBlanking = false;
		}
	}
//	printf("a = %lf, b = %lf\n",a,b);
		l = a/b;
		return l;
	
}