/*
	CBooM
	（控制台上的）仿炸弹人游戏
			－枋
			啊啊啊啊啊啊
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#define P '&'
#define W '+'
#define E '$'
#define B 'o'
#define C 'X'
#define BLANK ' '
#define T '#'
#define TRUE 1
#define FALSE 0
#define M_S 30
#define S_Y 5
#define S_X 5
#define BOMB_TIME 0.1 //3s
#define SHOCK_WAVE_TIME 0.002 //0.2s
#define EMENY_MOVE_BREAK_TIME 0.04 //2s
#define GAME_WIN 4

//vieW数据
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


//map数据
/*
	依旧是三维数组存储整个游戏要用到“场景“
	为了看上去更加直观（以及每行数量的限制）
	可以看出我还在纠结到底再数组中有变量表示
	还是直接用字符串

	一番纠结后 鉴于刚学完字符串 那就字符串吧

	为了在函数中调用数组的时候更➕顺利
	我将数组的第三维的长度设置为一个较长的常量M_S(M_S)的意思

	（第二维可以不设为M_S
	因为在实际调用时 每次只是调用一个二维数组
	如 data_map[0] 就是一个二维数组
	然后在其他函数中调用该数组时 （行可以省略对吧 不懂看书去）
	）



*/
char data_map[4][M_S][M_S] =
	 {
	 {
	 {view[5],view[5],view[5],view[5],view[5],view[5]},
	 {view[5],view[0],'S','T','A','R'},
	 {view[5],view[5],view[5],view[5],view[5],view[5]},
	 {' ',' ','E','x','I','T'},
	 },
	 {
	  {"                "},
	  {"#+#+ + + +#+ + +"},
	  {"#    $      +   "},
	  {" + + + + + + + +"},
	  {"      #        &"}
	 },
	 {
	  {"  #  ## #     "},
	  {"&+++#+#+ +++  "},
	  {"#+        $+# "},
	  {"#+ +++ +++ +# "},
	  {"$  + # # +##  "},
	  {"#+#+#+$+ + +# "},
	  {"#+## # #    +#"},
	  {" +#+ + +#++ ++"},
	  {"$+   # # #$ # "},
	  {" +++#+ +#+#+  "},
	  {"              "}
	 },
	 {
	  {"              "},
	  {"       $      "},
	  {"              "},
	  {"         $    "},
	  {"   &          "},
	  {"              "},
	  {"       $      "},
	  {"              "},
	  {"   $          "},
	  {"   $      $   "},
	  {"              "}
	 }};
/*
	用来记录第几个“场景”的宽度是多少
	既然我上面都用字符串写了
	这里我就懒得用sizeof 自动计算了
	数数多好对吧

	宽度用于在将小的‘场景’“加载”到整个大的游戏画面中时for循环都哪里
	（不知道我说啥的看上一期）

	就是sizeof用错几次懒得去看
*/
int data_width[4] =
 	{6,16,14,14};
//用途同上
int data_height[4] = {4,5,11,11};


//开始的行数 就是在菜单那里要在哪一行按了空格就进入游戏
int start_row = 1;

//退出的行数 意义类上
int exit_row = 3;

//用于判断场上有没有炸弹 如果为TRUE则不再释放炸弹
int have_bomb = FALSE;

//用于判断场上有没有炸弹爆炸留下的冲击波
int have_shock_wave = FALSE;

//用于判断场上有没有炸弹 如果为TRUE则炸弹爆炸
int have_more_one_bomb = FALSE;

//炸弹冲击波可以消除的字符
char can_through_view[] = {P,E,BLANK,T};

//用于记录放下炸弹的时间，该时间加上常量BOMB TIME就是炸弹爆炸的时间
clock_t bomb_break_ = 0;

//用于记录敌人数量 我懒 我数数 我自豪
int emeny_number[M_S] = {0,1,5,6};

//给敌人的X 和 Y坐标来个出的定义
//有多的浪费了内存 （但我并不想在意！！）
int emeny_x[M_S]={0},emeny_y[M_S]={0};

//用于记录炸弹冲击波的长度
//1的话就是炸出一个＋
int break_shock_length = 1;


// 计算can_through_view 的长度
// 为了用循环在移动前判断前方小兵 哦不前方的Char
// 是否为该移动ing的char可以压过 穿过 透过的 我设了数组
// 需要的时候修改那个数组数据就好了
int length_can_through_view = sizeof(can_through_view)/ sizeof(can_through_view[0]);

//记录当前关卡 	0－菜单 1－第一关
int game_map_lv = 0;

//记录当前关卡是否胜利 等待加载下一关卡
bool is_win = false;

//////////////////////////////////////////////////

/*
	 bomb_break
	炸弹爆炸有冲击波向四个方向去
@bomb_view  			代表炸弹的字符
@break_view  		   代表冲击波的字符
@can_through_view[]	 代表可以被冲击波消除的字符的数组
@current_map[][M_S]
						炸弹所在的char数组
@M_S         最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void bomb_break(
	char bomb_view,
	char break_view,
	char can_through_view[],
	char current_map[][M_S]);

/*
	check_is_gameover
	判断游戏是否结束
	通过判断map中某位置的字符是否被over_view取代判断游戏是否结束
@*_y
@*_x
@map[][M_S]
@ober_view
*/
void check_is_gameover(
	int *_y,
	int *_x,
	char current_map[][M_S],
	char over_view);

/*
	check_is_gamewin
	判断游戏是否胜利
	通过判断map中某位置的字符的数量是否为零判断游戏是否胜利
@map[][M_S]
@ober_view
*/
void check_is_gamewin(
	char current_map[][M_S],
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
@order 							判断不同的移动类型
									‘N’是玩家移动
									‘R’是“敌人”单位随机移动
@width							 字符数组的列数
@height							字符数组的行数
@map[][M_S]			 二维字符数组
@view[]							用于确定“移动”的字符
@*_x							   用于确定字符的列位置
@*_y							   用于确定字符的行位置
@can_go_forward_view			   判断为可以向前“移动“的字符
@can_go_forward_view_length		上一个字符数组的长度
@M_S 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void control_view_move(
	char order,
	char current_map[][M_S],
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
@M_S		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）

*/
void display_view_array(
	char current_map[][M_S]);

/*
	获取随机命令
@number					最大随机数字

number>4时 随机到四以上则是不作反应

*/
char get_random_order(int number);

/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@view_array[][]		 char数组
@M_S		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符
*/
void get_view_x_y(
	char current_map[][M_S],
	int *_x,
	int *_y,
	char view);


/*
	get_emenygroup_x_y
	类似get_view_x_y
@map[][M_S]				  获取字符所在的字符数组
@view						要获取的字符
*/
void get_emenygroup_x_y(
	char map[][M_S],
	char view);

/*
	get_view_number
	获取某个数组中某个字符的数量
@map[][M_S]				某字符数组
@view 					 某字符
*/
int get_view_number(
		char map[][M_S],
		char view);


/*
	load_map
	读取map资料
@current_map[][M_S]		将第一个数组全部变为数组
@load_map[][M_S]		   然后将第二个数组从常量S_X
						   S_Y开始覆盖到第一个数组上
@load_view				 角色.炸弹等字符数组
*/
void load_map(
	char current_map[][M_S],
	char load_map[][M_S],
	char load_view[M_S]
	);

/*
	主游戏运行程序
@map[][M_S]				  当前Map
@*_x							  角色X为主
@*_y							  角色Y位置
@view[]						   游戏控件的字符数组
*/
void main_game(
	char current_map[][M_S],
	int *_x,
	int *_y,
	char view[]);


/*
	replace_view_in_map
	特定字符替换为另一个字符
@clear_view						被替换的字符
@replace_view					  替换的字符
@view_array[][M_S]				 字符数组
@M_S 			      			最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void replace_view_in_map(
	char clear_view,
	char replace_view,
	char current_map[][M_S]);


//主程序
int main(void){


	//”绘制“？整个游戏画面Suoyong所用的数组
	char c_map[M_S][M_S];
	//角色只有一个嘛 就用指针的形式传入函数内
	int player_x = 0, player_y = 0;

	//将第一个数组全部变为数组
	//然后将第二个数组从常量S_X S_Y开始覆盖到第一个数组上
	//角色等的数组
	load_map(c_map,data_map[game_map_lv],view);


	//将游戏画面内的角色字符所在的行数列数赋值给变量
	get_view_x_y(
  	c_map,
  	&player_x,
  	&player_y,
  	view[0]);
	//以上是开始游戏前的初始化

	//主要游戏开始啦
	main_game(
		c_map,
		&player_x,
		&player_y,
		view);

}

/*
	 bomb_break
	炸弹爆炸有冲击波向四个方向去
@bomb_view  			代表炸弹的字符
@break_view  		   代表冲击波的字符
@can_through_view[]	 代表可以被冲击波消除的字符的数组
@current_map[][M_S]
						炸弹所在的char数组
@M_S         最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/
void bomb_break(
	char bomb_view,
	char break_view,
	char can_through_view[],
	char current_map[][M_S]){
    int bomb_x,bomb_y;
   //获取炸弹的位置
   get_view_x_y(current_map,&bomb_x,&bomb_y,bomb_view);

   //先将炸弹自己的位置的字符变为爆炸的字符
   current_map[bomb_y][bomb_x] = break_view;

   //循环厉遍四个方向 符号条件的就将该位置的char变为
   //代表冲击波的字符
   for (int j =0;j<length_can_through_view;j++)

   	for (int a = 1; a <= break_shock_length; a++){

   	if (current_map[bomb_y-a][bomb_x] == can_through_view[j]
   		&&bomb_y-a >= S_Y)

   		current_map[bomb_y-a][bomb_x] = break_view;

   	if (current_map[bomb_y+a][bomb_x] == can_through_view[j]
   		&&bomb_y+a <= S_Y+data_height[game_map_lv])

   		current_map[bomb_y+a][bomb_x] = break_view;
   	if (current_map[bomb_y][bomb_x-a] == can_through_view[j]
   		&&bomb_x-a >= S_X)

   		current_map[bomb_y][bomb_x-a] = break_view;
   	if (current_map[bomb_y][bomb_x+a] == can_through_view[j]
   		&&bomb_x+a <= S_X+data_width[game_map_lv])

   		current_map[bomb_y][bomb_x+a] = break_view;
		}
}

/*
	check_is_gameover
	判断游戏是否结束
	通过判断map中某位置的字符是否被over_view取代判断游戏是否结束
@*_y
@*_x
@map[][M_S]
@ober_view
*/


void check_is_gameover(
	int *_y,
	int *_x,
	char current_map[][M_S],
	char over_view){
  		if ( current_map[*_y][*_x] == over_view && game_map_lv != 0){
  		//	system("clear");
  			printf("\n\n\n\t\tGame over!\n\t\t按下任意键to restart!");
			getch();

			load_map(
			current_map,data_map[game_map_lv],view);



			//将游戏画面内的角色字符所在的行数列数赋值给变量
			get_view_x_y(
 		 	current_map,
  			_x,
  			_y,
  			view[0]);
	//以上是开始游戏前的初始化

  		}
}


/*
	check_is_gamewin
	判断游戏是否胜利
	通过判断map中某位置的字符的数量是否为零判断游戏是否胜利
@map[][M_S]
@ober_view
*/

void check_is_gamewin(
	char current_map[][M_S],
	char over_view){

		  //printf("%d\n",get_view_number
  		//(current_map,over_view));
  		if (get_view_number
  		(current_map,over_view) == 0){
  			is_win = true;
  		//	printf("is_win = true");
  		}
}

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
	double break_time){
		if (((current_time - mark_time) / (double) CLOCKS_PER_SEC)
			> break_time)
			return true;
		else
			return false;
}


/*
	control_view_move
	控制某个特定字符在二维字符数组中“移动”
@order 							判断不同的移动类型
									‘N’是玩家移动
									‘R’是“敌人”单位随机移动
@width							 字符数组的列数
@height							字符数组的行数
@map[][M_S]			 二维字符数组
@view[]							用于确定“移动”的字符
@*_x							   用于确定字符的列位置
@*_y							   用于确定字符的行位置
@can_go_forward_view			   判断为可以向前“移动“的字符
@can_go_forward_view_length		上一个字符数组的长度
@M_S 			       最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/

void control_view_move(
	char order,
	char current_map[][M_S],
	char view[],
	int *_x,
	int *_y,
	char can_go_forward_view[],
	int can_go_forward_view_length){

	//如果一开始接受的order是'N'就读取用户的按键
	//如果是'R'就随机生成指令

	/*
		因为使用随机数生成的所以移动方式会有点奇怪
	*/

	if (order == 'N'){
		order = getch();
			clock_t order_time = clock();
	} else if (order == 'R'){
		order = get_random_order(4);
	}
	/*
		如何移动与之前类似
		只不过多了用循环判断不同的可前进条件
	*/
		//转换成大写字母 方便switch
		order = toupper(order);

	for (int i = 0;i<can_go_forward_view_length;i++){
	  switch (order) {
	      case 'A':

	      if (*_x -1 >= S_X){

	      	if (current_map[*_y][*_x -1] ==
	      	 can_go_forward_view[i]){

	      		*_x -= 1;

     			//为了每次只走一格哟
     			return ;

	      		}

     	 	}

       	break;
     	case 'S':
     		if (*_y + 1 < S_Y +data_height[game_map_lv]){

     			if (current_map[*_y+1][*_x] ==
     			 can_go_forward_view[i]){

 					*_y += 1;

     				return ;

     			}

     	    }

       	break;
     	case 'D':
     		if (*_x +1 < S_X +data_width[game_map_lv]){

     			if (current_map[*_y][*_x +1] ==
     			 can_go_forward_view[i]){

     				*_x += 1;

     				return ;
     			}

     		}

       	break;
    	 case 'W':

    	 	if (*_y - 1 >= S_Y){

    	 		if (current_map[*_y-1][*_x] ==
    	 		 can_go_forward_view[i]){

 					*_y -= 1;

     				return ;

     			}

    	 	}
       	break;
        case ' ':

      	//在菜单里面的话空格是确认键 不会放下炸弹
  	    	if (!game_map_lv){
    	  		if ((*_y - S_Y) == start_row){
     	 			load_map(
      					current_map,
      					data_map[++game_map_lv],
      					view);

      				get_view_x_y(
  						current_map,
  						_x,
  						_y,
  						view[0]);

					  display_view_array(current_map);
	      		} else if ((*_y - S_Y) == exit_row){
 	     			system("clear");

 	     			printf("\n\n\n\t\tGAME END");

 	     			exit(0);
	      		}

      	} else if (!have_more_one_bomb
      	) {


	      	have_bomb = TRUE;

  			have_more_one_bomb = TRUE;

  			//记录炸弹放下时间
			  bomb_break_= clock();

      	}

 		break;

      }

	}
}





/*
	打印一个char二维数组
@width  				char数组的列数
@height 				char数组的行数
@view_array[][]		 char数组
@M_S		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）

*/
void display_view_array(char current_map[][M_S]){

	for (int y = 0 ; y < M_S;y++){

		for (int x = 0 ; x < M_S;x++){

			printf("%c%c", current_map[y][x], x == M_S - 1 ? '\n' : BLANK);

      }

    }

}
/*
	获取随机命令
@number					最大随机数字

number>4时 随机到四以上则是不作反应

*/


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
	get_emenygroup_x_y
	类似get_view_x_y
@map[][M_S]				  获取字符所在的字符数组
@view						要获取的字符
*/

void get_emenygroup_x_y(
	char map[][M_S],
	char view){
		int i = 0;
	for (int y = 0; y< M_S;y++){
	for (int x = 0; x< M_S;x++){
		if (map[y][x] == view){
			emeny_y[i] = y;
			emeny_x[i++] = x;
		}
	}
	}
//	printf("%d\n",i);
//	getch();
//	exit(0);
}


/*
	在一个char 二维数组中获取某字符在其中的(y,x)
@view_array[][]		 char数组
@M_S		 最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
@*_x					获取的该字符的x
@*_y					获取的该字符的y
@view 				  某字符
*/
void get_view_x_y(
	char current_map[][M_S],
	int *_x,
	int *_y,
	char view){
	for (int y = 0;y<M_S;y++){
		for (int x = 0 ; x < M_S;x++){
	      *_x = current_map[y][x] == view ? x : *_x;
	      *_y = current_map[y][x] == view ? y : *_y;
      }
  }
}

/*
	get_view_number
	获取某个数组中某个字符的数量
@map[][M_S]				某字符数组
@view 					 某字符
*/


int get_view_number(
		char map[][M_S],
		char view){
	int i = 0;
	for (int y =0 ; y < M_S; y++){
		for (int x = 0; x < M_S ;x++){
			if( map[y][x] == view )
				i++;
		}
	}

	return i;

		}


/*
	load_map
	读取map资料
@current_map[][M_S]		将第一个数组全部变为数组
@load_map[][M_S]		   然后将第二个数组从常量S_X
						   S_Y开始覆盖到第一个数组上
@load_view				 角色.炸弹等字符数组
*/void load_map(
	char current_map[][M_S],
	char load_map[][M_S],
	char load_view[M_S]
	){

	//新定义的Char数组充满乱码 我们把它清空吧
	for (int y = 0; y < M_S ;y++){

		 for (int x = 0; x < M_S ; x++){

		 	current_map[y][x] = ' ';

		 }

	}

	//所谓将字符从Xxxx开始覆盖到>......
	for (int y = 0; y <= S_Y +data_height[game_map_lv] ;y++){

		 for (int x = 0; x <= S_X + data_width[game_map_lv] ; x++){

		 	if ( x >= S_X && y >= S_Y)
		 		current_map[y][x] =
		 			load_map[y-S_Y][x-S_X];

		 	// 围一个边框
		 	if ((( y  == S_Y - 1
		 		|| y == S_Y + data_height[game_map_lv])
		 		&& x >= S_X)
		 		|| (( x == S_X -1
		 		|| x == S_X + data_width[game_map_lv])
		 			&& y >= S_Y))
		 		current_map[y][x] = '.';

		 }

	}


	get_emenygroup_x_y(current_map,view[2]);

}


void main_game(
	char current_map[][M_S],
	int *_x,
	int *_y,
	char view[]){
	clock_t long_clock_time;
	clock_t emeny_move_time = 0;

	for(clock_t current_time;;){
		//每次循环都需要重新取而当前时间
		current_time = clock();

		//如果有键盘敲打
		/*
			Kbhit()这个函数在按下键盘的时候返回True好像
			没错我上网查的

			属于<conio.h>头文件
		*/
		if (kbhit()){
			//记录刷新的时间用于判断时间间隔
			long_clock_time = clock();

			//处理刚放下炸弹时炸弹与角色重合的情况
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

 	   	//如果不改的话会发生很有趣的事 可以一试
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

 	   	//呼应值得一试 不告诉你
			if (current_map[*_y][*_x] != view[3])
				current_map[*_y][*_x] =
				have_bomb ? view[3] :view[0];


		}

		//超过了一定时间的话就使敌人移动吧
		if(check_is_over_time(
				current_time,
				emeny_move_time,
				EMENY_MOVE_BREAK_TIME)){


		//敌人可以通过的字符的数组的长度
 	   int emeny_can_go_through_length = 2;

 	   //敌人可以通过的字符的数组
 	   char emeny_can_go_through[emeny_can_go_through_length] = {view[0],view[5]};

 	   //多个敌人 所以有循环
 	  for (int i = 0; i<emeny_number[game_map_lv];i++){
		if (current_map[emeny_y[i]][emeny_x[i]] != view[2])
			continue;
 	   //控制敌人移动
 	  // char emeny_order = get_random_order();
 	  current_map[emeny_y[i]][emeny_x[i]] = view[5];

 	  //不在菜单及还没有胜利的时候才有敌人移动
 	  if (!is_win && (game_map_lv != 0))
 	  control_view_move(
 	   	'R',
 	   	current_map,
 	   	view,
 	   	&emeny_x[i],
 	   	&emeny_y[i],
 	   	emeny_can_go_through,
 	   	emeny_can_go_through_length);
 	//control_view...中只改变了 x y 的值和清楚了旧有的字符
 	//并没有添加新的字符的新的位置
		current_map[emeny_y[i]][emeny_x[i]] = view[2];
	 //移动完了就记下时间 用于判断下一次移动
		emeny_move_time = clock();
		}
 	   }


		system("clear");

	    display_view_array(current_map);
		/*
		printf("敌人数量 = [%d] ",get_view_number(
			current_map,
			view[2]));

		for (int i = 0;i < emeny_number[game_map_lv];i++){
			printf("敌人[%d] (%d,%d)\n",
				emeny_x[i],emeny_y[i]);
		}
		*/
		//看看游戏结束的条件有没有达成
		//在显示了画面之后再判断更加自然
		//这是判断有没有自己炸死自己
		check_is_gameover(
					_y,
					_x,
					current_map,
					view[4]);
		//
		for (int i = 0; i<emeny_number[game_map_lv];i++)
		//判断是不是赢了
		//加入循环是因为
		//当一开始没有敌人的时候是不会执行这条语句的
		check_is_gamewin(
			current_map,
			view[2]);


		//这是判断有没有碰上敌人
		check_is_gameover(
			_y,
			_x,
			current_map,
			view[2]);

  	   //胜利条件达成
     	if (is_win){

     		//如果已经是最后一关了 就胜利 跳回菜单
     		if (game_map_lv == GAME_WIN -1){
		     	printf("\n\n\n\t\tGame Win!!!!");
				 getch();
				 game_map_lv = 0;
				 goto after_win_game;
  		   }

  		//询问是否下一关

     		printf("\n\n\n\t"
     		       "Go to next or return to menu?(Y/N)");
     	  win_choose:

     		switch(toupper(getch())){
     			case 'Y':
					++game_map_lv;break;
				 case 'N':
				 	game_map_lv = 0;
				 	/*replace_view_in_map(
				 		view[2],
				 		view[5],
				 		current_map);
				 	*/break;
				 default:
				 	//乱按就跳回去 直到做出选择
				 	goto win_choose;
     		}
    //这是游戏胜利后 不经过选择 按下任意键盘直接诶跳回菜单
    after_win_game:
     		system("clear");

		  	load_map(
     			 current_map,
     			 data_map[game_map_lv],
     	 		view);

  			get_view_x_y(
  				current_map,
  				_x,
  				_y,
  				view[0]);

			  display_view_array(current_map);

			  //每一次从新加载画面都将是否胜利改回为否
			  is_win = !is_win;
				}

		//显示邮箱时间嘛
	//up	printf("游戏时间：%0.4lf\n",(current_time/(double) CLOCKS_PER_SEC));

		//到达时间后炸弹爆炸
		//如果场上有炸弹
		if (have_more_one_bomb){
			//如果超过了指定时间
			if(check_is_over_time(
				current_time,
				bomb_break_,
				BOMB_TIME)){
				//准备爆炸了 将变量改回
				have_more_one_bomb = FALSE;

  			  //调用函数实现爆炸的效果
  			  bomb_break(view[3],
  			  view[4],can_through_view,current_map);

  			  //计时 判断冲击波的消失
  			  bomb_break_ = clock();

				//现在场上有冲击波
  			  have_shock_wave = TRUE;
			 }
			 //如果有冲击波
		} else if (have_shock_wave){
			//如果冲击波已经存在了一定时间
			//这是为了保证爆炸效果能被肉眼看见
			if(
			check_is_over_time(
				current_time,
				bomb_break_,
				SHOCK_WAVE_TIME)){

				//将冲击波覆盖的字符改为空白
				replace_view_in_map(
					view[4],
					view[5],
					current_map);
				//现在没有冲击波了
				have_shock_wave = !have_shock_wave;
 			}
		}
	}
}

/*
	replace_view_in_map
	特定字符替换为另一个字符
@clear_view						被替换的字符
@replace_view					  替换的字符
@view_array[][M_S]				 字符数组
@M_S 			      			最大长度 用于匹配数组
		（c99才可以用变长二维数组作参数）
*/

void replace_view_in_map(
	char clear_view,
	char replace_view,
	char current_map[][M_S]){
     	for (int y = 0 ;y<M_S;y++){
			for (int x = 0 ; x < M_S;x++){
				if ( current_map[y][x] == clear_view){
					current_map[y][x] = replace_view;
				}
			}
  		}
}
