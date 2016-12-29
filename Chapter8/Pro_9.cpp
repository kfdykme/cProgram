#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W 10

int main(void) {
  char map[W][W];
  char let = 'A' ;
  int x = 0, y = 0;
  int rN;

  for (int r = 0; r < W; r++) {
    for (int c = 0; c < W; c++) {
      map[r][c] = '.';
    }
  }

map[y][x] = let;
    
  do {
    rN = rand() % 4;
    
    if ( map[y][x-1] != '.'
    	&& map[y][x+1] != '.'
    	&& map[y-1][x] != '.'
    	&& map[y+1][x] != '.
    	|| (x)') 
    	break; 
    	
    switch(rN){
    	case 0://Left
    	  if ( x  > 0 && map[y][x-1] == '.'){
    	  	map[y][x-1] = ++let;
    	  	x--;
    	  }
    	  break;
    	case 1://Right
    	  if ( x  < W && map[y][x+1] == '.'){
    	  	map[y][x+1] = ++let;
    	  	x++;
    	  }
    	  break;
    	case 2://Up
    	if ( y  > 0 && map[y-1][x] == '.'){
    	  	map[y-1][x] = ++let;
    	  	y--;
    	  }
    	  break;
    	case 3://Down
    	  if ( y  < W && map[y+1][x] == '.'){
    	  	map[y+1][x] = ++let;
    	  	y++;
    	  }
    	  break;
    }	
  //  printf(" rN = %dlet = %c  x = %d  y = %d  map[][] =   %c\n",rN,let,x,y,map[x][y]);
    
    
  }while(let != 'Z');

  for (int r = 0; r < W; r++) {
      for (int c = 0; c < W; c++) {
        printf("%c%c", map[r][c],
         c == W - 1 ? '\n' : ' ');
      }
  }
    return 0;
  }