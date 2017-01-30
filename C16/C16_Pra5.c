#include <stdio.h>

typedef struct  {
	int month, day, year;
	} Date;
	
int day_of_year(Date date);

int compare_dates(Date d1, Date d2); 
		
int main(void){
	
	Date mD;
	printf("Enter mD's month/day/year:\t");
	scanf("%d/%d/%d",&mD.month, &mD.day, &mD.year);
	
	printf("---%d–--\n", day_of_year(mD));
	
	return 0;
}

int day_of_year(Date date){
	//1 3 5 7 8 10 12 -- 31
	// 2 28/29
	
	bool isRun = false;
	
	if ( ( date.year % 100 == 0 
		&& date.year % 400 == 0)
		|| date.year % 4 == 0 )
		isRun = true;
		
	int m[12] = {31,isRun? 29:28, 31,30,31,30,31,31,30,31,30,31};
	
	int d = 0;
	
	for (int i = 0; i < date.month - 1; i++)
		d += m[i];
	
	return 	d + date.day;
}

		
int compare_dates(Date d1, Date d2){
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