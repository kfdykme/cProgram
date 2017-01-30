#include <stdio.h>

typedef struct  {
	int month, day, year;
	} Date;
	

int compare_dates(Date d1, Date d2); 
		
int main(void){
	Date d1, d2;
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d",&d1.month, &d1.day, &d1.year);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d",&d2.month, &d2.day, &d2.year);
	if(compare_dates(d1,d2)<0)
		printf("%d/%d/%d is earlier than %d/%d/%d. ",
		d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
	else if (compare_dates(d1,d2) >0)
		printf("%d/%d/%d is earlier than %d/%d/%d. ", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
	
	return 0;
}


int compare_dates(Date d1, Date d2){
	if (d1.year < d2.year)
		return -1;
	else if (d1.year > d2.year)
		return 1;
	else {
		if ( d1.month < d2.month )
			return -1;
		else if (d1.month > d2.month)
			return 1;
		else {
				if (d1.day < d2.day)
					return -1;
				else if (d1.day > d2.day)
					return 1;
				else 
					return 0;
			}
		}
}						