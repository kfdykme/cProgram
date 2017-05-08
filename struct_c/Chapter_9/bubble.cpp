#include <stdio.h>
#include <stdlib.h>

#define M 100

int bubblepass(int *SqList, int len)
{
	int isFinish = 1;
	int key;
	for (int i = 0; i < len-1; i++)
		if (SqList[i] > SqList[i+1])
		{
			key = SqList[i];
			SqList[i] = SqList[i+1];
			SqList[i+1] = key;
			isFinish = 0;
		}
	
	return isFinish;
}

void bubble(int *SqList, int len)
{
	for (int i = len ; i >0 ; i--)
		if (bubblepass(SqList, i))
			return ;
}

int main(void)
{
	
	int a[11] = {7,2,3,1,5,4,6,8,9,0};
	
	for (int i = 0; i < 10 ; i++)
		printf("%d\t",a[i]);
	printf("\n");
	
	bubble(a,10);
	
	for (int i = 0; i < 10 ; i++)
		printf("%d\t",a[i]);
	printf("\n");
	
	
	return 0;
}