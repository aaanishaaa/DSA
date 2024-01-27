#include<stdio.h>
#include<stdlib.h>
void Insertion(int *a,int *N,int i,int x){
    for(int j=*N-1;j>=i;j--){
        a[j+1]=a[j];
    }
    a[i]=x;
    (*N)++;
}
int Deletion(int *a,int *N,int pos){
    int x=a[pos-1];
    for(int j=pos;j<=*N-1;j++){
        a[j-1]=a[j];
    }
    (*N)--;
    return x;
}
//! Ascending PQ
void PQinsertion(int *a,int *N,int x){
    int i=0;
    while(i<*N && x>=a[i]){
        i++;
    }
    Insertion(a,N,i,x);   
}
//! Ascending PQ
int PQdeletion(int *a, int *N) {
    if (*N > 0) {
        int x = a[0];
        Deletion(a, N, 1);
        return x;
    } else {
        printf("Priority Queue is empty.\n");
        return -1;
    }
}

int main() {
    int n, x, a[100];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number you want to insert: ");
    scanf("%d", &x);

    PQinsertion(a, &n, x);

    printf("Priority Queue after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

printf("Priority Queue elements after deletion: ");
while(n>0){
    int q = PQdeletion(a, &n);
    printf("%d ", q);
}
    return 0;
}

