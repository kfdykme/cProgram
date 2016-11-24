#include <stdio.h>
#include <stdlib.h>

void generate_random_walk(char walk[][10]);
void print_array(char walk[][10]);


int main(){
	char map[10][10]{'0'};
	generate_random_walk(map);
	
	print_array(map);	
		
	return 0;
}


void generate_random_walk(char walk[][10]){
	int ranNumber ;
	int x = 0,y = 0;
	char letter = 'A' ;
	for (int y = 0;y <10;y++){
		for (int x = 0; x < 10;x++){
			walk[y][x] = '.';
		}
	}
	walk[y][x] = letter;
	ranNumber = rand() % 4;
	
	while(letter != 'Z'&& letter != 'Z' +1 ){
		letter = ( walk[y+1][x] != '.'
			&&walk[y-1][x] != '.'
			&&walk[y][x+1] != '.'
			&&walk[y][x-1] != '.' )? 'Z' +1:letter;
		switch(ranNumber){
			case 0://Right
				if(walk[y][x+1] =='.' && x+1 <10&&walk[y][x]){
					walk[y][x+1] = ++letter;
					x= x+1;
				}
				break;
			case 1://Left
				if(walk[y][x-1] == '.' && x-1>=0){
					walk[y][x-1] = ++letter;
					x = x-1;
				}
				break;
			case 2://Up
				if(walk[y+1][x] == '.'&&y+1 <10){
					walk[y+1][x] = ++letter;
				y = y+1;
					}
				break;
			case 3://Down
				if(walk[y-1][x] == '.' && y-1>=0){
					walk[y-1][x] = ++letter;
					y = y-1;
					}
				break;
		}
		ranNumber = rand() % 4;
	}

}

void print_array(char walk[][10]){
	printf("\n");
	for (int y = 0;y  </10;y++){
		for (int x = 0; x < 10;x++){
			printf("%c",walk[y][x]);
			if (x==9)
			  printf("\n");
		}
	}

	}