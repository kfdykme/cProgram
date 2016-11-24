#include <stdio.h>
#include <ctype.h>
void read_word(int counts[26]);
bool equal_array(int counts1[26],int counts2[26]);

int main(void){
	
	int alpha1[26] = {0};
	int alpha2[26] = {0};
	
	
	printf("Enter first word: ");
	
	read_word(alpha1);
	
	
	printf("Enter second word: ");
	
	read_word(alpha2);
	
	if( equal_array(alpha1,alpha2) )
		printf("The words are anagrams.");
	else
		printf("The words are not anagrams.");
			
	return 0;
	
}
void read_word(int counts[26]){
	char a;
	do{
		a = toupper(getchar()) ;
		counts[a-'A']++;
	} while (a != '\n');
	
	
}

bool equal_array(int counts1[26],int counts2[26]){
	for (int i = 0;i<26;i++)
		if (counts1[i] - counts2[i] != 0)
			return false;
		
	return true;
}
	

	