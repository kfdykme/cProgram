#include<stdio.h>
int main(void){
	int minM,m,minD,d,minY,y;
	minY = 100;
	minD = 100;
	minM = 100;
	while( m != 0||d !=0||y != 0){
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d",&m,&d,&y);
	if (m == 0&&d==0&&y ==0)
	break;
	if ( y < minY){
		minY = y;
		minM = m;
		minD = d;
	} else if ( y == minY){
		if ( m < minM){
	    	minM = m;
    		minD = d;
    	} else if ( m == minM){
    		if (d < minD){
    			minD = d;
    		}
    	}
	}
	}
	
	printf("%d/%d/%d is the earliest date.\n", minM, minD, minY);
	
	return 0;
	
}
	