#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 256

char String[MAXSIZE];

struct Node
{
	char *str;
	int length;
};

typedef struct Node string;

void SeqStringCreat(string *S, char* s)
{
	S = (string*)malloc(sizeof(string));
	char *a = s;
	int i;
	for(i = 0; *(a + i) != '\0'; i++);
	
	S->length = i;
	S->str = s; 
}

void SeqStringAssign(string *S, string *T)
{
	if(S->str)
		free(S->str);
	S->length = T->length;
	if(S->length == 0)
	{
		S->str = (char *) malloc (sizeof(char));
		if(!S->str)
		{
			printf("malloc faile.");
			exit(0);
		}
		S->str='\0';
	}
	else
	{
		S->str = (char*)malloc((S->length +1) * sizeof(char));
		if(!S->str)
		{
			printf("mallo fail.");
			exit(0);
		}
		int i;
		for( i = 0; i < S->length; i++)
			S->str[i] = T->str[i];
		S->str[i] = '\0';	
	}
}

 void SeqStringContact(string *S, string *T)
 {
 	string temp;
 	SeqStringAssign(&temp,S);
		
	S->length = S->length + T->length;
	free(S->str);
	S->str = (char*)malloc((S->length+1)*sizeof(char));
	if(!S->str)
	{
		printf("!malloc");
		exit(0);
	}
	else
	{
		int i;
		for(i = 0; i < temp.length; i++)
			S->str[i] = temp.str[i];
		for(i = 0; i <T->length; i++)
			S->str[temp.length + i] = T->str[i];
		free(temp.str);
	}
 }
 
 void SubSeqString(string *S, string *Sub, int start, int len)
 {
 	if((0<=start && start<=S->length-1)
	&& (0 <= len&& len <= S->length+1))
	{
		Sub->str = (char*)malloc((len+1)*sizeof(char));
		if(!Sub->str)
		{
			printf("falie.");
			exit(0);
		}
		else
		{
			Sub->length =len;
			int i;
			for(i = 0; i < Sub->length; i++)
				Sub->str[i] = S->str[start+i];
		}
	}
	else
	{
		printf("start & len Error");
		exit(0);
	}
 }
 
 int SimpleMatching(string *S,string *p)
 {
 	int i = 0;
 	while(i<= (S->length-p->length);
 	{
 		int j = 0;
 		while(S->str[j] == P->str[i])
 		{
 			i++;
 			j++;
 		}
 		if(j == p->length)
 			return i-p->length;
 		i = i-j+1;
 	}
 	return -1;
 }
 
 int KMPMatching(string *S, string *p)
 {
 	int *next;
 	findnext(p,next);
 	int i, j;
 	i = 0;
 	j = 0;
 	while(i <= (S->length - p->length)
 	{
 		while(j == -1 
 		|| (j< p->length 
 			&& s->str[i] == p->str[j])
 		{
 			i++;
 			j++;
 		}
 		if(j == p->length)
 			return i-p->length;
 		j = next[j];
 	}
 	
 	return -1;
 	
 }
 
 void findnext(string *p, int *next)
 {
 	next[0] = -1;
 	int j = 0, k = -1;
 	while(j <p->length)
 	{
 		while (k==0
 		|| p->str[j] == p->str[k])
 		{
 			j++;
 			k++;
 			next[j]=k;
 		}
 		k =next[k];
 	}
 }
 
 
 		

int main(void)
{
	
	
	return 0;
}