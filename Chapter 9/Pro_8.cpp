#include <stdio.h>

#define ROW 5
#define COLUMN 5

int main(void) {
  int row;
  int numberArray[ROW][COLUMN];
  int studentTotals[ROW] = { 0 };
  double studentAverage[ROW];
  double examAverage[COLUMN] = { 0 };
  int examMax[COLUMN] = { 0 };
  int examMin[COLUMN] = { 0 };
  for (row = 0; row < ROW; row++) {
    printf("Enter row %d: ", row + 1);
    for (int i = 0; i < COLUMN; i++) {
      scanf("%d", &numberArray[row][i]);
      
      studentTotals[row] += numberArray[row][i];
      studentAverage[row] = (double) studentTotals[row] / COLUMN;
    }
  }

  for (int x = 0; x < COLUMN; x++) {
    for (int y = 0; y < ROW; y++) {
      examAverage[x] = (y == ROW - 1) ? examAverage[x] + numberArray[y][x] :
        ( examAverage[x] + numberArray[y][x]) /  ROW;
      examMax[x] =
        examMax[x] > numberArray[y][x] ? examMax[x] : numberArray[y][x];
      examMin[x] = 
        y == 0 ? numberArray[y][x] : examMin[x];
      examMin[x] =
        examMin[x] <numberArray[y][x]  ? examMin[x] : numberArray[y][x];
    }
  }

  printf("\nStudent totals: ");
  for (int i = 0; i < ROW; i++) {
    printf("%d ", studentTotals[i]);
  }
  printf("\nStudent average: ");
  for (int i = 0; i < ROW; i++) {
    printf("%.2lf ", studentAverage[i]);
  }
  printf("\nExam average: ");
  for (int i = 0; i < COLUMN; i++) {
    printf("%.2lf ", examAverage[i]);
  }
  printf("\nExam Min: ");
  for (int i = 0; i < COLUMN; i++) {
    printf("%d ", examMin[i]);
  }
  printf("\nExam Max: ");
  for (int i = 0; i < COLUMN; i++) {
    printf("%d ", examMax[i]);
  }

  return 0;
}