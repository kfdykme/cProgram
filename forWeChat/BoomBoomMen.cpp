/*
	CBooM
	（控制台上的）仿炸弹人游戏
			－枋
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>



#define P '&'
#define W '+'
#define E '$'
#define B 'o'
#define C 'X'
#define BLANK ' '
#define TRUE 1
#define FALSE 0
#define MAX_ARRAY_SIZE 100
#define BOMB_TIME 0.03 //3s
#define SHOCK_WAVE_TIME 0.002 //0.2s

//用于判断场上有没有炸弹 如果为TRUE则不再释放炸弹
int have_bomb = FALSE;
int have_shock_wave = FALSE;
//用于判断场上有没有炸弹 如果为TRUE则炸弹爆炸
int have_more_one_bomb = FALSE;
//炸弹冲击波可以消除的字符
char can_through_view[] = {P,E,' ',W};

bool before_time(clock_t check_time, double break_time);

int length_can_through_view = sizeof(can_through_view)/ sizeof(can_through_view[0]);
/*
	 bomb_break
	炸弹爆炸有冲击波向四个方向去
@bomb_view  			代表炸弹的字符
@break_view  		   代表冲击波的字符
@can_through_view[]	 代表可以被冲击波消除的字符的数组
@bomb_map[][MAX_ARRAY_SIZE]
						炸弹所在的char数组
@MAX_ARRAY_SIZE         最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void bomb_break(char bomb_view,char break_view,char can_through_view[], char bomb_map[][MAX_ARRAY_SIZE]);
/*
	check_is_gameover
	判断游戏是否结束
*/
void check_is_gameover(int *_y,int *_x, char map[][MAX_ARRAY_SIZE],char over_view);


void check_is_gamewin(
	int *_y,
	int *_x,
	char map[][MAX_ARRAY_SIZE],
	char over_view);


/* 
	clear_view_in_map
	讲某个char字符数组中的所以特定字符替换为另一个字符
@clear_view						被替换的字符
@replace_view					  替换的字符
@width							 字符数组的列数
@height							字符数组的行数
@view_array[][MAX_ARRAY_SIZE]	  字符数组
@MAX_ARRAY_SIZE 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void clear_view_in_map(char clear_view, char replace_viewr,int width, int height ,char view_array[][MAX_ARRAY_SIZE]);
/*
	control_view_move
	控制某个特定字符在二维字符数组中“移动”
@width							 字符数组的列数
@height							字符数组的行数
@map[][MAX_ARRAY_SIZE]			 二维字符数组
@view[]							用于确定“移动”的字符
@*_x							   用于确定字符的列位置
@*_y							   用于确定字符的行位置
@can_go_forward_view			   判断为可以向前“移动“的字符
@MAX_ARRAY_SIZE 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void control_view_move(int width, int height, char map[][MAX_ARRAY_SIZE], char view[], int *_x,int *_y,char can_go_forward_view);    
  
/*
	打印一个char二维数组
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_ARRAY_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void display_view_array(int width, int height,
char view_array[][MAX_ARRAY_SIZE]);

/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_ARRAY_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符		
*/
void get_view_x_y(int width, int height, char map[][MAX_ARRAY_SIZE], int *_x, int *_y,char view);

void main_game(
	int width,
	int height,
	char map[][MAX_ARRAY_SIZE],
	int *_x,
	int *_y,
	char view[]);


clock_t bomb_break_ = 0;


int main(void){
	/*
		view[0] 角色 
		view[1] 墙 
		view[2] 敌人 
		view[3] 炸弹 
		view[4] 冲击波
		view[5] 空白
	*/
	char view[6] = { P,W,E,B,C,' '};

	char test_map[4][MAX_ARRAY_SIZE] =
	 {
	 {view[1],view[1],view[1],view[1]},
	 {view[1],BLANK,BLANK,BLANK},
	 {view[1],BLANK,view[2],view[1]},
	 {view[1],view[0],view[1],view[1]},
	 };

	int player_x = 0, player_y = 0; 
	
	clock_t long_clock_time = clock();
	
	double breaktime = 0.001f;
	
	get_view_x_y(4,4,test_map,&player_x,&player_y,view[0]);
	
	display_view_array(4,4,test_map);
	main_game(
		4,
		4,
		test_map,
		&player_x,
		&player_y,
		view);



	//printf("%d %d", 1 == (ord = getch()),true);	
  return 0;

}



void main_game(
	int width,
	int height,
	char map[][MAX_ARRAY_SIZE],
	int *_x,
	int *_y,
	char view[]){
	clock_t long_clock_time;
	for(clock_t a;;){
		//如果时间间隔大于breaktime，就刷新一次屏幕

		a = clock();
	
		if (/*(((a - long_clock_time) / (double) CLOCKS_PER_SEC) > breaktime) 
		&&*/
		kbhit() ){
		//记录刷新的时间用于判断时间间隔
		long_clock_time = clock();
		
		//调用
 	   map[*_y][*_x] = 
 	   	have_bomb == TRUE ? 
 	   	map[*_y][*_x] :' ';
 	   
 	   control_view_move(
 	   	width,
 	   	height,
 	   	map,view,
 	   	_x,
 	   	_y,
 	   	' ');
		
		map[*_y][*_x] = 
		have_bomb ? view[3] :view[0];
		 
   //  map[*_y][*_x] = view[0];
		
		}
 	   system("clear");	
	    
	    display_view_array(
	    	width,
	    	height,
	    	map);
		
		printf("游戏时间：%0.4lf\n",(a/(double) CLOCKS_PER_SEC));
		
		//到达时间后炸弹爆炸
		if (have_more_one_bomb){
			printf("间隔时间: %0.2lf\n",((double)BOMB_TIME - ((a - bomb_break_) / (double) CLOCKS_PER_SEC)));	
	 	
			if(
			((a - bomb_break_) / (double) CLOCKS_PER_SEC)
			> BOMB_TIME){
				have_more_one_bomb = FALSE; 	 
  		
  			  bomb_break(view[3],
  			  view[4],can_through_view,map);
  			  
  			  
  			  bomb_break_ = clock();
  			  
  			  have_shock_wave = TRUE;
			 }
		} else if (have_shock_wave){
			if(
			((a - bomb_break_) / (double) CLOCKS_PER_SEC)
			> SHOCK_WAVE_TIME){
				int a =2 ,b = 2;
				
				check_is_gameover(
					_y,
					_x,
					map,
					view[4]);
  			 check_is_gamewin(
  			 	 &a,
  			 	 &b,
					map,
					view[4]);
  			   
				clear_view_in_map(
					view[4],
					view[5],
					width,
					height,
					map);
				have_shock_wave = !have_shock_wave;
 			}			
		}		
	}
}

/*
	before_time
*/
bool before_time(clock_t check_time, double break_time){
	return (((clock() - check_time) / (double)CLOCKS_PER_SEC) > break_time);
}

void control_view_move(int width, int height, char map[][MAX_ARRAY_SIZE], char view[], int *_x,int *_y,char can_go_forward_view){
	char order;
	
	order = getch();

	clock_t order_time = clock();
	
	order = toupper(order);
 
 	//printf("player_x = %d\nplayer_y = %d\n",*_x,*_y);

//	printf("\n1%c1\n",can_go_forward_view);
  
    have_bomb = FALSE;
 	
//	printf("player_x = %d\nplayer_y = %d\n",*_x,*_y);
	
	  switch (order) {
      case 'A':
      if (*_x -1 >= 0){
      	if (map[*_y][*_x -1] == can_go_forward_view){
      		*_x -= 1;
      		}
      } 
      break;
     case 'S':
        if (*_y + 1 <= height){
      	if (map[*_y+1][*_x] == can_go_forward_view){
 /*    */ 	*_y += 1;
       	}
      	} 
      break;
      case 'D':
      if (*_x +1 <= width){
      	if (map[*_y][*_x +1] == can_go_forward_view){
      		*_x += 1;
      		}
      } 
      break;
      case 'W':
        if (*_y - 1 >= 0){
      	if (map[*_y-1][*_x] == can_go_forward_view){
 /*    */ 	*_y -= 1;
       	}
      	} 
      break;
      case 'E':
 //     printf("%d,%d",have_bomb , have_more_one_bomb);
  // bomb_break(view[3],view[4],can_through_view,map);
 
    	break;
      case ' ':
      	//放下炸弹
      	if (!have_more_one_bomb ) {
  			have_bomb = TRUE;
  			have_more_one_bomb = TRUE;
  			//记录炸弹爆炸时间
			  bomb_break_= clock();
      	}  	   
 	break; 
 /*   */  
      }
//     if (ord != 'E')
    
	 }


void check_is_gameover(int *_y,int *_x, char map[][MAX_ARRAY_SIZE],char over_view){
  		if ( map[*_y][*_x] == over_view){
  		//	system("clear");
  			printf("Game over!");
  			exit(0);
  		}
}	

void check_is_gamewin(
	int *_y,
	int *_x,
	char map[][MAX_ARRAY_SIZE],
	char over_view){
  		if ( map[*_y][*_x] == over_view){
  		//	system("clear");
  			printf("Game Win!!!!");
  			exit(0);
  		}
}
		   
         
void bomb_break(char bomb_view,char break_view,char can_through_view[], char bomb_map[][MAX_ARRAY_SIZE]){
   int bomb_x,bomb_y;
   
   get_view_x_y(4,4,bomb_map,&bomb_x,&bomb_y,bomb_view);
   //printf("%c,%c,%d,%d\n",bomb_view,break_view,bomb_y,bomb_x);
   bomb_map[bomb_y][bomb_x] = break_view;
   
   
   
   for(int j =0;j<length_can_through_view;j++)
   	for(int a = 1; a <= 2; a++){
  	
   	if (bomb_map[bomb_y-a][bomb_x] == can_through_view[j] 
   		&&bomb_y-a >= 0)
   		bomb_map[bomb_y-a][bomb_x] = break_view;
   	if (bomb_map[bomb_y+a][bomb_x] == can_through_view[j]
   		&&bomb_y+a <=3)
   		bomb_map[bomb_y+a][bomb_x] = break_view;
   	if (bomb_map[bomb_y][bomb_x-a] == can_through_view[j] 
   		&&bomb_x-a >= 0)
   		bomb_map[bomb_y][bomb_x-a] = break_view;
   	if (bomb_map[bomb_y][bomb_x+a] == can_through_view[j]
   		&&bomb_x+a <=3)
   		bomb_map[bomb_y][bomb_x+a] = break_view;
	/*	*/
   		}
   }

     
       
void clear_view_in_map(char clear_view, char replace_view,int width, int height ,char view_array[][MAX_ARRAY_SIZE]){
     	for (int y = 0 ;y<height;y++){
			for (int x = 0 ; x < width;x++){
				if ( view_array[y][x] == clear_view){
					view_array[y][x] = replace_view;
				}
			}
  		}
}
 	 
 
/*
	打印一个char二维数组
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_ARRAY_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void display_view_array(int width, int height,
char view_array[][MAX_ARRAY_SIZE]){
	for (int y = 0;y<height;y++){
		for (int x = 0 ; x < width;x++){
			printf("%c%c", view_array[y][x], x == width - 1 ? '\n' : BLANK);
      }
    }
}
/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_ARRAY_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符		
*/
void get_view_x_y(int width, int height, char map[][MAX_ARRAY_SIZE], int *_x, int *_y,char view){
	for (int y = 0;y<height;y++){
		for (int x = 0 ; x < width;x++){
	      *_x = map[y][x] == view ? x : *_x;
	      *_y = map[y][x] == view ? y : *_y;
      }
  }
}
/*
#include <unistd.h>
#include <conio.h>

#include <stdio.h>

#include <locale.h>

int main() {

    int k;



//    setlocale(LC_ALL,"chs");

    printf("如果你三秒钟之内什么也不输入，我就输出-1。\n");

    sleep(3);

    if(!_kbhit())

        printf("-1\n");

    else {

        printf("输入了");

        while (1) {

            if (_kbhit()) {

                k=_getch();

				printf("%c",k);
                
            } else break;

        }

        printf("\n");

    }

    return 0;

}

*/
	 