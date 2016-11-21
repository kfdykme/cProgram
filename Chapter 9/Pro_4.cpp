#include <stdio.h>

#define LEN (int) sizeof(a)/sizeof(a[0])

int main(void){
	int a[10];
	
	printf("Enter %d numbers: ", LEN);
	for(int i  = 0;i<LEN;i++)
		scanf("%d",&a[i]);
		
	printf("In reverse order: ");
	for(int i = LEN -1;i>=0;i--)
		printf(" %d",a[i]);
	printf("\n");

	return 0;
}