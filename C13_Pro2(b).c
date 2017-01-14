#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void){
	
	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_str[3], msg_str[MSG_LEN+1];
	int day, i, j, num_remind = 0, hour, min;

	for (;;){
		if (num_remind == MAX_REMIND){
			printf("--No space left --\n");
			break;
		}
		
	printf("Enter day , 24-hour system time and reminder: \n");
	scanf("%2d",&day);
	
	if (day == 0)
		break;
	
	scanf(" %2d %2d",  &hour, &min);
		
	sprintf(day_str, "%2d %2d %2d",day,hour, min);
	
	read_line(msg_str,MSG_LEN);
	
	for ( i = 0 ; i < num_remind ; i++)
		if (strcmp(day_str, reminders[i]) < 0)
			break;	
	printf("i = %d\n",i);		
	
	strcpy(reminders[j], reminders[i]);
	
	printf("\nreminders[%d] = %s \nreminders[%d] = %s\n reminders[%d] = %s\n",i+1 , reminders[i+1], i, reminders[i], i-1, reminders[i-1]);
	
	strcpy(reminders[i], day_str);
	strcat(reminders[i], msg_str);
	
	if ( day > 31 || day < 0){
		strcpy(reminders[num_remind++],"____Eor.");
		continue;
	}
	
	num_remind++;
	
	}
	
	printf("\Day Reminder\n");
	for (i = 0 ; i < num_remind; i++)
		printf(" %s\n", reminders[i]);
		
	return 0;
	}
	
int read_line(char str[], int n){
	int ch, i = 0;
	
		while ((ch = getchar()) != '\n')
			if ( i < n)
				str[i++] = ch;
		str[i] = '\0';
		return i;
	}	