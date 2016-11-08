#include <stdio.h>

int main(void) {
  float f = 0, a = 0;
  char s;

  printf("Enter a expression: ");

  for (int i = 0; i < 2;) {
   	if ( i == 0){
     scanf("%f", &f);
     i++;
   	}
	scanf("%c", &s);
	if ( s == '\n'){
	//	i++;
		break;
	}
	scanf("%f", &a);
     

  switch (s) {
      case '+':
        f = f + a;
       // printf("f + a = %f\n", f);
        break;
      case '-':
        f = f - a;
      //  printf("f - a = %f\n", f);
        break;
      case '/':
        f = f / a;
       // printf("f / a = %f\n", f);
        break;
      case '*':
        f = f * a;
      //  printf("f * a = %f\n", f);
        break;
  }

  }
  printf("Value of expression: %.2f", f);

  return 0;
  }