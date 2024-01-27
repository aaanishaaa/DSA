#include <stdio.h>  
#include<math.h>
#define size 10

int array[size];  

void hash()
{     
    int i;  
    for(i = 0; i < size; i++)  
        array[i] = 0;  
}  
  
void insert(int x)  
{     
    int add = x % size;  
      
    if(array[add] == 0)  
    {     
        array[add] = x;  
        printf("%d inserted at array[%d]\n", x,add);  
    }  
    else  
    {       
        printf("INVALID");  
    }  
}  
int nearest_prime(int ts){
    int i=0,j=0;
    int flag=0;
    for(i=ts ; i>=2 ; i--){
        for(j=2;j<pow(i,0.5);j++){
            if(i%j==0)
            break;
        }
        if(j>pow(i,0.5)){
            return i;
        }
    }
    if(flag==1) {
        return 0;
    }
    else
    return 1;
}
int DivisionHash(int key,int ts){
    int np=0;
    int l=0;
    np=nearest_prime(ts);
    l=key%np;
    return 1;
}
void delete(int x)  
{  
    int add = x % size;  
    if(array[add] == x)  
        array[add] = 0;  
    else  
        printf("INVALID");  
}  
  
void search(int val)  
{  
    int key = val % size;  
    if(array[key] == val)  
        printf("Search Found\n");  
    else  
        printf("Search Not Found\n");  
}  
  
void traverse()  
{  
    int i;  
    for(i = 0; i < size; i++)  
        printf("[%d] = %d\n",i,array[i]);  
}  
  
int main()  
{  
    hash();  
    insert(2);   
    insert(4);    
    insert(6);  
    insert(8);  
    insert(10);
    printf("\n");  
    traverse(); 
    printf("\n");
    delete(10);  
    printf("\n");
    traverse();
    printf("\n");    
    int x=DivisionHash(1234,size);  
    printf(x);
    return 0;  
}  