#include <stdio.h>
#include <ctype.h>

#define LEN 8

int main(void){
	int departureTimeinM[LEN]={
		480,583,679,767,840,945,1140,1305};
	int arrivingTimeinM[LEN] = {
		616,712,811,900,968,1075,1250,1438};
	int enterHour,enterMin;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&enterHour,&enterMin);
	
	int m1,m2,enterTimeinM = enterHour*60 + enterMin;
	
	for (int i = 0; i++; i<LEN){
		m1 = enterTimeinM - departureTimeinM[i] > 0 ? enterTimeinM - departureTimeinM[i]:0;
		m2 = departureTimeinM[i+1]- enterTimeinM > 0  ?  departureTimeinM[i+1]- enterTimeinM : 0; 
		} 
	
	//printf("Closest departure time is %d:%d",,);
	
	
}