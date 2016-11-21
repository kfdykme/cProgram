#include <stdio.h>

#define ROW 5
#define COLUMN 5

int main(void){
	int row ;
	int numberArray[ROW][COLUMN];
	int rowTotals[ROW] = {0};
	int columnTotals[COLUMN] = {0};
	
	for(row = 0;row < ROW;row++){
		printf("Enter row %d: ",row+1);
		for (int i = 0;i < COLUMN;i++){
			scanf("%d",
			&numberArray[row][i]);
			rowTotals[row  ] += 
			numberArray[row][i];
		}
	}
	for (int x = 0; x< COLUMN;x++){
		for (int y = 0; y< ROW;y++){
			columnTotals[x] +=
			 numberArray[y][x];	
		}
	}
	
	printf("\nRow totals: ");
	for (int i = 0;i < ROW;i++){
		printf("%d ",rowTotals[i]);
	}
	printf("\nColumn totals: ");
	for (int i = 0;i < COLUMN;i++){
		printf("%d ",columnTotals[i]);
	}
	
	return 0;
}