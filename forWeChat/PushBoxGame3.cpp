#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define X 6
#define Y 6
#define WIDTH 30
#define HEIGHT 20
#define INFORMATIONSTARTLINE 7
#define INISCORE 100
#define TRUE 1
#define FALSE 0
										
#define BORDER '.'
#define BLANK ' '
#define WALL '+'
#define BOX 'o'
#define TARGET 'X'
#define PLAYER '&'

int main(void) {

  char infor[3][6] = { {'s', 'e', 'n', 'c', 'e', '1'},
  {'s', 'e', 'n', 'c', 'e', '2'},
  {'s', 'e', 'n', 'c', 'e', '3'}
  };

  char sence[6][10][10] = {
    {
     // /// 0
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, PLAYER, BLANK, 'S', 't', 'a', 'r', 't', BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, 'L', 'o', 'a', 'd', BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, 'S', 'c', 'o', 'r', 'e', BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, 'E', 'x', 'i', 't', BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     },
    // /// 1
    {{BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, PLAYER, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, 'M', 'e', 'n', 'u', BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},

     },
    // /// 2
    {
     },
    // /// 3
    {
     {BLANK, BLANK, BLANK, WALL, WALL, WALL, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, WALL, TARGET, WALL, BLANK, BLANK, BLANK, BLANK},
     {WALL, WALL, WALL, WALL, BLANK, WALL, BLANK, BLANK, BLANK, BLANK},
     {WALL, TARGET, BOX, BLANK, BOX, WALL, WALL, WALL, BLANK, BLANK},
     {WALL, WALL, WALL, PLAYER, BOX, BLANK, TARGET, WALL, BLANK, BLANK},
     {BLANK, BLANK, WALL, BOX, WALL, WALL, WALL, WALL, BLANK, BLANK},
     {BLANK, BLANK, WALL, TARGET, WALL, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, WALL, WALL, WALL, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     },
    // /// 4
    {
     {WALL, WALL, WALL, WALL, WALL, BLANK, BLANK, BLANK, BLANK},
     {WALL, PLAYER, BLANK, BLANK, WALL, BLANK, BLANK, BLANK, BLANK, BLANK},
     {WALL, BLANK, BOX, BOX, WALL, BLANK, WALL, WALL, WALL, BLANK},
     {WALL, BLANK, BOX, BLANK, WALL, BLANK, WALL, TARGET, WALL, BLANK},
     {WALL, WALL, WALL, BLANK, WALL, WALL, WALL, TARGET, WALL, BLANK},
     {BLANK, WALL, WALL, BLANK, BLANK, BLANK, BLANK, TARGET, WALL, BLANK},
     {BLANK, WALL, BLANK, BLANK, BLANK, WALL, BLANK, BLANK, WALL, BLANK},
     {BLANK, WALL, BLANK, BLANK, BLANK, WALL, WALL, WALL, WALL, BLANK},
     {BLANK, WALL, WALL, WALL, WALL, WALL, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK,},
     },
	// /// 5
    {
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
     {BLANK, WALL , WALL , WALL , WALL , WALL , WALL , WALL , BLANK, BLANK},
     {BLANK, WALL , BLANK, BLANK, BLANK, BLANK, BLANK, WALL , WALL , WALL },
     {WALL , WALL , BOX  , WALL , WALL , WALL , BLANK, BLANK, BLANK, WALL },
     {WALL , BLANK, PLAYER, BLANK, BOX  , BLANK, BLANK, BOX  , BLANK, WALL },
     {WALL , BLANK,TARGET,TARGET, WALL , BLANK, BOX  , BLANK, WALL , WALL },
     {WALL , WALL ,TARGET,TARGET, WALL , BLANK, BLANK, BLANK, WALL , BLANK},
     {BLANK, WALL , WALL , WALL , WALL , WALL , WALL , WALL , WALL , BLANK},
     {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK}
     }                          
  };

  char map[HEIGHT][WIDTH];

  char ord;

  int senceLv = 0;
  int isFinishGame = FALSE;
  int deScore = 0;
  int ifSence[3] = { TRUE, FALSE, FALSE };

  int maxMapLv = 5;

  int playerX, playerY;
  int boxNum = 0, wallNum = 0, targetNum = 0;
  int targetX[targetNum] = { 0 };
  int targetY[targetNum] = { 0 };
  int isDisconnect = FALSE;
changeMap:
  boxNum = 0;
  wallNum = 0;
  targetNum = 0;
  for (int r = 0; r < 10; r++) {
    for (int c = 0; c < 10; c++) {
      boxNum = sence[senceLv][r][c] == BOX ? boxNum + 1 : boxNum;
      wallNum = sence[senceLv][r][c] == WALL ? wallNum + 1 : wallNum;
      targetNum = sence[senceLv][r][c] == TARGET ? targetNum + 1 : targetNum;
    }
  }
  for (int r = 0, t = 0; r < 10; r++) {
    for (int c = 0; c < 10; c++) {
      playerX = sence[senceLv][r][c] == PLAYER ? c : playerX;
      playerY = sence[senceLv][r][c] == PLAYER ? r : playerY;
      if (sence[senceLv][r][c] == TARGET) {
        targetX[t] = c;
        targetY[t] = r;
        t++;
      }
    }
  }

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = BLANK;
    }
  }


  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      map[3][1 + x] = senceLv > 2 && x < 6 ? infor[senceLv - 3][x] : map[3][1 + x];
      map[Y + y][X + x] = sence[senceLv][y][x];

    }
  }



  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = (x == 0
                   || x == WIDTH - 1 || y == 0
                   || y == HEIGHT - 1) ? BORDER : map[y][x];
    }
  }

  while (!isFinishGame == TRUE) {
    for (int i = 0, j = 0; i < targetNum; i++) {
      map[Y + targetY[i]][X + targetX[i]] =
        map[Y + targetY[i]][X + targetX[i]] ==
        BLANK ? TARGET : map[Y + targetY[i]][X + targetX[i]];
      j = map[Y + targetY[i]][X + targetX[i]] == BOX ? j + 1 : j;
      isFinishGame = j == targetNum ? TRUE : FALSE;
    }

    system("clear");

     for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        printf("%c%c", map[y][x], x == WIDTH - 1 ? '\n' : BLANK);
      }
    }

    ord = getch();
    // deScore++; 
    map[Y + playerY][X + playerX] = BLANK;

    if (senceLv == 0) {
      switch (ord) {
      case 'S':
      case 's':
        playerY = playerY == 7 ? playerY : playerY + 2;
        break;
      case 'W':
      case 'w':
        playerY = playerY == 1 ? playerY : playerY - 2;
        break;
      case ' ':
        switch (playerY) {
        case 1:
          senceLv = 3;
          goto changeMap;
          break;
        case 3:
          for (int u = 2; u < 8; u = u + 2) {
            for (int x = 0; x < 10; x++) {
              sence[1][u][4 + x] = x < 6
                && ifSence[u / 2 - 1] ==
                TRUE ? infor[u / 2 - 1][x] : sence[1][u][4 + x];
            }
          }
          senceLv = 1;
          goto changeMap;
        case 5:
          break;
        case 7:
          system("clear");
          return 0;

        }
        break;
      }
    } else if (senceLv == 1) {
      switch (ord) {
      case 'S':
      case 's':
        playerY = playerY == 8 ? playerY : playerY + 2;
        break;
      case 'W':
      case 'w':
        playerY = playerY == 2 ? playerY : playerY - 2;
        break;
      case ' ':
        switch (playerY) {
        case 2:
          senceLv = 3;
          break;
        case 4:
          if (ifSence[1] == TRUE) {
            senceLv = 4;
          }
          break;
        case 6:
          if (ifSence[2] == TRUE) {
            senceLv = 5;
          }
          break;
        case 8:
          senceLv = 0;
          break;
        }
        goto changeMap;
        break;
      }
    } else {
      switch (ord) {
      case 'A':
      case 'a':
        if (map[Y + playerY][X + playerX - 1]
            == WALL) {
        } else if (map[Y + playerY][X + playerX - 1] == BOX) {
          if (map[Y + playerY][X + playerX - 2] != WALL
              && map[Y + playerY][X + playerX - 2] != BOX) {
            map[Y + playerY][X + playerX - 2] = BOX;
            playerX -= 1;
          }
        } else {
          playerX -= 1;
        }

        break;
      case 'S':
      case 's':
        if (map[Y + playerY + 1][X + playerX] == WALL) {
        } else if (map[Y + playerY + 1][X + playerX] == BOX) {
          if (map[Y + playerY + 2][X + playerX] != WALL
              && map[Y + playerY + 2][X + playerX] != BOX) {
            map[Y + playerY + 2][X + playerX] = BOX;
            playerY += 1;
          }
        } else {
          playerY += 1;
        }
        break;
      case 'D':
      case 'd':
        if (map[Y + playerY][X + playerX + 1] == WALL) {
        } else if (map[Y + playerY][X + playerX + 1] == BOX) {
          if (map[Y + playerY][X + playerX + 2] != WALL
              && map[Y + playerY][X + playerX + 2] != BOX) {
            map[Y + playerY][X + playerX + 2] = BOX;
            playerX += 1;
          }
        } else {
          playerX += 1;
        }
        break;
      case 'W':
      case 'w':
        if (map[Y + playerY - 1][X + playerX] == WALL) {
        } else if (map[Y + playerY - 1][X + playerX]
                   == BOX) {
          if (map[Y + playerY - 2][X + playerX] != WALL
              && map[Y + playerY - 2][X + playerX] != BOX) {
            map[Y + playerY - 2][X + playerX] = BOX;
            playerY -= 1;
          }
        } else {
          playerY -= 1;
        }
        break;
      case ' ':
        printf("\n\n\n\tAre you want to go to menu ?(Y/N))");
        ord = getch();
        if (ord == 'Y' || ord == 'y') {
          senceLv = ord == 'Y' || ord == 'y' ? 0 : senceLv;
          goto changeMap;
        }
        break;
      }
    }
    map[Y + playerY][X + playerX] = PLAYER;
  }
  if (senceLv == maxMapLv) {
    system("clear");
    printf("\n\n\n\n\n\n\t\tYou Win!");
    ord = getch();
    senceLv = 0;
    isFinishGame = FALSE;
    goto changeMap;
  }
  printf("\n\n\n\tComptele! Are you want to continue ?(Y/N))");

YON:
  ord = getch();
  senceLv = ord == 'Y' || ord == 'y' ? senceLv + 1 : senceLv;
  senceLv = ord == 'N' || ord == 'n' ? 0 : senceLv;
  ifSence[senceLv - 3] = TRUE;
  isFinishGame = FALSE;

  if (ord == 'Y' || ord == 'y' || ord == 'N' || ord == 'n')
    goto changeMap;
  else
    goto YON;
  return 0;

}