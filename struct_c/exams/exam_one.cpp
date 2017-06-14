#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[10];
  int age;
} stuInfo;

typedef struct node{
  stuInfo data;
  struct node* next;
} Node;

typedef struct {
  Node *head;
  int len;
} List;

void initList(List &L);
void insertList(List &L,stuInfo e);
void printList(List L);
void deleteList(List &L,stuInfo e);
void sortList(List &L);
Node* searchList(List &L, stuInfo e);
void swapNode(Node *n,Node *n2);
int sortPass(List &L);
List compainList(List &L1, List &L2);


List compainList(List &L1, List &L2){

  List l;

  initList(l);

  Node *p1,*p2;

  p1 = L1.head->next;

  p2 = L2.head->next;


  while(p1 && p2 ){
    if(p1->data.age <= p2->data.age)
    {
      insertList(l,p2->data);
      p2 = p2->next;
    } else if(p1->data.age > p2->data.age){
      insertList(l,p1->data);
      p1 = p1->next;
    }

  }
  if(p1 == NULL){
    printf("21\n" );
    while (p2) {
      insertList(l,p2->data);
      p2 = p2->next;
    }
  } else  {
    while (p1) {
      insertList(l,p1->data);
      p1 = p1->next;
    }
  }

  return l;

}

int sortPass(List &L){
  //printf("Pass\n");
  Node *p;
  p = L.head->next;

  int isPassed = 0;

  while(p->next){
    if(p->data.age < p->next->data.age )
    {
       //swapNode(p,p->next);
       stuInfo t;
       Node *n, *n2;
       n = p;
       n2 = p->next;

       strcpy(t.name,n->data.name);
       t.age = n->data.age;

       strcpy(n->data.name,n2->data.name);
       n->data.age = n2->data.age;

       strcpy(n2->data.name,t.name);
       n2->data.age = t.age;
       isPassed = 1;
    }
    p = p->next;
  }

  return isPassed;

}


Node* searchList(List &L, stuInfo e){
  Node *p,*hp;

  p = L.head->next;
  hp = L.head;
  while(p){
    if(!strcmp(p->data.name,e.name)
      && e.age == p->data.age)
      break;
    p = p->next;
    hp = hp->next;
  }

  return hp;
}

void initList(List &L){
  L.head = (Node*)malloc(sizeof(Node));
  L.len = 0;
  L.head->next = NULL;
}

void insertList(List &L, stuInfo e){
  Node * p,*t;

  p = (Node*) malloc(sizeof(Node));
  t = L.head;
  while(t->next)t=t->next;

  p->data = e;
  p->next = t->next;
  t->next = p;
  L.len++;
}

void printList(List L){
  printf("PrintList\n");
  Node *p;

  p = L.head->next;
  while(p){
    printf("%s %d\n",p->data.name, p->data.age);
    p = p->next;
  }
}

void deleteList(List &L, stuInfo e){
  // find a node which has a data equal e
  Node *hp,*p;


  hp = searchList(L,e);
  p = hp->next;

  if(p == NULL)
  {
    printf("Can't find this element in this List\n");
    return;
  }

  hp->next = p->next;
  free(p);

}

void sortList(List &L){

  while (sortPass(L));
}

int main(void){
  List L;
  initList(L);
  //printf("%d %d\n",sizeof(L.head),L.len);

  printf("Init\n");
  for (size_t i = 0; i < 3; i++) {
    stuInfo s;
    strcpy(s.name,"Test Info ");
    char s2[2];
    s2[0] = 'A'+i;
    s2[1] = '\0';
    strcat(s.name,s2);
    s.age = i;

    insertList(L,s);
  }

  //deleteList(L,);
  printList(L);
  printf("\n\nInsert\n");
  stuInfo s;
  strcpy(s.name,"Chen");
  s.age = 20;
  insertList(L,s);

  printList(L);

  printf("\n\nDelete\n");
  stuInfo s2;
  strcpy(s2.name,"Test Info B");
  s2.age = 1;
  deleteList(L,s2);
  printList(L);

  printf("\n\nSort\n");
  List L2;
  initList(L2);

  for (size_t i = 7; i < 10; i++) {
    stuInfo s;

    int age = rand()%10+10;
    strcpy(s.name,"Name ");
    char s2[2];
    s2[0] = 'A'+i;
    s2[1] = '\0';
    strcat(s.name,s2);
    s.age = age;

    insertList(L2,s);
  }
  printList(L2);


  sortList(L2);

  sortList(L);

  List l;
  l = compainList(L,L2);
  printList(l);


}
