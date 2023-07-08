#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &v,int n){
    int s=0,sum=(n-1)*n/2;
    for(int i=0;i<n;i++)
        s+=v[i];
    return s-sum;
}

int main(){
    vector<int> v={5,4,6,7,2,4,1,3,8};
    cout<<findDuplicate(v,v.size());
    return 0;
}