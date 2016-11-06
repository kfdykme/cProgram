#include <stdio.h>
#include <stdlib.h>

/* 
   这是一个推箱子的游戏 呵呵
   我实在不知道微信公众号干嘛好 －枋 */
#define X 8
#define Y 8

int main(void) {
// 首先我们需要一个推箱子游戏的总体背景
// 于是我设了一个char二维数组
// 当我们想改变箱子和人的位置时，
// 我们只需要改变char中对应的行列中的值就好了
  char xyBackground[20][20] = { };

// 同时我们控制小人去推箱子时 我们需要输入一个指令 
// 于是我设了一个名叫 ord 的 char 变量
// (比较我们现在只学了scanf来获得输入）
  char ord;

// 在关卡中一开始就会有一些箱子
// 于是我设了以下两个变量来确定箱子最初的xy 坐标
  int boxX[4] = { 2, 3, 4, 4 };
  int boxY[5] = { 3, 5, 3, 4 };

// 同理 这是推箱子的小人的xy坐标
  int playerX = 3;
  int playerY = 4;
  
// 这是墙的xy坐标 （好鸡肋好烦好无聊
  int wX[] =
    { 3, 4, 5, 3, 5, 0, 1, 2, 3, 5, 0, 5, 6, 7, 0, 1, 2, 7, 2, 4, 5, 6, 7, 2,
    4, 2, 3, 4
  };
  int wY[] =
    { 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6,
    6, 7, 7, 7
  };
 
// 恩 这个是标记为箱子要推到什么地方的那个地方的坐标
// 		😃
  int tX[] = { 4, 1, 6, 3 };
  int tY[] = { 1, 3, 4, 6 };

// 啊 因为我忘了 不知道 char 的某些语法 所以就干脆用for历遍
// 把xyBackground 中每个值都变成了一个空格
  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      xyBackground[y][x] = ' ';
    }
  }
// 然后再把特定xy坐标上的值改为P (代表推箱子的小人）
  xyBackground[playerY][playerX] = 'P';
	
// 然后用了三个历遍把 xyBackground
// 中B(箱子)W(墙)T(目标地)的相应xy的值改为 B W T
	for (int n = 0; n < (sizeof(boxX) / sizeof(boxX[0])); n++) {
    xyBackground[boxY[n]][boxX[n]] = 'B';
  }
  for (int n = 0; n < (sizeof(wX) / sizeof(wX[0])); n++) {
    xyBackground[wY[n]][wX[n]] = 'W';
  }
  for (int n = 0; n < (sizeof(tX) / sizeof(tX[0])); n++) {
    xyBackground[tY[n]][tX[n]] = 'T';
  }
  
// 设置好了上面的东西之后 就会有一个“地图？” 在xyBackground[][]里
// 接下来就要实现用户每一次输入指令 小人就动一下 的这个过程
  
      for (int t = 0; t < 1;) {
//毕竟我们不想弄个长长长的东西出来 
//所以每一次都把控制台里面的东西清空好一点
      system("clear");

//接下来就是用for 循环吧xyBackground[][] 中的东西打印出来啦
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        printf("%c ", xyBackground[y][x]);
        
        // 打印归打印 既然我们用了xy坐标
        // 就没理由打出一条线出来让人骂智障对吧
        // 于是在打印每行的最后一个char 后 顺便打个换行符
        // 这里我在第 3 4 5 行加入了一下额外的文本让玩家更容易知道
        // 这是个什么鬼 什么鬼 鬼鬼鬼
        if (x == X - 1) {
          switch (y) {
          case 2:
            printf("\tP - 玩家\n");
            break;
          case 3:
            printf("\tW - 墙\n");
            break;
          case 4:
            printf("\tB - 箱子\n");
            break;
          case 5:
            printf("\tT - 放箱子的地方\n");
            break;
          default:
            printf("\n");
            break;
          }
        }
      }

    }

// 记不记得前面那个设了 int t 的那个for 循环 
// 我没有设置 t 的递增所以他会一直循环下去 
// 那么当小人把箱子推到位的时候我们就需要听着这个循环
// 于是写了个if来判断 如果所有目标位置上都被压了箱子 那么游戏就完成了啦 
// 游戏完成 孜然就要🔚循环啦 于是让 t 自增
    if ((xyBackground[tY[0]][tX[0]] == 'B')
        && (xyBackground[tY[1]][tX[1]] == 'B')
        && (xyBackground[tY[2]][tX[2]] == 'B')
        && (xyBackground[tY[3]][tX[3]] == 'B')) {
      t++;
    } else {
    //如果没有完成游戏的话 还是老老实实地继续推吧
    //然 下面这两条语句就是用来输入你的小人往哪边走的
      printf("Enter a s d w to contro the P\n");
      scanf("%c", &ord);
    }


// 小人移动的时候不能留下分身对不对 
// 所以要把原先小人位置的char 变量设成 ‘ ’ 
    xyBackground[playerY][playerX] = ' ';
    
// 然后用switch语句判断用输入了 a w s d 中 哪一个
// 为了大小写都可以成功判断 就加入了 A S D W     
    switch (ord) {
    case 'A':  
    case 'a':
    // 当用户输入 a 时 代表他想让小人往左走对不对？
    // 但是不是他想往左就能给他往左走对不对
    // 第一步 我们要看一看小人的左边是不是墙
    // 如果他左边是墙的话 他就不能穿墙了对嘛 这是推箱子不是cf
    // 那么 不是墙的话 如果他左边是箱子呢 好像也不一定行吧？
    // 所以 我们再判断一下 小人左边是箱子的时候 箱子左边是不是墙
    // 如果 不是的话 小人就开心地可以推着箱子往左走啦
    // 当然 如果不是墙也不是箱子的话 就让小人直接往左走吧
    // 剩下的三个方向也是相同的道理丷
      if (xyBackground[playerY][playerX - 1] == 'W') {

      } else if (xyBackground[playerY][playerX - 1] == 'B') {
        if (xyBackground[playerY][playerX - 2] != 'W') {
          xyBackground[playerY][playerX - 2] = 'B';
          playerX -= 1;
        }
      } else {
        playerX -= 1;
      }
      break;
    case 'S':
    case 's':
      if (xyBackground[playerY + 1][playerX] == 'W') {

      } else if (xyBackground[playerY + 1][playerX] == 'B') {
        if (xyBackground[playerY + 2][playerX] != 'W') {
          xyBackground[playerY + 2][playerX] = 'B';
          playerY += 1;
        }
      } else {
        playerY += 1;
      }
      break;
    case 'D':
    case 'd':
      if (xyBackground[playerY][playerX + 1] == 'W') {

      } else if (xyBackground[playerY][playerX + 1] == 'B') {
        if (xyBackground[playerY][playerX + 2] != 'W') {
          xyBackground[playerY][playerX + 2] = 'B';
          playerX += 1;
        }
      } else {
        playerX += 1;
      }
      break;
    case 'W':
    case 'w':
      if (xyBackground[playerY - 1][playerX] == 'W') {

      } else if (xyBackground[playerY - 1][playerX] == 'B') {
        if (xyBackground[playerY - 2][playerX] != 'W') {
          xyBackground[playerY - 2][playerX] = 'B';
          playerY -= 1;
        }
      } else {
        playerY -= 1;
      }
      break;
    }
    // 因为在上面的语句中 
    // 我们只是将小人原先所在位置的 char 值变为空格' '  
    // 然后给小人的 xy 坐标挪了一下 
    // 可是动了坐标又怎么样 显示器不会理你 他需要一条语句
    // 一条让小人“现身的语句”
    // 对的就是下面这条
    xyBackground[playerY][playerX] = 'P';


  }

 // 当推完箱子之后 自然就游戏结束了
 // 看到前面我设墙的坐标 还想让我做第二关吗? 我还要学习！！！
  system("clear");
  printf("\n\n\n\t\t\tYou Win!");
   return 0;

}