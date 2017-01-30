#include <stdio.h>

typedef struct {
	
	int hour;
	int min;
} time;


typedef struct {
	time dep;
	
	time arr;
	
} TimeTable;


int main(void){
	TimeTable TT[8] = {
		{{8,0},{10,16}},
		{{9,43},{11,52}},
		{{11,19},{13,31}},
		{{12,47},{15,0}},
		{{14,0},{16,8}},
		{{15,45},{17,55}},
		{{19,0},{21,20}},
		{{21,45},{23,58}}};
	time cTime;	
	
	int dif[8], mindif_n, mindif; 
			
	printf("Enter a 24-hour time: ");
	
	scanf("%d:%d",&cTime.hour, &cTime.min);
	
	for (int i = 0; i <(sizeof (dif) / sizeof (dif[0])) ; i++){
		dif[i] = cTime.hour * 60 + cTime.min - (TT[i].dep.hour * 60 + TT[i].dep.min);
		if (dif[i] < 0) 
			dif[i] = (-1) * dif[i];
//		printf("dif[%d] = %d\n",i, dif[i] );
	}
	
	
	
	for (int i = 0; i < (sizeof (dif)/ sizeof (dif[0])) ; i++){
		if (!i){
			mindif = dif[i];
			mindif_n = i;
		}
		if (dif[i] < mindif){
			mindif_n = i;
			mindif = dif[i];
		}
//		printf("mindif = %d , mindif_n = %d\n", mindif, mindif_n);
	}
	
	printf("Closest departure time is %.2d:%.2d %c.m., arriving at %.2d:%.2d %c.m.",
			TT[mindif_n].dep.hour > 13 ? TT[mindif_n].dep.hour - 12 : TT[mindif_n].dep.hour, 
			TT[mindif_n].dep.min,
			TT[mindif_n].dep.hour > 12 ? 'p' : 'a' ,
			TT[mindif_n].arr.hour > 13 ? TT[mindif_n].arr.hour - 12 : TT[mindif_n].arr.min,
			TT[mindif_n].arr.min,
			TT[mindif_n].arr.hour > 12 ? 'p' : 'a');
	
	return 0;
	}
		