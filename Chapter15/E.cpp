#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define FILE_NAME "good_info.txt"

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
  char id[30];
  char name[20];
  char price[10];
  char discount[10];
  int amount;
  int remain;
} Goods ;

Goods AGo[MAX] ;
	

void delete_D(Goods g[]);
void edit(Goods g[]);
void enter(Goods g[]);
void goods_info_ini();
void inquiry(Goods g[]);



int main(void) {
	int order_number;
	goods_info_ini();
	while (order_number != 5) {
    	printf("\n-----------------------------------------------------------\n"
    	       "\n"
    	       "输入数字来选择功能：\n"
     	      "\t 1. 商品信息修改\n"
     	      "\t 2. 商品信息删除\n"
     	      "\t 3. 商品信息查询\n"
     	      "\t 4. 商品信息录入\n"
     	      "\t 5. 推出系统并保存\n"
     	      "\t 6. 显示所有商品信息"
     	      "\n"
     	      "\n-----------------------------------------------------------\n");

	    scanf("%d", &order_number);

	    switch (order_number) {
		    case 1:
		      edit(AGo);
 		   break;
  		  case 2:
   		  delete_D(AGo);
    		  break;
    		case 3:
   			inquiry(AGo);
     		     break;
    		case 4:
     		 enter(AGo);
		      break;
		case 6:
			for ( int i = 0 ; i < e;i++)
					printf("\nGoods' info of %s :\n"
			 		      "\tid: %s\n"
			   		    "\tname: %s\n"
			  		     "\tprice: %sf\n"
			    		   "\tdiscount: %s\n"
			     		  "\tamount: %d\n"
			     		  "\tremain: %d\n",
			       AGo[i].name,
			       AGo[i].id,
			       AGo[i].name,
			       AGo[i].price,
			       AGo[i].discount,
			       AGo[i].amount,
			       AGo[i].remain);
			break;
 		   default:
  			printf("无效操作\n\n");
   		   break;
    }
  }

  return 0;
}

	
	
void delete_D(Goods g[]){
	printf("\nThere are the Goods:\n");	
	for (int i = 0; i <e;i++)
		printf("Id\t%s\tname\t%s\n",g[i].id,g[i].name);
	printf("\nEnter Goods' id to delete a Goods: ");
	char did[30];
	bool isDeleteStart =false;
	scanf("%s",did);
	for (int i = 0; i < e;i++){
		if (!strcmp(g[i].id,did))
			isDeleteStart = true;
		if (isDeleteStart)
			g[i] = g[i+1];
		if (isDeleteStart && i  == e - 1){
			e--;
		}
	}
	
	for (int i = 0; i <e;i++)
		printf("Id\t%s\tname\t%s\n",g[i].id,g[i].name);
		
	printf( "There are the Goods now: \n");
	if (isDeleteStart)
		printf("Delete successfully.\n");
	else 
		printf("Delete  unsuccessfully.\n");
	
}
void edit(Goods g[]){
		printf("\nThere are the Goods:\n");	
	for (int i = 0; i <e;i++)
		printf("Id\t%s\tname\t%s\n",g[i].id,g[i].name);

	printf("\n"
	       "Enter the Goods' id to edit it: ");
	char id[30];
	scanf("%s",id);
	
	Goods* tg = (Goods*)malloc(sizeof(Goods));
			
	for (int i = 0; i < e; i++)
		if (!strcmp(g[i].id,id)){
			*tg = g[i];
			printf("id: %s to : ",tg->id);
			scanf("%s",tg->id);
			for (int j = 0 ; j < e; j++){
			}
			printf("name: %s to : ",tg->name);
			scanf("%s",tg->name);
			printf("price: %s to : ",tg->price);
			scanf("%s",tg->price);
			printf("discount: %s to : ",tg->discount);
			scanf("%s",tg->discount);
			printf("amount: %d to : ",tg->amount);
			scanf("%d",&tg->amount);
			printf("remain: %d to : ",tg->remain);
			scanf("%d",&tg->remain);
			g[i] = *tg;
			break;
		}
	
}
			
			


void enter(Goods g[]) {

    printf("Enter goods' id: ");
    scanf("%s",&g[e].id);
    printf("Enter goods' name: ");
    scanf("%s", g[e].name);
    printf("Enter goods' price($): ");
    scanf("%s", &g[e].price);
    printf("Enter goods' discount: ");
	scanf("%s",&g[e].discount);
	printf("Enter goods amount: ");
	scanf("%d",&g[e].amount);  
	printf("Enter goods remain: ");
	scanf("%d",&g[e].remain);                
  e++;
}
	
void goods_info_ini(){
	FILE* fp;
	fp = fopen(FILE_NAME,"r");

	Goods* g = (Goods*)malloc(sizeof(Goods));

	//g = AGo;
	if( fp == NULL){
		printf("Can't open %s",FILE_NAME);
		exit(0);	
	}
	char s[100];
	int i;
	printf("Had open %s\n", FILE_NAME);
	
	while(1){
		fscanf(fp, "id:%s\n",s);
		strcpy(g->id,s);
		
		if ( !strcmp(s,"end") )break;
		printf("  id:%s\n",g->id);
		
		fscanf(fp, "name:%s\n",s);
		strcpy(g->name,s);
		printf("  name:%s\n",g->name);
		
		fscanf(fp, "price:%s\n",s);
		strcpy(g->price,s);
		printf("\tprice:%s\n",g->price);
		
		fscanf(fp, "discount:%s\n",s);
		strcpy(g->discount,s);
		printf("\tdiscount:%s\n",g->discount);
		
		fscanf(fp, "amount:%d\n",&i);
		g->amount = i;
		printf("\tamount:%d\n",g->amount);
		fscanf(fp, "remain:%d\n",&i);
		g->remain = i;
		printf("\tremain:%d\n",g->remain);
		AGo[e++] = *g;
	} 	
	
	fclose(fp); 	
}



void inquiry(Goods g[]){
	
	char name[20];
	char  id[30];
	int choice;
	
	printf("You can inquiry goods' data by \n"
	       "1 id\n"
	       "2 name\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("Please enter the id: ");
			
			scanf("%s",id);
	
			for( int i = 0 ; i < MAX;i++){
				if (!strcmp(g[i].id,id)){
					printf("Goods' info of %d :\n"
			 		      "\tid: %s\n"
			   		    "\tname: %s\n"
			  		     "\tprice: %s\n"
			    		   "\tdiscount: %s\n"
			     		  "\tamount: %d\n"
			     		  "\tremain: %d\n",
			       g[i].id,
			       g[i].id,
			       g[i].name,
			       g[i].price,
			       g[i].discount,
			       g[i].amount,
			       g[i].remain);
			       return;
				}
			}
			printf("无效查询\n\n");
			break;
		case 2:
			printf("Please enter the name: ");
			
			scanf("%s",name);
	
			for( int i = 0 ; i < MAX;i++){
				if (!strcmp( g[i].name,name)){
					printf("Goods' info of %s :\n"
			 		      "\tid: %s\n"
			   		    "\tname: %s\n"
			  		     "\tprice: %s\n"
			    		   "\tdiscount: %s\n"
			     		  "\tamount: %d\n"
			     		  "\tremain: %d\n",
			       g[i].name,
			       g[i].id,
			       g[i].name,
			       g[i].price,
			       g[i].discount,
			       g[i].amount,
			       g[i].remain);
				 return;
				}
			}
		default:
			printf("无效查询\n\n");
			break;
	}
	
}