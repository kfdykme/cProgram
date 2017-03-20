#include <stdio.h>
#include <stdlib.h>

int AKM(int m, int n)
{
	if (m == 0)
	{
		return n+1;
	} else if (n == 0) {
		return AKM(m-1,1);
	} else {
		return AKM(m-1,AKM(m,n-1));
	}
	
}

int main(void)
{
	printf("%d\n",AKM(4,0));
	return 0;
}