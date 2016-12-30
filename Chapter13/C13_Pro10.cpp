#include <stdio.h>
#include <string.h>

/*
C13 Pro 11
修改第七章编程题11:
根据用户输入的英文名和姓氏显示姓氏，其后跟一个逗号，然后显示名的首字母
最后加一个点。
使其包含函数
void reberse_name(char* name);
在参数name 指向的字符串中，名在前姓在后，在修改后的字符串中，姓在前，其后跟一个逗号和一个空格，然后是名的首字母，最后加一个点。原始字符串中，名在前面，名和姓之间，姓的后面都可以有额外的空格
*/

void reverse_name(char *name);

int main(void){
	char s[40];
	char ss[20];
	printf("Enter a first and last name: ");
	scanf("%s",ss);
	strcpy(s,ss);
	strcat(s," ");
	scanf("%s",ss);
	strcat(s,ss);
	
	reverse_name(s);
	
	printf("%s",s);
	
	return 0;
}

void reverse_name(char *name){
	char *p = name;
	char a = *name;
	while ( *(name++) != ' ');
	
	while ( (*p++ = *name++) != '\0');

	p--;
	strcat(p,", ");
	while (*p++ != '\0');
	*--p = a;
	*++p = '\0';
	strcat(p,".");
}

