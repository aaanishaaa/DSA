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

int main(){
    int A[] = {1, 4, 7, 2,11,15,5,9,17};
    A[10]=__INT_MAX__;
    quicksort(A,0,10);
    printf("\n The Sorted array is");
    for(int i=0;i<9;i++){
    printf(" %d\t ",A[i]);
    }
    return 0;
}