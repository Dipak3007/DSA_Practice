//find common elements in 3 sorted array

#include<bits/stdc++.h>
using namespace std;

vector<int> Intersection(vector<int> v1,vector<int> v2){
    vector<int> v;
    for(int i=0,j=0;i<v1.size()&&j<v2.size();){
        if(v1[i]<v2[j])
            i++;
        else if(v1[i]>v2[j])
            j++;
        else{
            v.emplace_back(v1[i++]);
            j++;
        }
    }
    return v;
}

int main(){
    vector<int> v1={2,3,4,5,7,9},v2={3,6,7,8,10},v3={3,6,7,10,15,19,21},v;
    v=Intersection(v1,v2);
    v=Intersection(v,v3);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}