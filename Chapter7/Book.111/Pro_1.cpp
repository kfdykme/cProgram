#include <stdio.h>

int main(void){
	int s;
	int n;
	printf("Enter 1/2/3 to choose the mode\n1 to int\n2 to short\n3 to long\n");
	scanf("%d", &s);
	switch(s){
		case 1:
			printf("int\t");
			int i;
	
			printf("This program prints a table of squares.\n");
			printf("Enter number of entries in tables: ");
			scanf("%d", &n);
//用for 输出i*i
			for ( i = 1; i <= n; i++){
			printf("%10d%10d\n", i, i * i);
			}
			break;
		case 2:
			printf("short\t");
			
			short  i2;
			printf("This program prints a table of squares.\n");
			printf("Enter number of entries in tables: ");
			scanf("%d", &n);
	
			for ( i2 = 1; i2 <= n; i2++){
			printf("%10d%10d\n", i2, i2 * i2);
			}
			break;
		case 3:
			printf("long\t");
			long i3;
			
			printf("This program prints a table of squares.\n");
			printf("Enter number of entries in tables: ");
			scanf("%d", &n);
	
			for ( i3 = 1; i3 <= n; i3++){
			printf("%10d%10d\n", i3, i3 * i3);
			}
			break;
		default:
			printf("Please enter a number to choose the mode.");
			break;
			}
	

		return 0;
}	