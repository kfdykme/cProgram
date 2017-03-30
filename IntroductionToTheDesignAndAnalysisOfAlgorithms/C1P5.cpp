//用欧几里德算法求gcd(31314,14142)

#include <stdio.h>

int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(void)
{
	printf("%d",gcd(14142,31415));	
	//快多少？？？？？？？？
	//不知道

	return 0;
}