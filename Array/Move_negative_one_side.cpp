#include<bits/stdc++.h>
using namespace std;

void moveNegative(vector<int> &v){
    int i,j=0;
    for(i=0;i<v.size();i++)
        if(v[i]<0){
            int t=v[i];
            v[i]=v[j];
            v[j]=t;
            j++;
        }
}

int main(){
    vector<int> v={3,-1,2,-4,-6,-4,5};
    moveNegative(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}