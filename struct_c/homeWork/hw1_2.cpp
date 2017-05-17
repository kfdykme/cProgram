#include <stdio.h>

void de(int *list, int len, int start , int w){
	for (int i = 0;i < w;i++)
		if (start + i < len)
			list[start+i] = 0;
}

int main(void)
{
	int list[100];
	int len = 100;
	for (int i =0; i < 100; i++)
		list[i] = i+3;
	de(list,len,55,39);
	for (int i =0; i < 100; i++)
		printf("%d\n",list[i]);
	return 0;
}