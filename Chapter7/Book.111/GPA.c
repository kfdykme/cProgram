#include <stdio.h>

float compute_GPA(char grades[],int n){
	float a = 0.0f;
	for ( int i = 0;i<n;i++){
		switch(grades[i]){
			case 'A': a+=4;break;
			case 'B': a+=3;break;
			case 'C': a+=2;break;
			case 'D': a+=1;break;
		}printf("\n%f",a);
		
	}
				
		a = a/ n;
	return a;
}


int main(void){
	int i =0;
	char ch[100];
	
	do{
		ch[i++] = getchar();
	} while(ch[i -1] != '\n');
	
	printf("%0.2f",compute_GPA(ch,i-1));
	
		 return 0;
		 }	 