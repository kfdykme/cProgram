#include <stdio.h>

typedef struct {
	int hours, minutes, seconds;
} Time;

Time split_time(long total_seconds);

int main(void){
	Time t = split_time(39661);
	printf("%d:%d:%d\n",t.hours, t.minutes, t.seconds);
	return 0;
}

Time split_time(long total_seconds){
	Time t;
	t.hours = total_seconds / 3600;
	
	while (t.hours > 23)
		t.hours -= 24;
		
	total_seconds = total_seconds % 3600;
	
	t.minutes = total_seconds / 60;
	
	total_seconds = total_seconds % 60;
	
	t.seconds = total_seconds ;
	
	return t;
}