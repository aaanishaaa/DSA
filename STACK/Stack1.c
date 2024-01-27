/*#include<stdio.h>
struct Time {
int hour;
int minute;
int second;
};
int main()
{
    struct Time T1={5,24,46};
    struct Time T2={11,54,58};
    struct Time T3;
    int carry=0;
    int x,y,z;
    printf("%d::%d::%d",T1.hour,T1.minute,T1.second);
    printf("\n\n%d::%d::%d",T2.hour,T2.minute,T2.second);

    x=T1.second+T2.second;
    carry=x/60;
    x=x%60;

    y=T1.minute+T2.minute+carry;
    carry=y/60;
    y=y%60;

    z=T1.hour+T2.hour+carry;
    T3.second=x;
    T3.minute=y;
    T3.hour=z;
    printf("\n\n%d::%d::%d",T3.hour,T3.minute,T3.second);
}
Write a program to add two complex numbers using structure.
The values of the complex number is to be taken from the user
(a + ib) (c + id) = (ac - bd) + i(ad + bc).
#include<stdio.h>
struct complex{
int real;
int imagine;
};
int main(){
struct complex C1={7,8};
struct complex C2={4,3};
struct complex C3;
int x,y,a,b,c,d;
printf("%d+%di",C1.real,C1.imagine);
printf("\n%d+%di",C2.real,C2.imagine);
x=C1.real+C2.real;
y=C1.imagine+C2.imagine;

a=C1.real-C2.real;
b=C1.imagine-C2.imagine;

c=C1.real*C2.real-C1.imagine*C2.imagine;
d=C1.real*C2.imagine+C1.imagine*C2.real;

C3.real=x;
C3.imagine=y;
printf("\n%d+%di",C3.real,C3.imagine);

C3.real=a;
C3.imagine=b;
printf("\n%d+%di",C3.real,C3.imagine);

C3.real=c;
C3.imagine=d;
printf("\n%d+%di",C3.real,C3.imagine);

}
*/
#include<stdio.h>
struct Tower{
int feet;
int inches;
};
int main(){
struct Tower T1={11,9};
struct Tower T2={10,11};
struct Tower T3={9,9};
struct Tower T4;
int x,y,carry=0;
x=T1.feet+T2.feet+T3.feet;
y=T1.inches+T2.inches+T3.inches;
carry=y/12;
y=y%12;
T4.feet=x+carry;
T4.inches=y;
printf("\n%d'%d",T4.feet,T4.inches);
}
