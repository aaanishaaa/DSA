#include<stdio.h>
void main(){
    int a[10]={1,2,3,4,5,6,7,8,9};
    int i=7;
    printf("%d ",&a[i]);
    int x=i-0;
    printf("%d",a+x);

int b[5][4];
    i=4;
    int j=3;
    x=(i-0)*(3-0+1)+(j-0);

    printf("\n%u\n",&b[i][j]);
    printf("%d\n",b[0]+x);
    return 0;


    // *****************3-D array****************************

    int c[10][20][30];

    i=4;
    j=8;
    int k=6;
    x=(i-0)*(19-0+1)*(29-0+1)+(j-0)*(29-0+1)+(k-0);

    printf("\n%u\n",&c[i][j][k]);
    printf("%d\n",c[0][0]+x);
}
