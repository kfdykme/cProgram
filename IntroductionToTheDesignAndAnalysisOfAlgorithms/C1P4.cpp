//计算开平方后向下取整

#include <stdio.h>

int get(int n)
{
	int i ;
	for (i = 1;i*i<=n;i++);
	return i-1;	
}
int main(void)
{
	printf("%d",get(48));
	return 0;
}
	