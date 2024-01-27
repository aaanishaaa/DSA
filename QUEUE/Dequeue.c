#include<stdio.h>
#include"MyDqueue.h"
int main() {

  EnqueueFront(2);
  EnqueueFront(5);
  EnqueueRear(-1);
  EnqueueRear(0);
  EnqueueFront(7);
  DequeueFront();
  GetFront();
  GetRear();

  display();

  return 0;
}