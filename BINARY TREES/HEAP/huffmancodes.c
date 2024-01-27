#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_HT 100
struct minheapnode{
    char data;
    int freq;
    struct minheapnode *left,*right;
};
struct minheap{
    int size;
    int capacity;
    struct minheapnode **array;
};
struct minheapnode* newnode(char data,int freq){
    struct minheapnode* temp=malloc(sizeof(struct minheapnode));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;

    return temp;
}
struct minheap *createminheap(int capacity){
    struct minheap* minheap=malloc(sizeof(struct minheap));
    minheap->size=0;
    minheap->capacity=capacity;
    minheap->array=(struct minheapnode**)malloc(minheap->capacity * sizeof(struct minheapnode*)); 
    return minheap;
}
void swap(struct minheapnode **a,struct minheapnode **b){
    struct minheapnode* t=*a;
    *a=*b;
    *b=t;
}
void minheapify(int *a,int i,int n){
    int l,r,m;
    while(2*i+1<=n){
        l=2*i+1;
        r=l+1;
        m=l;
        if(r<=n){
            if(a[r]<a[l]){
               m=r; 
            }
        }
        if(a[i]>a[m]){
            swap(&a[i],&a[m]);
        }
        else{
            break;
        }
        i=m;
        
    }
}
