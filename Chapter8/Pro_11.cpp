#include <stdio.h>

int main(void) {
  char ePN[16];
 
  printf("Enter phone number: ");
  for (int i = 0; i < 15; i++) {
    scanf("%c", &ePN[i]);
    switch (ePN[i]) {
    case 'A':
    case 'B':
    case 'C':
      ePN[i] = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      ePN[i] = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      ePN[i] = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      ePN[i] = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      ePN[i] = '6';
      break;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
      ePN[i] = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      ePN[i] = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      ePN[i] = '9';
      break;
    case '\n':
      ePN[15] = i;
      i = 15;
      break;
    }

  }

  printf("In numeric form: ");
  for (int i = 0; i < ePN[15] + 1 ; i++) {
    printf("%c", ePN[i]);
  }
  return 0;
}