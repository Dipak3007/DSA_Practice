#include<bits/stdc++.h>
using namespace std;

pair<int,int> findMaxMin(vector<int> &v){
    int max=v[0],min=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]>max)
            max=v[i];
        if(v[i]<min)
            min=v[i];
    }
    return make_pair(max,min);
}

int main(){
    vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    pair<int,int> p=findMaxMin(v);
    cout<<"Max= "<<p.first<<endl;
    cout<<"Min= "<<p.second;
    return 0;
}