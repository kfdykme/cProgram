#include <stdio.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void){
	char word1[100], word2[100];
	char *w1 = word1, *w2 = word2;
	printf("Enter first word: ");
	while((*w1++ = toupper(getchar())) != '\n' );
	*w1 = '\0';
	
	printf("Enter second word: ");
	while((*w2++ = toupper(getchar())) != '\n' );
	*w2 = '\0';
	
	printf("w1 = %s\nw2 = %s\n", word1,word2);
	
	if ( are_anagrams(word1,word2))
		printf("The words are anagrams.");
	else 
		printf("The words are not anagrams.");
	
	return 0;		
}
	
bool are_anagrams(const char *word1, const char *word2){
	
	int alpha[27] = {0};
	while(*word1 != '\0'){
		alpha[*word1 - 'A' ]++;
	//	printf("%c(%d) = %d\n",*word1,*word1- 'A',alpha[*word1 -'A']);
		word1++;
		}
//	for (int i = 0;i<26;i++)
//		printf("%c = %d\n",i +'A',alpha[i]);
	while(*word2 != '\0'){
		alpha[*word2 - 'A']--;
//		printf("%c(%d) = %d\n",*word2,*word2- 'A',alpha[*word2 -'A']);
		word2++;
	}
	
	for (int i = 0;i<26;i++){
		if (alpha[i] != 0){
			//printf("%c = %d\n",i +'A',alpha[i]);
			break;
		}
		if ( i == 25 )
			return true;
	}	
	return false;

}
