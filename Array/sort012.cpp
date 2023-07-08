#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &v){
    int i,z=0,o=0,t=0,n=v.size();
    for(i=0;i<n;i++){
        if(v[i]==0)
            z++;
        else if(v[i]==1)
            o++;
        else if(v[i]==2)
            t++;
    }
    for(i=0;i<z;i++)
        v[i]=0;
    for(i=z;i<z+o;i++)
        v[i]=1;
    for(i=z+o;i<n;i++)
        v[i]=2;
}

int main(){
    vector<int> v={1,1,2,0,2,1,0,2,1,2,2,0,0,0,2,1};
    sort012(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}