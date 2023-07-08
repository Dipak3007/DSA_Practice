#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n/2;i++){
        int t=v[i];
        v[i]=v[n-1-i];
        v[n-1-i]=t;
    }
}

int main(){
    vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    reverse(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}