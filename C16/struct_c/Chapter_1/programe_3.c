//3. 写一个由20项组成的等差数列，其偶数项之和为330，奇数项之和为300，而且每项都是正整数。

#include <stdio.h>

float giveDi(int sum1, int sum2, int n){
	
	//只能用于长度为偶数的数列
		
	return (( sum2 - sum1)  * 2 / n) + 0.0f;
}	

int giveFirst(int sum, int length, int d){
	
	//Sn = a1 * n + (n*(n -1 )*d)/2
	//a1 = (Sn - (n*(n-1)*d)/2 ) / n
	 
	
	return (sum - (length*(length-1) *d)/2 ) /length;
	
}	

void writeArray(int a[], int length , int a0, int d ){
	a[0] = a0;
	for (int i = 1; i<length; i++){
		a[i]  = a[i-1] +d;
		}		
}	

void printfArray(int a[], int length,int a0, int d){
	for (int i = 0; i < length ; i++)
		printf(" a[%d] = %d\n",i ,a[i]);
	printf("d = %d\n a0 = %d\n\n",d, a0);
}

void testArray(int a[], int length){
	int ouSum = 0 , jiSum = 0;
	for (int i = 1; i <= length ; i++)
		if (i % 2 == 0  )
			ouSum += a[i-1];
		else 
			jiSum += a[i-1];
	
	printf("\n\n\touSum = %d\n\tjiSum = %d\n\n",ouSum, jiSum);
}


void getArray(int a[], int length, int jiSum, int ouSum ){
		if (length % 2 != 0 ){
		printf("无效\n");
		
	}

	
	int d = giveDi(jiSum, ouSum, length);
	
	int a0 = giveFirst(jiSum, length / 2, 2*d);
	
	writeArray(a, length, a0, d);
	printfArray(a,length,a0,d);
	testArray(a,length);
}



int main(void){
	int a[20];
	int ouSum = 330, jiSum = 300;

	
	getArray(a,20,jiSum, ouSum);	
	
	writeArray(a,20,3,3);
	printfArray(a,20,3,3);
	testArray(a,20);
	return 0;
	
}