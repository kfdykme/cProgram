#include <stdio.h>
#include <string.h>

#define GOOD_MAX 100

int e_number = 0;

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char name[20];
  float price;
  Date date_pru;
  int enter_ord;
} Goods;

Goods all_g[GOOD_MAX];

void edit_data(Goods g);
void delete_data(Goods g);
void inquiry_data(Goods g);
void enter_data(Goods g[]);

int main(void) {
  int order_number;



  while (order_number != 5) {
    printf("输入数字来选择功能：\n"
           "\t 1. 商品信息修改\n"
           "\t 2. 商品信息删除\n"
           "\t 3. 商品信息查询\n"
           "\t 4. 商品信息录入\n" "\t 5. 推出系统并保存\n" "");

    scanf("%d", &order_number);

    switch (order_number) {
    case 1:
      // edit_data();
      break;
    case 2:
      // delete_data();
      break;
    case 3:
      // inquiry_data();
      break;
    case 4:
      enter_data(all_g);

      break;
    default:
      break;
    }
  }

  return 0;
}

void enter_data(Goods g[]) {

  printf("Enter goods' name: ");
  scanf("%s", g[e_number].name);
  printf("Enter goods' price($): ");
  scanf("%f", &g[e_number].price);
  printf("Enter goods' pru_date: ");
  scanf("%d.%d.%d", &g[e_number].date_pru.year,
        &g[e_number].date_pru.month, &g[e_number].date_pru.day);
/*		printf("Your entered goods：\n"
			       "\t name:\t%s\n"
			       "\t price:\t%0.2f$\n"
			       "\t data: %d.%d.%d \n"
			       "\n\n",
			       all_g[e_number].name,
			       all_g[e_number].price,
			       all_g[e_number].date_pru.year,
			       all_g[e_number].date_pru.month,
			       all_g[e_number].date_pru.day,
			       );*/

  printf("Your entered goods：\n"
          "\t name:\t%s\n"
          "\t price:\t%0.2f$\n"
          "\t data: %d.%d.%d \n"
          "\n\n",
          g[e_number].name,
          g[e_number].price,
          g[e_number].date_pru.year,
          g[e_number].date_pru.month,
          g[e_number].date_pru.day);
          
  e_number++;
}