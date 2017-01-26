#include <stdio.h>

#define FRENCH

int main(void){
	
	#if defined ENGLISH
		printf("Insetr Disk 1");
	#elif defined FRENCH
		printf("Inserez Le Disque 1");
	#elif defined SPANISH
		printf("Inserte El Disco 1");
	#endif
	
	return 0;
	} 
	