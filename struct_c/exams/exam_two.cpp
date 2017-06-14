#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 26
typedef struct node{
  char c;
  struct node *l, *r, *p;
  int w;
} Node;

typedef struct code{
  char c;
  char s[M];
} Code;

typedef Node Tree;

void initTree(Tree *t);
void createTree(Tree *t);
void select(Tree *t, int len,int &l,int &r);
void read(int *c);
void printTree(Tree *t);
void printCode(Tree *t);
int main(void){

  Tree t[2*M];
  initTree(t);
  createTree(t);
  printTree(t);
  printCode(t);
}

void printCode(Tree *t){
  int len = 0;
  for (int i = 0 ; i < M ; i++)if(t[i].l== NULL && t[i].r == NULL && t[i].w != 0)len++;
  Code code[len];
  char s[M+1];
  for(int i = 0 ; i; i++){
    if(t[i].w == 0) break;
    Node *N;
    N = &t[i];
    printf("%c\t",N->c );

    while(N){
      printf("%c",N->c);

      N = N->p;
    }
    printf("\n");
  }


  //for(int i = 0; i < len ; i++)  printf("%c %s\n",code[i].c,code[i].s);
}

void printTree(Tree *t){
  int len = 0;
  for (int i = 0 ; i < M ; i++)if(t[i].w!= 0)len++;
  printf("element len is %d\n",len);
  printf("c w l r p\n");
  for(int i =0 ; ; i++){
      if(t[i].w == 0) break;
    printf("%c %d %c %c %c\n",
      t[i].c, t[i].w,
      t[i].l ? t[i].l->c:'+'-1,
      t[i].r ? t[i].r->c:'+'-1,
      t[i].p ? t[i].p->c:'+'-1);

  }
}

void select(Tree *t, int len,int &l,int &r){
  int a,b,c,d;

  for(a = 0 ; a< len; a++){
    if(t[a].p == NULL)
    {
      l = a;
      break;
    }
  }

  for(b = 0; b < len ; b++){
    if(t[b].p == NULL && t[b].w < t[l].w){
      l = b;
      break;
    }
  }
  for(c = 0 ; c< len; c++){
    if(t[c].p == NULL && c != l)
    {
      r = c;
      break;
    }
  }

  for(d = 0; d < len ; d++){
    if(t[d].p == NULL && t[d].w < t[r].w && d != l){
      r = d;
      break;
    }
  }

}

void createTree(Tree *t){
  //
  int len = 0;
  for (int i = 0 ; i < M ; i++)if(t[i].w!= 0)len++;
  printf("element len is %d\n",len);

  int mLen = 2*len -1;
  //
  int l,r;
  for(int i =len ; i <= mLen;i++ ){
    select(t,i-1,l,r);
    t[i].l = &t[l];
    t[i].r = &t[r];
    t[l].p = &t[i];
    t[i].w = t[l].w + t[r].w;
    t[i].p = NULL;
    t[i].c = '+'+i;
  }

}

void read(int *cs){
  for(int i =0; i < M; i++)cs[i] = 0;

  //  for(int i =0 ; i < M ; i ++ )printf("%c %d\n",i+'a',cs[i]);
  char c;
  while((c = getchar()) != '\n'){
    int pos = c-'a';
    //printf("%c %d\n",c,pos);
    cs[pos]++;
  }

  //for(int i =0 ; i < M ; i ++ )printf("%c %d\n",i+'a',cs[i]);
}

void initTree(Tree *t){
  int cs[M];
  read(cs);
  int n = 0;
  int i;
  for( i =0 ; i < M ; i++)
  {
    t[i].w = 0;
    if(cs[i] != 0){

      t[n].c = 'a' +i;
      t[n].w = cs[i];

      t[n].l = NULL;
      t[n].r = NULL;
      t[n].p = NULL;
      n++;
    }
  }
  //printf("n = %d\n",n);

}
