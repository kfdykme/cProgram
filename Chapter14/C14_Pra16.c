#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void){
	//IDENT(foo)
	// ==  "identfoo"
	return 0;
}