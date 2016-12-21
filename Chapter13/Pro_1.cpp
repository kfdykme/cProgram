#include <stdio.h>
#include <string.h>

int main(void){
	
	char smallest_word[20],largest_word[20],current_word[20]="";
	
	char *s = smallest_word, *l = largest_word, *c = current_word;
	
	bool is = false;
	
	//printf("%d",strlen(c));
	
	while (strlen(current_word) != 4 ){
		printf("Enter word: ");
		scanf("%s",current_word);
		if(!is){
			strcpy(s,c);
			strcpy(l,c);
			is = !is;
		}
			
		if (strcmp(c,s) < 0){
			strcpy(s,c);
		 } 
		if (strcmp(c,l) > 0){
		 strcpy(l,c);
		 }
	}
	
	printf("s : %s\n",s);
	printf("l : %s",l);
	
	
	return 0;
}