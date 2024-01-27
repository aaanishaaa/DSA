#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void exchange(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void bubble(int A[],int N){
    int flag=1;
    for(int i=0;i<N-1;i++){
        flag=0;
        for(int j=0;j<N-i-1;j++){
            if(A[j+1]<A[j]){
                exchange(&A[j],&A[j+1]);
                flag=1;
            }
        }
    }
}
void insertion(int A[],int N){
    int i,j,k;
    for(i=1;i<N-1;i++)
    {
        k=A[i+1];
        j=i;
    while(j>=i && A[i>k]){
        A[j+1]=A[j];
        j=j-1;
    }
    A[j+1]=k;
    }
}
void selection(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        exchange(&A[i], &A[min]);
    }
}
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); //seed a random number,time(NULL) returns the current time in seconds 
    for (int i = 0; i < size; i++) { //size tak, we are accepting the array
        arr[i] = rand() % 1000 + 1; 
    }
}
double measureTime(void (*sortFunc)(int[], int), int arr[], int size) {
    clock_t start, end; //clock_t is a data type used to measure CPU time.
    double cpu_time_used;
    start = clock();
    sortFunc(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
int main() {
    int rounds = 20;
    int arraySizes[] = {100, 500, 1000, 5000};
    for (int i = 0; i < sizeof(arraySizes) / sizeof(arraySizes[0]); i++) {
        printf("Array size: %d\n", arraySizes[i]);
        for (int j = 0; j < rounds; j++) {
            int arr[arraySizes[i]];
            generateRandomArray(arr, arraySizes[i]);
            int arrCopy[arraySizes[i]];
            for (int k = 0; k < arraySizes[i]; k++) {
                arrCopy[k] = arr[k];
            }
            double bubbleTime = measureTime(bubble, arrCopy, arraySizes[i]);
            for (int k = 0; k < arraySizes[i]; k++) {
                arrCopy[k] = arr[k];
            }
            double selectionTime = measureTime(selection, arrCopy, arraySizes[i]);    
            for (int k = 0; k < arraySizes[i]; k++) {
                arrCopy[k] = arr[k];
            }
            double insertionTime = measureTime(insertion, arrCopy, arraySizes[i]);

            printf("\nBubble Sort Time: %f s\n", bubbleTime);
            printf("Selection Sort Time: %f s\n", selectionTime);
            printf("Insertion Sort Time: %f s\n", insertionTime);
        }
    }
    return 0;
}