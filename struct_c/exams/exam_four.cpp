#include<stdio.h>

typedef struct {
  int data[10000];
  int lenght;
} SQL;

void initSQl(SQL * S);

void quicksort(int *data, int left, int right);

void printSQL(SQL *S);

int getPivot(int *data, int left, int right);

void sort(int *data, int left, int right);

int sortpass(int *data, int left, int right);

int binser(int *data, int key, int left, int right);

int binser(int *data, int key, int left, int right){
  int mid = (left + right)/2;
  if (data[mid]  == key )
   return mid;
  if(left == mid)
  {
      printf("can't find");
      return -1;
  }
  //printf("left = %d right = %d mid = %d\n",left, right ,mid);
  if (data[mid] < key) {
  //  printf("%d<%d\n",data[mid],key);
    return binser(data,key, mid, right);
  } else if (data[mid] > key)
  {
    //printf(">\n");
    return binser(data,key, left, mid);
  }

}

void sort(int *data, int left, int right){
  while(sortpass(data,left, right));
}

int sortpass(int *data, int left , int right)
{

  for(int i = left ;i < right-1 ; i++)
  {
    if(data[i] > data[i+1])
    {
      int a = data[i];
      data[i]  = data[i+1];
      data[i+1] = a;
      return 1;
    }
  }
  return 0;
}

int getPivot(int *data, int left, int right){
  return data[left];
}


void initSQL(SQL *S)
{
  S->lenght = 0;

  printf("ENter SQL's lenght : ");
  scanf("%d",&S->lenght);
  for(int i = 0; i < S->lenght;i++)
  {
  //  printf("ENter %d number : ",i);
    scanf("%d",&S->data[i]);

  }
}

void printSQL(SQL *S)
{
  printf("Printf SQL:\n");
  for(int i =0; i < S->lenght; i++)
  {
    printf("%d\n",S->data[i]);
  }

}

void quicksort(int *data, int left, int right){
  //printf("a\n" );
  if(right - left  >= 3)
  {
    int pivot,i,j;
    pivot = getPivot(data,left, right);
    i = left;
    j = right-1;

    for(;;){
      while(i < j && pivot <= data[j])j--;
      if(i >= j) break;
      data[i++] = data[j];

      while(i < j && pivot >= data[i])i++;
      if(i >= j )break;
      data[j--] = data[i];
    }
    data[j] = pivot;

    int mid = j;
    //if(right - left <=1) return;
    quicksort(data,left,mid);
    quicksort(data,mid+1,right);
  } else
  {
  //  printf("jieshu\n");
    sort(data,left, right);

  }

}

int main(void){

  SQL S;
  initSQL(&S);

  quicksort(S.data,0,S.lenght);

  printSQL(&S);

  printf("search new:\nenter a number:\n");
  while (1) {
    int a;
    scanf("%d",&a);
    //printf("%d",a);
    printf("is in %d\n",binser(S.data,a,0,S.lenght));
  }
  return 0;

}