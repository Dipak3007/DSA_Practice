//find a pair that sum to a given value

#include<bits/stdc++.h>
using namespace std;

pair<int,int> pairSum(vector<int> v,int x){
    sort(v.begin(),v.end());
    int i,j,n=v.size();
    for(i=0,j=n-1;i<j;){
        if(v[i]+v[j]==x)
            return make_pair(v[i],v[j]);
        else if(v[i]+v[j]>x)
            j--;
        else
            i++;
    }
    return make_pair(INT_MIN,INT_MIN);
}

int main(){
    vector<int> v={3,1,4,13,9,5};
    int x=14;
    pair<int,int> p=pairSum(v,x);
    if(p.first==INT_MIN && p.second==INT_MIN)
        cout<<"Element not found.";
    else
        cout<<p.first<<" "<<p.second;
    return 0;
}