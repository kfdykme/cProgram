#include <stdio.h>

int gcd(int m, int n,int &x,int &y)
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

int main(void)
{
	int x , y;
	
	printf("%d %d %d",gcd(12,9,x,y),x,y);
	
	return 0;
}