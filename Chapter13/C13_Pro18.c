#include <stdio.h>
#include <string.h>

int main(void){
	int m, d, y;
	char s[20], *mouth[] = {"January","February","March","April",
						  "May","June","July","August",
						  "September","October","November",
						  "December"};
	
	char s2[20];
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&m, &d, &y);
	
	strcpy(s,mouth[m-1]);
	sprintf(s2," %d, %d",d,y);
	strcat(s,s2);
	printf("You entered the date %s",s);
	
	return 0;
}
	
	