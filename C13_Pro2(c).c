#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void){
	
	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_str[9], msg_str[MSG_LEN+1];
	int mouth, day, i, j, num_remind = 0;
	
	for (;;){
		if (num_remind == MAX_REMIND){
			printf("--No space left --\n");
			break;
		}
		
	printf("Enter day and reminder: ");
	scanf("%2d", &mouth);
	if (mouth == 0)
		break;
		
	scanf("/%2d",&day);
	if (day == 0)
		break;
/* 要注意 day_str 的长度*/
	sprintf(day_str,"%2d/%2d",mouth, day);
	
	read_line(msg_str,MSG_LEN);
	
	if ( day > 31 
	|| day < 0
	|| mouth > 12 
	|| mouth < 0){
		strcpy(reminders[num_remind++],"____Eor.");
		continue;
	}
	
	for ( i = 0 ; i < num_remind ; i++)
		if (strcmp(day_str, reminders[i]) < 0)
			break;
	
	
	
	for (j = num_remind; j > i; j--)
		strcpy(reminders[j], reminders[j-1]);
		
	
	
	strcpy(reminders[i], day_str);
	strcat(reminders[i], msg_str);
	
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