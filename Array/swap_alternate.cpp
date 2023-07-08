#include<bits/stdc++.h>
using namespace std;

void swapAlternate(vector<int> &v){
    int i,n=v.size();
    for(i=0;i+1<n;i+=2){
        int t=v[i];
        v[i]=v[i+1];
        v[i+1]=t;
    }
}

int main(){
    vector<int> v={3,-1,2,-4,-6,-4,5};
    swapAlternate(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}