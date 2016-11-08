// This program prints a table of squares.
// And it is a text about int, long int and short int.

#include <stdio.h>

int main(void) {
  int n;
  
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in tables: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {

    printf("%10d%10d\n", i, i * i);
    if (i % 24 == 0) {
      printf("Press Enter to continue...   " );

	if ( i == 24 )
	 getchar();
      while (getchar() != '\n');
    }
  }
  // 用if语句判断是否是第24次循环，
  // use the second for to stop the first for .\
  // use while and getchar() to judge if the uesr enter a Enter.
  // use s++ to break from the second of, use break to break from the while.


  // The main part of this program 

  return 0;
  // return

}