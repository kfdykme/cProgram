#include <stdio.h>
#include <math.h>

#define DISP(f,x) printf(#f "(%g) = %g\n",(x),(f(x)))
#define DIS2P(f,a,b) printf(#f"(%g,%g) = %g",a, b, f(a,b))

double m(double a, double b){
	return a + b;
}

double sqrt(double a){
	return a + 3.1;
}

int main(void){
	
	DISP(sqrt,3.0);
	
	DIS2P(m,4.0,5.5);
	return 0;
}