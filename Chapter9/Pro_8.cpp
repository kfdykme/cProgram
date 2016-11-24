#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void game();
void isContinue();
void isWin(int p);
int roll();

int main(void){
	
	game();	
	
	return 0;
}

	
void game(){
	int a = roll();
	int b = roll();
	int sum = a + b;
	
	printf("You rolled: %d\n",sum);
	printf("Your point is %d\n",sum);
	if ( sum == 7 || sum == 11 ){
		printf("You win!\n");
		isContinue();
	} else if (sum == 2 || sum == 3 || sum == 12){
		printf("you lose!\n");
		isContinue(); 
	} else 
		isWin(sum);
	
}

void isContinue(){
	printf("Play again?(Y/N)\n");
	char a = toupper(getchar());
	while(getchar() != '\n');	
	switch(a){
		case 'Y':
			game();
			break;
		case 'N':
			exit(0);
			break;
		default:
			isContinue();
			break;		
		}
}

void isWin(int p){
	int a = roll() + roll();
	
	printf("You rolled: %d\n",a);
	if ( a == p){
		printf("You win!\n");
		isContinue();
	} else if ( a == 7){
		printf("you lose!\n");
		isContinue(); 
	}
	isWin(p);
}	

int roll(){
	return rand() % 6 +1;
}