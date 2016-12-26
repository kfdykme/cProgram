#include <stdio.h>
#include <string.h>

#define GOOD_MAX 100

int e = 0;
/*			GoodInfo* pGoodInfo = (GoodInfo*)malloc(sizeof(GoodInfo));
			strcpy(pGoodInfo->good_id,temp.good_id);
			strcpy(pGoodInfo->good_name,temp.good_name);
			strcpy(pGoodInfo->good_price, temp.good_price);
			strcpy(pGoodInfo->good_discount, temp.good_discount);
			pGoodInfo->good_amount = temp.good_amount;
			pGoodInfo->good_remain = temp.good_remain;
			Goods[i] = pGoodInfo;*/


typedef struct {
  int id;
  char name[20];
  float price;
  float discount;
  int amount;
} Goods;

Goods all_g[GOOD_MAX];

void edit_data(Goods g);
void delete_data(Goods g);
void inquiry_data(Goods g[]);
void enter_data(Goods g[]);

all_g[0]{
	id = 000;
	name[] = "kfdykme";
	price = 2.2;
	discount = 0.7;
	amount = 1;
	}

all_g[1] = {
	id = 001;
	name[] = "可乐";
	price = 2.5;
	discount = 1;
	amount = 100;
	}



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
       inquiry_data(all_g);
      break;
    case 4:
      enter_data(all_g);

      break;
    default:
  	printf("无效操作\n\n");
      break;
    }
  }

  return 0;
}

void enter_data(Goods g[]) {

    printf("Enter goods' id: ");
    scanf("%d",&g[e].id);
    printf("Enter goods' name: ");
    scanf("%s", g[e].name);
    printf("Enter goods' price($): ");
    scanf("%f", &g[e].price);
    printf("Enter goods' discount: ");
	scanf("%f",&g[e].discount);
	printf("Enter goods amount: ");
	scanf("%d",&g[e].amount);         
  e++;
}


void inquiry_data(Goods g[]){
	
	char name[20];
	int id;
	int choice;
	
	printf("You can inquiry goods' data by \n"
	       "1 id\n"
	       "2 name\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("Please enter the id: ");
			
			scanf("%d",&id);
	
			for( int i = 0 ; i < e;i++){
				if (g[i].id == id){
					printf("Goods' info of %d :\n"
			 		      "\tid: %d\n"
			   		    "\tname: %s\n"
			  		     "\tprice: %0.2f\n"
			    		   "\tdiscount: %0.2f\n"
			     		  "\tamount: %d\n",
			       g[i].id,
			       g[i].id,
			       g[i].name,
			       g[i].price,
			       g[i].discount,
			       g[i].amount);
			       return;
				}
			}
			printf("无效查询\n\n");
			break;
		case 2:
			printf("Please enter the name: ");
			
			scanf("%s",name);
	
			for( int i = 0 ; i < e;i++){
				if (!strcmp( g[i].name,name)){
					printf("Goods' info of %s :\n"
			 		      "\tid: %d\n"
			   		    "\tname: %s\n"
			  		     "\tprice: %0.2f\n"
			    		   "\tdiscount: %0.2f\n"
			     		  "\tamount: %d\n",
			       g[i].name,
			       g[i].id,
			       g[i].name,
			       g[i].price,
			       g[i].discount,
			       g[i].amount);
				   return;
				}
			}
		default:
			printf("无效查询\n\n");
			break;
	}
	
}
	

