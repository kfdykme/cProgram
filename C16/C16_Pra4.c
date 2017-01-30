#include <stdio.h>

typedef struct  {
	double real, imaginary;
} Complex;

Complex c1, c2, c3;

Complex make_complex(double r, double i);
Complex add_complex(Complex c1, Complex c2);

int main(void){
	c1 = make_complex(1.1, 22.2);
	printf("%lf , %lf\n",c1.real, c1.imaginary);
	c1 = add_complex(c1,{1.0,-2.2});
	printf("%lf , %lf\n", c1.real, c1.imaginary);
	return 0;
}

Complex make_complex(double r, double i){
	Complex c;
	c.real = r;
	c.imaginary = i;
	return c;
}

Complex add_complex(Complex c1, Complex c2){
		c1.real += c2.real;
		c1.imaginary += c2.imaginary;
		return c1;
}