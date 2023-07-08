#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &v){
    int i,n=v.size(),x=v[n-1];
    for(i=n-1;i>0;i--)
        v[i]=v[i-1];
    v[0]=x;
}

int main(){
    vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    rotate(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}