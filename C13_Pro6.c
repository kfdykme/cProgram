/* Checks planet names */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9


int strcmp_wou(char s1[],char s2[]){
	
	while (toupper(*(s1++)) == toupper(*(s2++)))
		if ( *s1 == '\0') 
			return 0;
	
	return *(s2-1) - *(s1-1);
}
		

int main(int argc, char *argv[]){
	
	char *planets[] = {"Mercury","Venus", "Earth",
	                   "Mars", "Jupiter", "Saturn",
	                   "Uranus", "Neptune", "Pluto"};
	int i, j;
	
	for (i = 1 ; i < argc; i++){
		for (j = 0 ; j < NUM_PLANETS; j++)
//			printf("%s %s",argv[i],planets[j]);
			if (!strcmp_wou(argv[i], planets[j])){
				printf("%s is planet %d\n",argv[i], j + 1);
				break;
			}
		if ( j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}
	
	return 0;
}

