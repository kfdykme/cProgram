/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"
#include "readline.c"
#include <string.h>


#define NAME_LEN 25

#define MAX_PARTS 100

struct part {
	
	int number;
	
	char name[NAME_LEN + 1];
	
	int on_hand;
	
} inventory[MAX_PARTS];


int num_parts = 0;

int find_part(int number);

void insert(void);

void search(void);

void update(void);

void print(void);

/*************************************************
main: Prompts the user to enter an operation code,

			then calls a function to perform the requested
			
			action. Repeats until the user enters the 
			
			command 'q'. Prints an error message if the user
			
			enters an illegal code.
*************************************************/


int main(void){
	
	char code;
	
	for(;;){
		
		printf("Enter operation code: ");
		
		scanf(" %c", &code);
		
		while (getchar() != '\n');
		
		
		switch (code){
			case 'i':
			
				insert();
				
				break;
				
			case 's':
				search();
				break;
				
			case 'u':
				update();
				break;
			case 'p':
				print();
				
				break;
				
			case 'q':
			
				return 0;
			default :
			
				printf("Illegal code\n");
				
		}
		
		printf("\n");
		
	}
	
}
	
int find_part(int number){
	
	int i;
	
	for ( i = 0; i < num_parts; i++)
		if ( inventory[i].number == number)
			return i;
			
	return -1;
	
}


void insert(void){
	
	int part_number;
	
	
	if ( num_parts == MAX_PARTS){
		printf("Database is full; can't addmpre parts.\n");
		
	}
	
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	int current_i = 0;
	
	for (; current_i < num_parts; current_i++){
		if ( inventory[current_i].number >=	part_number)
		break;
	}
			
	for (int j = num_parts; j >= current_i ; j--){
		
		inventory[j+1] = inventory[j];
		
	}
		  
	
	if (find_part(part_number) >= 0){
		printf("Part already exists.\n");
		return ;
	}
	
	inventory[current_i].number = part_number;
	
	printf("Enter part name: ");
	read_line(inventory[current_i].name,NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[current_i].on_hand);
	num_parts++;
	
	printf("current_i = %d num_parts = %d\n",current_i, num_parts);		
	
}

void search(void){
	int i, number;
	
	
	printf("Enter part number: ");
	
	scanf("%d", &number );
	
	i = find_part(number);
	
	if ( i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	} else 
		printf("Part not found.\n");
		
}

void update (void){
	int i, number , change;
	
	printf("Enter part number : ");
	scanf("%d", &number);
	i = find_part (number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else 
		printf("Part not found.\n");
}


void print(void){
	int i;
	printf("Part Number  Part Name\n"
				"Quanty on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("inventory[%d] :%7d     %-25s%11d\n",i,  inventory[i].number,
			inventory[i].name, inventory[i].on_hand);
}
	
	
		