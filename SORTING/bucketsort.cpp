#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
void bucketsort(double A[],int N){
    vector<double>bucket[10];
    for(int i=0;i<N;i++){
        int x=A[i]*10;
        bucket[x].push_back(A[i]);
    }
     for(int i=0;i<10;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
     for(int i=0;i<10;i++){
        for(auto j:bucket[i]){
            cout<<j<<endl;
        }
    }
}
int main(){
    double A[]={0.32,0.67,0.73,0.11,0.46,0.56,0.72,0.12,0.09,0.81};
    bucketsort(A,10);
    return 0;
}