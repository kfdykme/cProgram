#include <stdio.h>

#define LEN 8

void find_closest_flight(int desired_time,int *departure_time, int *arrival_time, char *departure_am_or_pm,char *arrival_am_or_pm);
   
int main(void){
	// 将起飞时间储存在数组中
	int eH,eM,eTM;
	int oM,cDM;
	char dAoP,aAoP;
	
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&eH,&eM);
	eTM = eH * 60 + eM;
	
	
	
	find_closest_flight(eTM,&cDM, &oM,&dAoP,&aAoP); 
   
	
		
	printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.", 
	 (cDM - cDM % 60)/60,
	 cDM % 60,
	 dAoP,
	 (oM - oM % 60)/60,
	 oM % 60,
	 aAoP);
	
	return 0;
	
}

void find_closest_flight(int desired_time,int *departure_time, int *arrival_time, char *departure_am_or_pm,char *arrival_am_or_pm){
	int dM[LEN]={
		480,583,679,767,840,945,1140,1305};
	// 将抵达时间储存在数组中
	int aM[LEN] = {
		616,712,811,900,968,1075,1250,1438};
	int m1,m2;
	for (int i = 0; i<LEN;i++){
		m1 = desired_time - dM[i] >= 0 ? desired_time - dM[i]: -1;
	//	printf("m1: %d\n",m1);
	//	printf("desired_time - dM[i]: %d\n",desired_time - dM[i]);
		m2 = dM[i+1]- desired_time >= 0  ?  dM[i+1]- desired_time : -1;
	//	printf("m2: %d\n",m2);
		*departure_time = m1 < m2 ? dM[i] :dM[i+1];
//		printf("cDM: %d\n",cDM);
		*departure_am_or_pm = *departure_time > 720 ? 'p' : 'a'; 
		*departure_time = *departure_time > 780 ? *departure_time - 720 :*departure_time;
	//	printf("cDM: %d\n",cDM);
		
		*arrival_time = m1 < m2? aM[i] : aM[i+1];
		*arrival_am_or_pm = *arrival_time > 720 ? 'p' : 'a';
		*arrival_time = *arrival_time > 780 ? *arrival_time - 720 :*arrival_time;
	//	printf("oM: %d\n",oM);
		
		i = dM[i+1]- desired_time > -1 &&
		desired_time - dM[i] > -1? LEN : i;
		} 
}
