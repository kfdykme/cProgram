#include <stdio.h>

void read_line(char s[]){
	char c, *p = s;
	while ( (c = getchar()) != '\n')
		*(p++) = c;
	*p = '\0';
	}
double compute_average_word_length(const char *sentence){
	float wl = 1, al = 0;
	char *c = sentence;
	//printf("c   wl  al\n");
	while ( *c != '\0'){
		//printf("%c %.1f %.1f\n",*c, wl, al);
		if ( *c == ' ' && *(c - 1 ) != ' ')
			wl = wl +1;
		if ( *c != ' ' )
			al = al +1;
		c++;
	} 
	
	return al/wl;
}
      
int main(void){
	char ss[199];
		
	printf("Enter a expression: ");
	read_line(ss);
	double a;
	//printf("%s\n",ss);
	a = compute_average_word_length(ss);
	printf("Average word length: %.1f", a);
	
	return 0;
}
	
	