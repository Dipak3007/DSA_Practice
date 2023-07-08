//find a triplet that sum to a given value

#include<bits/stdc++.h>
using namespace std;

vector<int> tripletSum(vector<int> v,int x){
    sort(v.begin(),v.end());
    int i,j,k,n=v.size();
    vector<int> ans(3);
    for(i=0;i<n-2;i++){
        ans[0]=v[i];
        for(j=i+1,k=n-1;j<k;){
            if((v[j]+v[k])==(x-v[i])){
                ans[1]=v[j];
                ans[2]=v[k];
                return ans;
            }
            else if((v[j]+v[k])>(x-v[i]))
                k--;
            else
                j++;
        }
    }
    return {INT_MIN,INT_MIN,INT_MIN};
}

int main(){
    vector<int> v={3,1,4,13,9,5};
    int x=25;
    vector<int> ans=tripletSum(v,x);
    if(ans[0]==INT_MIN)
        cout<<"Element not found.";
    else
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    return 0;
}