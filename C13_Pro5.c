#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int sum = 0;
	if (!strcmp(argv[1],"sum"))
		for (int i = 2; i < argc ; i++)
			sum += atoi(argv[i]);

	printf("Total: %d",sum);
	return 0;
}










/*
#include <stdio.h>
#include <string.h>


int main(void){
	int i = 0,num[100], sum = 0;
	char order[10], c;
	scanf("%s", order);

	if(!strcmp(order,"sum"))
		while ((c = getchar()) != '\n')
			scanf("%d",&num[i++]);
	
	for (int j = i-1 ; j >= 0 ; j--)
		sum += num[j];
	
	printf("Total: %d ",sum);
	return 0;
}
*/