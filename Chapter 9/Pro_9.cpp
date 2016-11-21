#include <stdio.h>
#include <stdlib.h>


int main(){
	char map[10][10]{'0'};
	int ranNumber ;
	int x = 0,y = 0;
	char letter = 'A' ;
	for (int y = 0;y <10;y++){
		for (int x = 0; x < 10;x++){
			map[y][x] = '.';
		}
	}
	map[y][x] = letter;
	ranNumber = rand() % 4;
	
	while(letter != 'Z'&& letter != 'Z' +1 ){
		letter = ( map[y+1][x] != '.'
			&&map[y-1][x] != '.'
			&&map[y][x+1] != '.'
			&&map[y][x-1] != '.' )? 'Z' +1:letter;
		switch(ranNumber){
			case 0://Right
				if(map[y][x+1] =='.' && x+1 <10&&map[y][x]){
					map[y][x+1] = ++letter;
					x= x+1;
				}
				break;
			case 1://Left
				if(map[y][x-1] == '.' && x-1>=0){
					map[y][x-1] = ++letter;
					x = x-1;
				}
				break;
			case 2://Up
				if(map[y+1][x] == '.'&&y+1 <10){
					map[y+1][x] = ++letter;
				y = y+1;
					}
				break;
			case 3://Down
				if(map[y-1][x] == '.' && y-1>=0){
					map[y-1][x] = ++letter;
					y = y-1;
					}
				break;
		}
		ranNumber = rand() % 4;
	}
	
			  printf("\n");
	for (int y = 0;y <10;y++){
		for (int x = 0; x < 10;x++){
			printf("%c",map[y][x]);
			if (x==9)
			  printf("\n");
		}
	}
		
	return 0;
}