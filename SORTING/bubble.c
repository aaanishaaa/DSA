#include<stdio.h>
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
int main(){
    int arr[100];
    int n;
    printf("Enter the no. elements");
    scanf("%d",&n);
    printf("Enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is");
    for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
    bubble(arr,5);
    printf("\n The Sorted array is");
    for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
    return 0;
}