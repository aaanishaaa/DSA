#include<stdio.h>
void AddElement(int A[],int n, int ele,int pos){
    for(int i=0;i>pos;i--){
        A[i]=A[i-1];
    }
    A[pos]=ele;
}
void DeleteElement(int A[],int n, int ele){
    int i;
   for(i=0;i<n;i++)
    {
       if (A[i]==ele)
       break;
    }
   for(i; i<n-1; i++)
    {
      A[i]=A[i+1];
    }
}
void traverse(int A[],int n){
    int i;
    printf("Array :");
    for(i=0;i<n;i++)
        {
        printf("%d ",A[i]);
        }
}
int main()
{
    int A[20];
    int n,ele,pos;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d%d",&ele,&pos);
    DeleteElement(A,n,ele);
    AddElement(A,n,ele,pos);
    traverse(A,n+1);
    return  0;
}
