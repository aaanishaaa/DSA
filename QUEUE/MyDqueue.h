#include<stdio.h>
#define N 5
int deque[N];
int f=-1,r=-1;
/***********************************************/
void EnqueueFront(int x) {
  if ((f == r + 1) || (f== 0 && r == N - 1)) {
    printf("Deque Overflow !\n");
  } else if (r ==-1 && f==-1) {
    r = 0;
    f = 0;
    deque[f]=x;
  } else if (f == 0) {
    f = N-1;
    deque[f] = x;
  } else {
    f--;
    deque[f] = x;
  }
}
/***********************************************/
void EnqueueRear(int x) {
  if ((f == r + 1) || (f== 0 && r == N - 1)) {
    printf("Deque Overflow !\n");
  } else if (r ==-1 && f==-1) {
    r = 0;
    f = 0;
    deque[r]=x;
  } else if (r == N-1) {
    r = 0;
    deque[r] = x;
  } else {
    r++;
    deque[r] = x;
  }
}
/***********************************************/
void display() {
  int i = f;
  while (i != r) {
    printf("%d ", deque[i]);
    i=(i+1)%N;
  }
  printf("%d",deque[r]);
}
/***********************************************/
void GetFront() {
    if(f==-1){
        printf("Deque Underflow !\n");
    }
    printf("Front is : %d\n", deque[f]);
}
/***********************************************/
void GetRear() {
    if(r==-1){
        printf("Deque Underflow !\n");
    }
    printf("Rear is : %d\n", deque[r]);
}
/***********************************************/
void DequeueFront() {
  if (f == -1 && r==-1) {
    printf("Deque Underflow !\n");
  } else if (f == r) {
    r = -1;
    f = -1;
  } else if (f==N-1){
    printf("Dequed value is : %d\n",deque[f]);
    f=0;
  } else{
    printf("Dequed value is : %d\n",deque[f]);
    f++;
  }
}
/***********************************************/
void DequeueRear() {
  if (f == -1 && r==-1) {
    printf("Deque Underflow !\n");
  } else if (f == r) {
    r = -1;
    f = -1;
  } else if (r==0){
    printf("Dequed value is : %d\n",deque[r]);
    r=N-1;
  } else{
    printf("Dequed value is : %d\n",deque[r]);
    r--;
  }
}
/**********************************/