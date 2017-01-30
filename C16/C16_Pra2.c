#include <stdio.h>

struct {
	double real, imaginary;
} c1 = { 0.0, 1.0},  c2 = { 1.0 , 0.0}, c3;


int main(void){
	
	c3 = c1;
	
	printf(" %lf , %lf\n", c3.real, c3.imaginary);
	
	c3.real = c1.real + c2.real;		
	c3.imaginary = c1.imaginary + c2.imaginary;
	
	printf(" %lf , %lf", c3.real, c3.imaginary);
	return 0;
}

