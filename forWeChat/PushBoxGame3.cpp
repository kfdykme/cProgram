#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define X 6
#define Y 6


#define WIDTH 25
#define HEIGHT 18
#define INFORMATIONSTARTLINE 7
#define INISCORE 100
#define TRUE 1
#define FALSE 0


#define BORDER '.'
#define BLANK ' '
#define WALL '+'
#define BOX 'o'
#define TARGET 'X'
#define PLAYER 'S'

int main(void) {

  char m1[8][8] = {
    {BLANK, BLANK, BLANK, WALL, WALL, WALL, BLANK, BLANK},
    {BLANK, BLANK, BLANK, WALL, TARGET, WALL, BLANK, BLANK},
    {WALL, WALL, WALL, WALL, BLANK, WALL, BLANK, BLANK},
    {WALL, TARGET, BOX, BLANK, BOX, WALL, WALL, WALL},
    {WALL, WALL, WALL, PLAYER, BOX, BLANK, TARGET, WALL},
    {BLANK, BLANK, WALL, BOX, WALL, WALL, WALL, WALL},
    {BLANK, BLANK, WALL, TARGET, WALL, BLANK, BLANK, BLANK},
    {BLANK, BLANK, WALL, WALL, WALL, BLANK, BLANK, BLANK}
  };
  char m2[9][9] = {
    {WALL, WALL, WALL, WALL, WALL, BLANK, BLANK, BLANK, BLANK},
    {WALL, PLAYER, BLANK, BLANK, WALL, BLANK, BLANK, BLANK, BLANK},
    {WALL, BLANK, BOX, BOX, WALL, BLANK, WALL, WALL, WALL},
    {WALL, BLANK, BOX, BLANK, WALL, BLANK, WALL, TARGET, WALL},
    {WALL, WALL, WALL, BLANK, WALL, WALL, WALL, TARGET, WALL},
    {BLANK, WALL, WALL, BLANK, BLANK, BLANK, BLANK, TARGET, WALL},
    {BLANK, WALL, BLANK, BLANK, BLANK, WALL, BLANK, BLANK, WALL},
    {BLANK, WALL, BLANK, BLANK, BLANK, WALL, WALL, WALL, WALL},
    {BLANK, WALL, WALL, WALL, WALL, WALL, BLANK, BLANK, BLANK}
  };
  // /////////////////////////////////////////////////////

  char map[HEIGHT][WIDTH];

  char ord;

  // /////////////////////////////////////////////////// 

  int mapLv = 1;
  int isFinishGame = FALSE;
  int deScore = 0;

  int playerX, playerY;
  int boxNum = 0, wallNum = 0, targetNum = 0;
  int targetX[targetNum] = { 0 };
  int targetY[targetNum] = { 0 };
  // //////////////////////////
  for (int r = 0; r < (mapLv == 1 ? 8 : 9); r++) {
    for (int c = 0; c < (mapLv == 1 ? 8 : 9); c++) {
      boxNum = m1[r][c] == BOX ? boxNum + 1 : boxNum;
      wallNum = m1[r][c] == WALL ? wallNum + 1 : wallNum;
      targetNum = m1[r][c] == TARGET ? targetNum + 1 : targetNum;
    }
  }
  // //////////////////////////

  // printf("\n\t%d \t%d \t%d",boxNum,wallNum,targetNum);
  int t = 0;
  for (int r = 0; r < (mapLv == 1 ? 8 : 9); r++) {
    for (int c = 0; c < (mapLv == 1 ? 8 : 9); c++) {
      playerX = m1[r][c] == PLAYER ? c : playerX;
      playerY = m1[r][c] == PLAYER ? r : playerY;
      // targetX[t++] = m1[r][c] == TARGET ? c:targetX[--t];
      // targetY[t++] = m1[r][c] == TARGET ? r:targetY[--t];
      if (m1[r][c] == TARGET) {
        targetX[t] = c;
        targetY[t] = r;
        // printf("\ntatgetY[%d] = %d targetX[%d] =
        // %d",t,targetY[t],t,targetX[t]);
        // printf("\nt = %d",t);
        t++;
      }

    }
  }

  // /////////////////////////////////////////////////// 
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = x == 0
        || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1 ? BORDER : BLANK;
       printf("%c%c", map[y][x],
                               x == WIDTH - 1 ? '\n' : BLANK);
    }
  }

  // /////////////////////////////////////////////////// 
  int j = 0;
  for (int i = 0; i < targetNum; i++) {
    j = map[Y + targetY[i]][X + targetX[i]] == BOX ? j + 1 : j;
    isFinishGame = (j == targetNum - 1) ? TRUE : FALSE;
    // printf("\nisFinishGame = %d ",isFinishGame);
    // printf("\ntargetNum = %d ",targetNum);
    // printf("\ni = %d ",i);
    // printf("\ntargetY[%d] = %d targetX[%d] =
    // %d",i,targetY[i],i,targetX[i]);
    // printf("\nt = %d ",t);
    // printf("\nmap[Y+targetY[i]][X+targetX[i]] =
    // %c",map[Y+targetY[i]][X+targetX[i]]);
  }


  // /////////////////////////////////////////////////// 



  if (mapLv == 1) {
    for (int y = 0; y < mapLv == 1 ? 8 : 9; y++) {
      for (int x = 0; x < mapLv == 1 ? 8 : 9; x++) {
        map[Y + y][X + x] = m1[y][x];
      }
    }
  }

  for (int k = 0; k < 1; k++) {
 //   system("clear");
/*
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        printf("%c", map[y][x]);
        if (x == WIDTH - 1) {
          switch (y) {
          case INFORMATIONSTARTLINE:
            printf("\t%c - 玩家\n", PLAYER);
            break;
          case INFORMATIONSTARTLINE + 1:
            printf("\t%c - 墙\n", WALL);
            break;
          case INFORMATIONSTARTLINE + 2:
            printf("\t%c - 箱子\n", BOX);
            break;
            case
          INFORMATIONSTARTLINE + 3:
            printf("\t%c - 放箱子的地方\n", TARGET);
            break;
          case INFORMATIONSTARTLINE + 5:
            printf("\tSCORES : %3d \n", deScore <=
                   INISCORE ? INISCORE - deScore : 0);
            break;
          default:
            printf("\n");
            break;
          }
        }
      }

    }
   
       // ///////////////////////////////////////////////////

       // /////////////////////////////////////////////////// ord = getch();
       deScore++; // ///////////////////////////////////////////////////

       map[Y + playerY][X + playerX] = BLANK;

       switch (ord) { case 'A': case 'a': if (map[Y + playerY][X + playerX -
       1] == WALL) { } else if (map[Y + playerY][X + playerX - 1] == BOX) { if 
       (map[Y + playerY][X + playerX - 2] != WALL) { map[Y + playerY][X +
       playerX - 2] = BOX; playerX -= 1; } } else { playerX -= 1; }

       break; case 'S': case 's': if (map[Y + playerY + 1][X + playerX] ==
       WALL) { } else if (map[Y + playerY + 1][X + playerX] == BOX) { if
       (map[Y + playerY + 2][X + playerX] != WALL) { map[Y + playerY + 2][X +
       playerX] = BOX; playerY += 1; } } else { playerY += 1; } break; case
       'D': case 'd': if (map[Y + playerY][X + playerX + 1] == WALL) { } else
       if (map[Y + playerY][X + playerX + 1] == BOX) { if (map[Y + playerY][X
       + playerX + 2] != WALL) { map[Y + playerY][X + playerX + 2] = BOX;
       playerX += 1; } } else { playerX += 1; } break; case 'W': case 'w': if
       (map[Y + playerY - 1][X + playerX] == WALL) { } else if (map[Y +
       playerY - 1][X + playerX] == BOX) { if (map[Y + playerY - 2][X +
       playerX] != WALL) { map[Y + playerY - 2][X + playerX] = BOX; playerY -= 
       1; } } else { playerY -= 1; } break; } map[Y + playerY][X + playerX] =
       PLAYER; */

}

  // /////////////////////////////////////////////////// system("clear");

  printf("\n\n\n\n\n\n\t\t\t\t\tYou Win!");
  return 0;

}