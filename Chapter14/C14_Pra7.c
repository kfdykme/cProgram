#include <stdio.h>

#define GENERIC_MAX(type)		\
type type##_max(type x, type y); \
{								\
 return x > y ? x: y;			\
}								\

GENRIC_MAX(long)

int main(void){
	long a = 3, b = 99;

	printf("%d", long_max(a,b));
	
	return 0;
}
		