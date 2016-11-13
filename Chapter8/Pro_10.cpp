#include <stdio.h>
#include <ctype.h>

#define LEN 8

int main(void){
	// 将起飞时间储存在数组中
	int departureTimeinM[LEN]={
		480,583,679,767,840,945,1140,1305};
	// 将抵达时间储存在数组中
	int arrivingTimeinM[LEN] = {
		616,712,811,900,968,1075,1250,1438};
	int enterHour,enterMin;
	int outputTimeinM,closestDepartureTimeinM;
	
	int m1,m2,enterTimeinM = enterHour * 60 + enterMin;
	
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&enterHour,&enterMin);
	
	for (int i = 0; i<LEN;i++){
		m1 = enterTimeinM - departureTimeinM[i] > 0 ? enterTimeinM - departureTimeinM[i]: 0;
		printf("m1: %d\n",m1);
		m2 = departureTimeinM[i+1]- enterTimeinM > 0  ?  departureTimeinM[i+1]- enterTimeinM : 0;
		printf("m2: %d\n",m2);
		closestDepartureTimeinM = m1 < m2 ? departureTimeinM[i] :departureTimeinM[i+1];
		printf("closestDepartureTimeinM: %d\n",closestDepartureTimeinM);
		closestDepartureTimeinM = closestDepartureTimeinM > 780 ? closestDepartureTimeinM - 720 :closestDepartureTimeinM;
		printf("closestDepartureTimeinM: %d\n",closestDepartureTimeinM);
		outputTimeinM = m1 < m2? arrivingTimeinM[i] : arrivingTimeinM[i+1];
		outputTimeinM = outputTimeinM > 780 ? outputTimeinM - 720 :outputTimeinM;
		printf("outputTimeinM: %d\n",outputTimeinM);
		
		i = departureTimeinM[i+1]- enterTimeinM > 0 &&
		enterTimeinM - departureTimeinM[i] > 0? LEN : i;
		} 
		
	printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.", (closestDepartureTimeinM - closestDepartureTimeinM % 60)/60,
	 closestDepartureTimeinM % 60,
	 closestDepartureTimeinM > 720 ? 'p':'a',
	 (outputTimeinM - outputTimeinM % 60)/60,
	 outputTimeinM % 60,
	 outputTimeinM > 720 ? 'p':'a');
	
	return 0;
	
}