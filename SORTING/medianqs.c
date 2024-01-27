#include<stdio.h>
#include<limits.h>
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
int medianqs(int A[],int low,int high){
    int i=low;
    int j=high+1;
    int mid=(low+high)/2;
    exchange(&A[i],&A[mid]);
    quicksort(A,low,high);
}

int main(){
    int A[] = {1, 3, 70, 5,61,17,83,91,10};
    A[10]=__INT_MAX__;
    medianqs(A,0,9);
    printf("\n The Sorted array is");
    for(int i=0;i<9;i++){
    printf(" %d\t ",A[i]);
    }
    return 0;
}