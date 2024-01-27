#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void exchange(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;
    do
    {
        do
        {
           i++;
        } while (A[i] < pivot);
        do
        {
           j--;
        } while (A[j] > pivot);
        if (i < j) {
            exchange(&A[i], &A[j]);
        }
    } while (i<j);
    exchange(&A[low], &A[j]);
    return j;
}

void quicksort(int A[], int low, int high){
    int j;
    if(low < high){
        j = partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
}
void randomqs(int A[],int low,int high){
    int i=low;
    int j=high+1;
    int r=((rand())%(high-low+1))+low;
    exchange(&A[i],&A[r]);
    quicksort(A,low,high);
}