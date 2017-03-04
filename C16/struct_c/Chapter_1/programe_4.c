//4. 解方程

#include <stdio.h>

#include <math.h>


//求根号 sqrt(n)

void doFunction(float x[],float a, float b , float c){
	
	if(a != 0){
	//ax2+bx+c = 0
	float dito = b*b - 4 * a * c;
	if (dito < 0){
		printf("无解\n");
	} else{
		x[0] = (((-1*b) + sqrt(dito))/(2*a));
		x[1] = (((-1*b) - sqrt(dito))/(2*a));
		printf("x1 = %g, x2 = %g\n",x[0],x[1]);
	}
	} else {
		printf("a != 0 !!!!");
	}
}
	
int main(void){
	float a[2];


	doFunction(a,0,4,1);

	return 0;
}