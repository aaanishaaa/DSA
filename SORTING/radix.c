#include<stdio.h>
#include<stdlib.h>
int* countingsort(int A[],int size,int largest){
    int *c=(int*)calloc(sizeof(int*),largest+1);
    int *ans=(int*)calloc(sizeof(int*),size);
    for(int i=0;i<=size-1;i++){
        c[A[i]]++;
    }
    for(int i=1;i<=largest;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int i=size-1;i>=0;i--){
        ans[c[A[i]]-1]=A[i];
        c[A[i]]--;
    }
return ans;
}
