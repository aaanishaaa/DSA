#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int>V[5];
    // V.push_back(4);
    // V.push_back(5);
    // V.push_back(3);
    // V.push_back(3);
    // V.push_back(6);
    // V.push_back(6);
    // V.push_back(7);
    // // for(int i=0;i<V.size();i++){
    // //     cout<<V[i]<<"\t";
    // // }
    // sort(V.begin()+2,V.end());
    // for(auto i:V){
    //     cout<<i<<"\t";
    // }
    // // cout<<V.size()<<"\n";
    V[0].push_back(10);
    V[0].push_back(24);
    V[0].push_back(321);
    V[0].push_back(42);
    V[1].push_back(541);
    V[1].push_back(62);
    V[1].push_back(7);
    V[2].push_back(842);
    V[2].push_back(90);
    V[2].push_back(110);
    V[2].push_back(141);
    V[2].push_back(121);
    V[3].push_back(13);
    V[3].push_back(145);
    V[4].push_back(15);
    V[4].push_back(165);
    V[4].push_back(172);
    V[4].push_back(181);
    V[4].push_back(195);
    V[4].push_back(206);
    for(int i=0;i<5;i++){
        sort(V[i].begin(),V[i].end());
        for(auto j:V[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}