#include<stdio.h>
void traverse(int A[],int n){
    int i;
    printf("Array :");
    for(i=0;i<n;i++)
        {
        printf("%d ",A[i]);
        }
}
void insertion(int A[],int ele,int pos, int n){
    if(pos<0 || pos>n){
        printf("Invalid");
    }
    else{
        for(int i=0;i>pos;i--){
            A[i]=A[i-1];
        }
        A[pos]=ele;
        n++;
    }
}
void deletion(int A[],int n,int i){
    int x;
    if(i>0 || i>=n){
        printf("Invalid");
    }
    else{
        for(int j=i+1;j<n;j++){
            A[j-1]=A[j];
        }
        n--;
        return x;
    }
}
int main(){
    int A[20],i,n;
    printf("enter no. of elements");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    traverse(A,n);
    insertion(A,4,2,100);
    printf("The New Array after Insertion: ");
    traverse(A, n);
    deletion(A,n,3);
    printf("The New Array after Deletion: ");
    traverse(A, n);
}