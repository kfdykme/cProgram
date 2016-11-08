#include <stdio.h>

int main(void){
	char fN, N,fNF;
	bool b = true;
	int i = 0;
	printf("Enter a first name and last name: ");
	
	N = getchar();
	
	while( N != '\n'){
		if ( N >= 'A' &&N <= 'Z' &&i == 0){
			fN = N;
			i = 1;
		} else if ( i == 1&&N ==' '){
			i =2;
		} else if (i==2){
		printf("%c",N);

		}
//	printf("%d ",i);
	N = getchar();
	}
	printf(", %c.", fN);
	
	
	/*
	while(b){
		scanf("%c", &N);
	
		if ( 'A' <= N && 'Z' >= N && i == 0){
			fNF = N;
			while(b){
				scanf("%c", &N);
				if (N == ' '){
					while(b){
						scanf("%c", &N);
						if(N != ' '){printf("%c", N);}
						if(N == ' '){
							printf(", %c." , fNF);
							b = false;}}}}}}
	
	*/
	return 0 ;
	}
	
//Maybe you can use it.
/*#include <stdio.h>

int main(void){
	char fN, N,fNF;
	bool b = true;
	int i = 0;
	printf("Enter a first name and last name: ");
	
	while(b){
		scanf("%c", &N);
	
		if ( 'A' <= N && 'Z' >= N && i == 0){
			fNF = N;
			}
		if ( N ==' '){
				do {
					scanf("%c", &N);
					if(N != '\n')
						printf("%c", N);}
					while( N != '\n');
			
				printf(", %c.", fNF);
				b = false;}}
	
	return 0 ;
	}
*/
					
			