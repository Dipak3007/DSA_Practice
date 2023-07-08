#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &v,int x){
    for(int i=0;i<v.size();i++)
        if(v[i]==x)
            return i;
    return -1;
}

int main(){
    vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    int x=12,ans;
    ans=linearSearch(v,x);
    if(ans==-1)
        cout<<"Element not found.";
    else
        cout<<"Element found at index "<<ans;
    return 0;
}