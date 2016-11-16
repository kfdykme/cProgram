#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define X 6
#define Y 6


#define WIDTH 25
#define HEIGHT 18
#define INFORMATIONSTARTLINE 7
#define INISCORE 100

#define BORDER '.'
#define BLANK ' '
#define WALL '+'
#define BOX 'o'
#define TARGET 'X'
#define PLAYER 'S'
 
int main(void) {
  // /////////////////////////////////////////////////////
  
  char map[HEIGHT][WIDTH];
  char ord;

  // /////////////////////////////////////////////////// 
  int mapLv = 1;
  int deScore = 0;

  int boxNum,wallNum,targetNum;
  
  switch (mapLv) {
  	case 1:
  	 boxNum = 4;
  	 wallNum = 28;
  	 targetNum = 4;
  	 break;
  	case 2:
  	 boxNum = 3;
  	 targetNum = 3;
  	 wallNum = 39;
  	 break;
  }

  
    int boxX[boxNum] = { 2, 3, 4, 4 };
  int boxY[boxNum] = { 3, 5, 3, 4 };

  int playerX = 3;
  int playerY = 4;

  int wallX[wallNum] =
    { 3, 4, 5, 3, 5, 0, 1, 2, 3, 5, 0, 5, 6, 7, 0, 1, 2, 7, 2, 4, 5, 6, 7, 2,
    4, 2, 3, 4
  };
  int wallY[wallNum] =
    { 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6,
    6, 7, 7, 7
  };
  int targetX[targetNum] = { 4, 1, 6, 3 };
  int targetY[targetNum] = { 1, 3, 4, 6 };

  // /////////////////////////////////////////////////// 
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = x == 0 || y == 0 || x == WIDTH -1 || y == HEIGHT - 1 ? BORDER:BLANK;
    }
  }

  // /////////////////////////////////////////////////// 

  map[Y + playerY][X + playerX] = PLAYER;

  for (int n = 0; n < (sizeof(boxX) / sizeof(boxX[0])); n++) {
    map[Y + boxY[n]][X + boxX[n]] = BOX;
  }
  for (int n = 0; n < (sizeof(wallX) / sizeof(wallX[0])); n++) {
    map[Y + wallY[n]][X + wallX[n]] = WALL;
  }
  for (int n = 0; n < (sizeof(targetX) / sizeof(targetX[0])); n++) {
    map[Y + targetY[n]][X + targetX[n]] = TARGET;
  }

  // /////////////////////////////////////////////////// 

  for (;!(map[Y + targetY[0]][X + targetX[0]] == BOX
        && map[Y + targetY[1]][X + targetX[1]] == BOX
        && map[Y + targetY[2]][X + targetX[2]] == BOX
        && map[Y + targetY[3]][X + targetX[3]] == BOX) ;) {
    
    system("clear");

    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        printf("%c ", map[y][x]);

        if (x == WIDTH - 1 ) {
          switch (y) {
          case INFORMATIONSTARTLINE:
            printf("\t%c - 玩家\n",PLAYER);
            break;
          case INFORMATIONSTARTLINE+1:
            printf("\t%c - 墙\n",WALL);
            break;
          case INFORMATIONSTARTLINE+2:
            printf("\t%c - 箱子\n",BOX);
            break;
          case INFORMATIONSTARTLINE+3:
            printf("\t%c - 放箱子的地方\n",TARGET);
            break;
          case INFORMATIONSTARTLINE+5:
            printf("\tSCORES : %3d \n",deScore <= INISCORE ? INISCORE - deScore:0 );
            break;
          default:
            printf("\n");
            break;
          }
        }
      }

    }
  // /////////////////////////////////////////////////// 
    
  // /////////////////////////////////////////////////// 
	ord = getch();
	deScore++;
  // /////////////////////////////////////////////////// 

	map[Y + playerY][X + playerX] = BLANK;
	
    switch (ord) {
    case 'A':
    case 'a':
    if (map[Y + playerY][X + playerX - 1] == WALL) {} else if (map[Y + playerY][X + playerX - 1] == BOX) {
        if (map[Y + playerY][X + playerX - 2] != WALL) {
          map[Y + playerY][X + playerX - 2] = BOX;
          playerX -= 1;
        }
      } else {
        playerX -= 1;
      }
    
    break;
    case 'S':
    case 's':
      if (map[Y + playerY + 1][X + playerX] == WALL) {} else if (map[Y + playerY + 1][X + playerX] == BOX) {
        if (map[Y + playerY + 2][X + playerX] != WALL) {
          map[Y + playerY + 2][X + playerX] = BOX;
          playerY += 1;
        }
      } else {
        playerY += 1;
      }
      break;
    case 'D':
    case 'd':
      if (map[Y + playerY][X + playerX + 1] == WALL) {} else if (map[Y + playerY][X + playerX + 1] == BOX) {
        if (map[Y + playerY][X + playerX + 2] != WALL) {
          map[Y + playerY][X + playerX + 2] = BOX;
          playerX += 1;
        }
      } else {
        playerX += 1;
      }
      break;
    case 'W':
    case 'w':
      if (map[Y + playerY - 1][X + playerX] == WALL) {} else if (map[Y + playerY - 1][X + playerX] == BOX) {
        if (map[Y + playerY - 2][X + playerX] != WALL) {
          map[Y + playerY - 2][X + playerX] = BOX;
          playerY -= 1;
        }
      } else {
        playerY -= 1;
      }
      break;
    }
    map[Y + playerY][X + playerX] = PLAYER;

  }

  // /////////////////////////////////////////////////// 
  system("clear");

  printf("\n\n\n\n\n\n\t\t\t\t\tYou Win!");
  
  return 0;

}