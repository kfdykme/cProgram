#include <stdio.h>

#define LEN 8
 
int main(void){
	// 将起飞时间储存在数组中
	int dM[LEN]={
		480,583,679,767,840,945,1140,1305};
	// 将抵达时间储存在数组中
	int aM[LEN] = {
		616,712,811,900,968,1075,1250,1438};
	int eH,eM;
	int oM,cDM;
	int m1,m2,eTM;
	char dAoP,aAoP;
	
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&eH,&eM);
	eTM = eH * 60 + eM;
	for (int i = 0; i<LEN;i++){
		m1 = eTM - dM[i] >= 0 ? eTM - dM[i]: -1;
	//	printf("m1: %d\n",m1);
	//	printf("eTM - dM[i]: %d\n",eTM - dM[i]);
		m2 = dM[i+1]- eTM >= 0  ?  dM[i+1]- eTM : -1;
	//	printf("m2: %d\n",m2);
		cDM = m1 < m2 ? dM[i] :dM[i+1];
//		printf("cDM: %d\n",cDM);
		dAoP = cDM > 720 ? 'p' : 'a'; 
		cDM = cDM > 780 ? cDM - 720 :cDM;
	//	printf("cDM: %d\n",cDM);
		
		oM = m1 < m2? aM[i] : aM[i+1];
		aAoP = oM > 720 ? 'p' : 'a';
		oM = oM > 780 ? oM - 720 :oM;
	//	printf("oM: %d\n",oM);
		
		i = dM[i+1]- eTM > -1 &&
		eTM - dM[i] > -1? LEN : i;
		} 
		
	printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.", 
	 (cDM - cDM % 60)/60,
	 cDM % 60,
	 dAoP,
	 (oM - oM % 60)/60,
	 oM % 60,
	 aAoP);
	
	return 0;
	
}