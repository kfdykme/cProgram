#include <stdio.h>

typedef struct {
	
	int number ;
	char name[20];
} Country_codes;

 Country_codes country_codes[5] = { 
	{93, "Afghanistan"},
	{213,"Algeria"},
	{376, "Andorra"},
	{1264,"Angnilla"},
	{55,"Brazil"}};
	
void search(int number);

int main(void){
	int n;
	
	printf("Enter a number to search: ");
	scanf("%d",&n);
	
	for (int i = 0 ; i < 5 ; i++){
		if (n == country_codes[i].number){
			printf("The name of %d is %s\n",n, country_codes[i].name);
			
			break;
			
	}
		else if (i == 4)
			printf("Enter current number\n");
	}
	return 0;
	
}		
			
		