//change 12 hour system into 24 hour system.

#include <stdio.h>
#include <ctype.h>
int main(void){
	int eHour, eMin;
	int pHour, pMin;
	char t;
	
	printf("Enter a 12 hour system time: ");
	scanf("%d :%d %c", &eHour, &eMin, &t);
	
	if ('a' <= t && t <= 'z'){
			t = toupper(t);
		}
//changer t into upper.

	switch(t){
		case 'A':  case 'AM':
			pHour = eHour;
			pMin = eMin;
			break;
		case 'P':  case 'PM':
			pHour = eHour + 12;
			pMin = eMin;
			if(pHour == 24){
				pHour = 0;
				}
			break;
	}
	
	printf("Equivalent 24-hour time: %d:%d ,", pHour, pMin);

// The first part of the program.
		
	int enterHour, enterMin, changedHour;
	
	enterHour = pHour;
	enterMin = pMin;
			
	int nowMinTime;
	int arriveHour,arriveMin;
	int am = 1;
	int minus1, minus2;
	nowMinTime = 60 * enterHour + enterMin;
	
	if ( nowMinTime <= 8 * 60){
		arriveHour = 10;
		arriveMin = 16;
		} else if (nowMinTime > 8 * 60 && nowMinTime <= 9 * 60 + 43){ 
		minus1 = nowMinTime - 8 * 60;
		minus2 = 9 * 60 + 43 - nowMinTime; 
		if ( minus1 < minus2){
			arriveHour = 10;
			arriveMin = 16;
		} else {
			arriveHour = 11;
			arriveMin = 52;
		};
	   } else if (nowMinTime > 9 * 60 + 43 && nowMinTime <= 11 * 60 + 19){
	   minus1 = nowMinTime -( 9 * 60 +43) ;
	   minus2 = 11 * 60 + 19 - nowMinTime;
	   if ( minus1 < minus2 ){
	   	arriveHour = 11;
	   	arriveMin = 52;
	   } else {
	   	arriveHour = 1;
	   	arriveMin = 31;
	   	am = 0; 
	   };
	   } else if (nowMinTime > 11 * 60 + 19 && nowMinTime <= 12 * 60 + 47 ){
	   minus1 = nowMinTime -( 11 * 60 + 19) ;
	   minus2 = 12 * 60 + 47 - nowMinTime;
	   if ( minus1 < minus2 ){
	   	arriveHour =1 ;
	   	arriveMin =31 ;
	   	am = 0;
	   } else {
	   	arriveHour = 3 ;
	   	arriveMin =00 ;
	   	am = 0;
	   };
	   } else if (nowMinTime > 12 * 60 + 47 && nowMinTime <= 14 * 60 ){
	   minus1 = nowMinTime - (12 * 60 + 47) ;
	   minus2 = 14 * 60 - nowMinTime;
	   if ( minus1 < minus2 ){
	   	arriveHour = 3;
	   	arriveMin = 00;
	   	am = 0;
	   } else {
	   	arriveHour = 4  ;
	   	arriveMin = 8;
	   	am = 0;
	   };//////
	   } else if (nowMinTime >15 * 60 + 45 && nowMinTime <= 19 * 60 ){
	   minus1 = nowMinTime - (15 * 60 + 45) ;
	   minus2 = (19 * 60 ) - nowMinTime;
	   if ( minus1 < minus2 ){
	   	arriveHour = 5 ;
	   	arriveMin = 55;
	   	am = 0;
	   } else {
	   	arriveHour = 9 ;
	   	arriveMin = 20 ;
	   	am = 0;
	   };
	   } else if (nowMinTime > 19 * 60  && nowMinTime <= 21 * 60 + 45 ){
	   minus1 = nowMinTime - (19 * 60) ;
	   minus2 = 21 * 60 + 45 - nowMinTime;
	   if ( minus1 < minus2 ){
	   	arriveHour = 9 ;
	   	arriveMin = 20;
	   	am = 0;
	   } else {
	   	arriveHour = 11 ;
	   	arriveMin = 58;
	   	am = 0;
	   };
	   } else if (nowMinTime > 21 * 60 + 45){
	   	arriveHour = 11 ;
	   	arriveMin = 58;
	   	am = 0;
	   };
	////////
	if(am = 1){
	printf(", arriving at %d :%2d a.m", arriveHour, arriveMin);
} else if (am = 0){
	printf(", arriving at %d :%2d p.m", arriveHour, arriveMin);	
};
//From Book.67/Test8	
	return 0;
}