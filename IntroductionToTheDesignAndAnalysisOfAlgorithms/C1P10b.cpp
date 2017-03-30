#include <stdio.h>

int gcd(int m, int n,float &x,float &y)
{
	if(n == 0)
	{
		x = 1; y = 0;
		return m;
	}
	int r = gcd(n,m%n,x,y);
	
	int t = x;
	x = y;
	y = t-m/n*x;
	
	return r;		
}

int cal(int a,int b,int c,float &x,float &y)
{
	float f;
	int r = gcd(a,b,x,y);
	f = c * 1.0f /r;
	x = x *f;
	y = y * f; 
	return r;
}

int main(void)
{
	float x , y;
	
	printf("%d %f %f",cal(7,2,6,x,y),x,y);
	
	return 0;
}