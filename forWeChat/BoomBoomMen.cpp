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
#define T '#'
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define BOMB_TIME 0.03 //3s
#define SHOCK_WAVE_TIME 0.002 //0.2s
#define EMENY_MOVE_BREAK_TIME 0.02 //2s

//用于判断场上有没有炸弹 如果为TRUE则不再释放炸弹
int have_bomb = FALSE;

//用于判断场上有没有炸弹爆炸留下的冲击波
int have_shock_wave = FALSE;

//用于判断场上有没有炸弹 如果为TRUE则炸弹爆炸
int have_more_one_bomb = FALSE;

//炸弹冲击波可以消除的字符
char can_through_view[] = {P,E,BLANK,T};

//用于记录放下炸弹的时间，用于计算炸弹爆炸时间
clock_t bomb_break_ = 0;

//用于记录敌人数量
int emeny_number = 1;

//用于记录炸弹冲击波的长度
int break_shock_length = 1;

//用于记录敌人移动的时间
clock_t emeny_break_time[4] = {0};


//当前显示的map的宽
int current_width = 0;

//当前显示的map的高
int current_height = 0;

//计算can_through_view 的长度
int length_can_through_view = sizeof(can_through_view)/ sizeof(can_through_view[0]);

//////////////////////////////////////////////////

/*
	 bomb_break
	炸弹爆炸有冲击波向四个方向去
@bomb_view  			代表炸弹的字符
@break_view  		   代表冲击波的字符
@can_through_view[]	 代表可以被冲击波消除的字符的数组
@current_map[][MAX_SIZE]
						炸弹所在的char数组
@MAX_SIZE         最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void bomb_break(
	char bomb_view,
	char break_view,
	char can_through_view[],
	char current_map[][MAX_SIZE]);


/*
	check_is_gameover
	判断游戏是否结束
	通过判断map中某位置的字符是否被over_view取代判断游戏是否结束
@*_y						
@*_x
@map[][MAX_SIZE]
@ober_view
*/
void check_is_gameover(
	int *_y,
	int *_x,
	char current_map[][MAX_SIZE],
	char over_view);

/*
	check_is_gamewin
	判断游戏是否胜利
	通过判断map中某位置的字符是否被over_view取代判断游戏是否胜利
@*_y						
@*_x
@map[][MAX_SIZE]
@ober_view
*/
void check_is_gamewin(
	int *_y,
	int *_x,
	char current_map[][MAX_SIZE],
	char over_view);

/*
	check_is_over_time
	判断是否过了指定时间
@current_time						当前时间
@mark_time						   标记的时间
@break_time						  指定间隔时间

*/
bool check_is_over_time(
	clock_t current_time,
	clock_t mark_time,
	double break_time);



/*
	control_view_move
	控制某个特定字符在二维字符数组中“移动”
@width							 字符数组的列数
@height							字符数组的行数
@map[][MAX_SIZE]			 二维字符数组
@view[]							用于确定“移动”的字符
@*_x							   用于确定字符的列位置
@*_y							   用于确定字符的行位置
@can_go_forward_view			   判断为可以向前“移动“的字符
@MAX_SIZE 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void control_view_move(
	char order,
	char current_map[][MAX_SIZE],
	char view[],
	int *_x,
	int *_y,
	char can_go_forward_view[],
	int can_go_forward_view_length);    
  
/*
	打印一个char二维数组
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void display_view_array(
	char current_map[][MAX_SIZE]);

/*
	获取随机数字
@number					最大随机数字
*/
char get_random_order(int number);

/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符		
*/
void get_view_x_y(
	char current_map[][MAX_SIZE],
	int *_x,
	int *_y,
	char view);


/*
	主游戏运行程序
@width							当前Map的宽 
@height						   当前Map的高
@map[][MAX_SIZE]				  当前Map
@*_x							  角色X为主
@*_y							  角色Y位置
@view[]						   游戏控件的字符数组
*/
void main_game(
	char current_map[][MAX_SIZE],
	int *_x,
	int *_y,
	char view[]);
	
	
/* 
	replace_view_in_map特定字符替换为另一个字符
@clear_view						被替换的字符
@replace_view					  替换的字符
@width							 字符数组的列数
@height							字符数组的行数
@view_array[][MAX_SIZE]	  字符数组
@MAX_SIZE 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void replace_view_in_map(
	char clear_view,
	char replace_view,
	char current_map[][MAX_SIZE]);


//主程序
int main(void){
	/*
		view[0] 角色 
		view[1] 墙 
		view[2] 敌人 
		view[3] 炸弹 
		view[4] 冲击波
		view[5] 空白
		view[6] 可被炸开的道路
	*/
	char view[7] = { P,W,E,B,C,BLANK,T};

	char test_map[3][4][MAX_SIZE] =
	 {
	 {
	 {
	 },
	 {	
	 {view[1],view[1],view[1],view[1],view[1],view[1]},
	 {view[1],view[5],view[6],view[6],view[5],view[6]},
	 {view[1],view[5],view[2],view[1],view[5],view[1]},
	 {view[1],view[5],view[1],view[1],view[0],view[1]},
	 },
	 {	
	 {view[1],view[1],view[1],view[1]},
	 {view[1],view[5],view[6],view[6]},
	 {view[1],view[5],view[2],view[1]},
	 {view[1],view[0],view[1],view[1]},
	 }};

	int player_x = 0, player_y = 0; 
	
	current_width = 6;
	current_height = 4;
	char c_map[100][100];
	
	for (int y = 0; y < 100 ;y++){
		 
		 for (int x = 0; x < 100 ; x++){
		 	
		 	c_map[y][x] = view[6];
		 
		 }
	
	} 
	
	for (int y = 0; y < current_height ;y++){
		 
		 for (int x = 0; x < current_width ; x++){
		 	
		 	c_map[y][x] = test_map[0][y][x];
		 
		 }
	
	}
	
	clock_t long_clock_time = clock();
	
	double breaktime = 0.001f;
	
	get_view_x_y(c_map,&player_x,&player_y,view[0]);
	
	display_view_array(c_map);

	main_game(
		c_map,
		&player_x,
		&player_y,
		view);

	//printf("%d %d", 1 == (ord = getch()),true);	
  return 0;

}


/*
	before_time
*/
bool before_time(clock_t check_time, double break_time){
	return (((clock() - check_time) / (double)CLOCKS_PER_SEC) > break_time);
}

void control_view_move(
	char order,
	char current_map[][MAX_SIZE],
	char view[],
	int *_x,
	int *_y,
	char can_go_forward_view[],
	int can_go_forward_view_length){
	
	if (order == 'N'){
		order = getch();
		clock_t order_time = clock();
	} else if (order == 'R'){
		order = get_random_order(4);
	//	printf("%c\n",order);
//		exit(0);
	}
	
	order = toupper(order);
 
	for(int i = 0;i<can_go_forward_view_length;i++){
	  switch (order) {
	      case 'A':
	      
	      if (*_x -1 >= 0){
	      	
	      	if (current_map[*_y][*_x -1] ==
	      	 can_go_forward_view[i]){
	      		
	      		*_x -= 1;
	      		
	      		}      			
		//printf("emeny_control        A\n");
      	
      	} 
      	
      	break;
     case 'S':
     	if (*_y + 1 <= current_height){
     		
     		if (current_map[*_y+1][*_x] ==
     		 can_go_forward_view[i]){
 				
 				*_y += 1;
     			
     			}
         
         } 
     	
     	break;
     case 'D':
     	if (*_x +1 <= current_width){
     		
     		if (current_map[*_y][*_x +1] ==
     		 can_go_forward_view[i]){
     			
     			*_x += 1;
     		
     		}
      
     } 
     
     break;
     
     case 'W':
     	
     	if (*_y - 1 >= 0){
     		
     		if (current_map[*_y-1][*_x] ==
     		 can_go_forward_view[i]){
 				
 				*_y -= 1;
     			
     		}
     	
     	} 
     
		 break;
//     case 'E':
//     printf("%d,%d",have_bomb , have_more_one_bomb);
// bomb_break(view[3],view[4],can_through_view,map);
// 
//    	break;
      case ' ':
      	//放下炸弹
      	if (!have_more_one_bomb ) {
  			
  			have_bomb = TRUE;
  			
  			have_more_one_bomb = TRUE;
  			
  			//记录炸弹爆炸时间
			  bomb_break_= clock();
      	
      	}  	   
 		
 		break; 
   
      }
      
	}
}


void check_is_gameover(
	int *_y,
	int *_x,
	char current_map[][MAX_SIZE],
	char over_view){
  		if ( current_map[*_y][*_x] == over_view){
  		//	system("clear");
  			printf("Game over!");
  			exit(0);
  		}
}	

void check_is_gamewin(
	int *_y,
	int *_x,
	char current_map[][MAX_SIZE],
	char over_view){
  		if ( current_map[*_y][*_x] == over_view){
  		//	system("clear");
  			printf("Game Win!!!!");
  			exit(0);
  		}
}

bool check_is_over_time(
	clock_t current_time,
	clock_t mark_time,
	double break_time){
		if (((current_time - mark_time) / (double) CLOCKS_PER_SEC)
			> break_time)
			return true;
		else 
			return false;
}
		   
         
void bomb_break(
	char bomb_view,
	char break_view,
	char can_through_view[],
	char current_map[][MAX_SIZE]){
   int bomb_x,bomb_y;
   
   get_view_x_y(current_map,&bomb_x,&bomb_y,bomb_view);
   //printf("%c,%c,%d,%d\n",bomb_view,break_view,bomb_y,bomb_x);
   current_map[bomb_y][bomb_x] = break_view;
   
   
   
   for(int j =0;j<length_can_through_view;j++)
   	for(int a = 1; a <= break_shock_length; a++){
  	
   	if (current_map[a][bomb_x] == can_through_view[j] 
   		&&bomb_y-a >= 0)
   		current_map[bomb_y-a][bomb_x] = break_view;
   	if (current_map[bomb_y+a][bomb_x] == can_through_view[j]
   		&&bomb_y+a <=3)
   		current_map[bomb_y+a][bomb_x] = break_view;
   	if (current_map[bomb_y][bomb_x-a] == can_through_view[j] 
   		&&bomb_x-a >= 0)
   		current_map[bomb_y][bomb_x-a] = break_view;
   	if (current_map[bomb_y][bomb_x+a] == can_through_view[j]
   		&&bomb_x+a <=3)
   		current_map[bomb_y][bomb_x+a] = break_view;
	/*	*/
   		}
   }

     
       
 	 
 
/*
	打印一个char二维数组
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
	
*/
void display_view_array(char current_map[][MAX_SIZE]){
	
	for (int y = 0;y<current_height;y++){
		
		for (int x = 0 ; x < current_width;x++){
			
			printf("%c%c", current_map[y][x], x == current_width - 1 ? '\n' : BLANK);
      
      }
    
    }

}

char get_random_order(int number){
	
	int r;
	
	r =  rand() % number + 1;

	switch(r){
		case 1:
			return 'W';
		case 2:
			return 'S';
		case 3:
			return 'D';
		case 4:
			return 'A';
		default:
			return 'N';
	}
	
	}
	

/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@MAX_SIZE		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符		
*/
void get_view_x_y(
	char current_map[][MAX_SIZE],
	int *_x,
	int *_y,
	char view){
	for (int y = 0;y<current_height;y++){
		for (int x = 0 ; x < current_width;x++){
	      *_x = current_map[y][x] == view ? x : *_x;
	      *_y = current_map[y][x] == view ? y : *_y;
      }
  }
}	 


void main_game(
	char current_map[][MAX_SIZE],
	int *_x,
	int *_y,
	char view[]){
	clock_t long_clock_time;
	int emeny_x,emeny_y;	
	clock_t emeny_move_time = 0;	
	
	for(clock_t current_time;;){
		//如果时间间隔大于breaktime，就刷新一次屏幕
		//每次循环都需要重新取而当前时间
		current_time = clock();
		
		//如果有键盘敲打
		if (kbhit()){
			//记录刷新的时间用于判断时间间隔
			long_clock_time = clock();
		
			//调用
 		   if (current_map[*_y][*_x] != view[3])
				current_map[*_y][*_x] = 
 		 	  	have_bomb == TRUE ? 
 		 	  	current_map[*_y][*_x] :view[5];
 		   //角色移动
 		   //角色可以通过的字符的数组的长度
 		   int player_can_go_through_length = 1;
 		  
 		   //角色可以通过的字符的数组
 		   char player_can_go_through[
 		   player_can_go_through_length] = {view[5]};
 	   	
 	   	//
 		   have_bomb = FALSE;

 		   
 		   //控制角色移动
 		   control_view_move(
 		   	'N',
 		   	current_map,
 		   	view,
 		   	_x,
 		   	_y,
 		   	player_can_go_through,
 		   	1);
 	   
 	   
			if (current_map[*_y][*_x] != view[3])
				current_map[*_y][*_x] = 
				have_bomb ? view[3] :view[0];
		 
		
		}

		if(check_is_over_time(
				current_time,
				emeny_move_time,
				EMENY_MOVE_BREAK_TIME)){
				
		//敌人数量
		int emeny_number = 1;
		
		//敌人可以通过的字符的数组的长度
 	   int emeny_can_go_through_length = 2;
 	   
 	   //敌人可以通过的字符的数组
 	   char emeny_can_go_through[emeny_can_go_through_length] = {view[0],view[5]};
 	   //获得敌人位置
 	   get_view_x_y(
 	      current_map,
 	  	&emeny_x,
 	  	&emeny_y,
 	  	view[2]);
 			
 	   //控制敌人移动
 	  // char emeny_order = get_random_order();
 	  current_map[emeny_y][emeny_x] = view[5];
 	   
 	  control_view_move(
 	   	'R',
 	   	current_map,
 	   	view,
 	   	&emeny_x,
 	   	&emeny_y,
 	   	emeny_can_go_through,
 	   	emeny_can_go_through_length);
 	   
		current_map[emeny_y][emeny_x] = view[2];
		
		emeny_move_time = clock();
		}
 		 	
		system("clear");	
	    
	    display_view_array(current_map);
		check_is_gameover(
			_y,
			_x,
			current_map,
			view[2]);
  	    
		printf("游戏时间：%0.4lf\n",(current_time/(double) CLOCKS_PER_SEC));
		
		//到达时间后炸弹爆炸
		if (have_more_one_bomb){
			printf("间隔时间: %0.2lf\n",((double)BOMB_TIME - ((current_time - bomb_break_) / (double) CLOCKS_PER_SEC)));	
	 	
			if(check_is_over_time(
				current_time,
				bomb_break_,
				BOMB_TIME)){
				have_more_one_bomb = FALSE; 	 
  		
  			  bomb_break(view[3],
  			  view[4],can_through_view,current_map);
  			  
  			  
  			  bomb_break_ = clock();
  			  
  			  have_shock_wave = TRUE;
			 }
			 
		} else if (have_shock_wave){
			if(
			check_is_over_time(
				current_time,
				bomb_break_,
				SHOCK_WAVE_TIME)){
				
				check_is_gameover(
					_y,
					_x,
					current_map,
					view[4]);
  			   
  			  
  			  check_is_gamewin(
					&emeny_y,
					&emeny_x,
					current_map,
					view[4]);
  			    
				replace_view_in_map(
					view[4],
					view[5],
					current_map);
					
				have_shock_wave = !have_shock_wave;
 			}			
		}		
	}
}


void replace_view_in_map(
	char clear_view,
	char replace_view,
	char current_map[][MAX_SIZE]){
     	for (int y = 0 ;y<current_height;y++){
			for (int x = 0 ; x < current_width;x++){
				if ( current_map[y][x] == clear_view){
					current_map[y][x] = replace_view;
				}
			}
  		}
}