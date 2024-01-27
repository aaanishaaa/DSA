#include<stdio.h>
void merge(int A[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int C[high+1];
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){
            C[k]=A[i];
            k=k+1;
            i=i+1;
        }
        else{
            C[k]=A[j];
            k=k+1;
            j=j+1;
        }
    }
    while(i<=mid){
            C[k]=A[i];
            k=k+1;
            i=i+1;
    }
    while(j<=high){
            C[k]=A[j];
            k=k+1;
            j=j+1;
    }
    for(i=low;i<=high;i++){
        A[i]=C[i];
    }
}
void mergesort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main(){
    int A[]={1,4,2,8,5,3,6};
    mergesort(A,0,6);
    for(int i=0;i<7;i++){
        printf("%d ",A[i]);
    }
}