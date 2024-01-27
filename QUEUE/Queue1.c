#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 10
struct Queue
{
    char item[SIZE];
    int REAR;
    int FRONT;
}; struct Queue Q;

void initializeQ(){
    Q.REAR=-1;
    Q.FRONT=0;
}

int IsEmpty(){
    if(Q.REAR-Q.FRONT+1==0)
        return 1;
    else
        return 0;
}

void EnQueue(char x){
    if(Q.REAR==SIZE-1)
    {
        printf("\n Queue Overflow");
        // return 1;
    }
    else{
        Q.REAR++;
        Q.item[Q.REAR]=x;
    }
}

char DeQueue(){
    char x;
    if(IsEmpty()){
        printf("\n Queue Underflow");
        exit(1);
    }
    else{
    x=Q.item[Q.FRONT];
    Q.FRONT++;
    return x;
    }
}
int main(){
  initializeQ();
  EnQueue('A');
  EnQueue('B');
  EnQueue('C');
  char a=DeQueue();
  printf("Deleted Item is => %c",a);

}

