//union & intersection of two sorted sets using array

#include<bits/stdc++.h>
using namespace std;

void Union(vector<int> v1,vector<int> v2){
    vector<int> v;
    int i,j;
    for(i=0,j=0;i<v1.size()&&j<v2.size();){
        if(v1[i]<v2[j])
            v.emplace_back(v1[i++]);
        else if(v1[i]>v2[j])
            v.emplace_back(v2[j++]);
        else{
            v.emplace_back(v1[i++]);
            j++;
        }
    }
    while(i<v1.size())
        v.emplace_back(v1[i++]);
    while(j<v2.size())
        v.emplace_back(v2[j++]);

    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

void Intersection(vector<int> v1,vector<int> v2){
    vector<int> v;
    int i,j;
    for(i=0,j=0;i<v1.size()&&j<v2.size();){
        if(v1[i]<v2[j])
            i++;
        else if(v1[i]>v2[j])
            j++;
        else{
            v.emplace_back(v1[i++]);
            j++;
        }
    }
    if(v.size()==0){
        cout<<"No Common element found!";
        return;
    }
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

int main(){
    vector<int> v1={2,3,4,5,7,9},v2={3,6,7,8,10};
    cout<<"Union ==> ";
    Union(v1,v2);
    cout<<"\nIntersection ==> ";
    Intersection(v1,v2);
    return 0;
}