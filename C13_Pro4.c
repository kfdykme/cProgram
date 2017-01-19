#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	if (!strcmp(argv[1],"reverse"))
		for (int j = argc-1 ; j > 1;j--)
			printf("%s ",argv[j]);
		
	return 0;
}



















/*

#include <stdio.h>
#include <string.h>


int main(void){
	int i = 0;
	char order[10], c, word[100][100];
	scanf("%s", order);

	if(!strcmp(order,"reverse"))
		while ((c = getchar()) != '\n')
			scanf("%s",&word[i++]);
	
	for (int j = i-1 ; j >= 0 ; j--)
		printf("%s ",word[j]);
	return 0;
}

*/