/*
Find all valid combinations of k numbers that sum up to target such that the following conditions are true:
    - Only numbers 1 through 9 are used.
    - Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int target,int k,vector<int> output,int currPos){
    if((target==0 && k!=0) || target<0)   return;
    if(target==0 && k==0){
        for(int i:output)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    for(int i=currPos;i<10;i++){
        output.emplace_back(i);
        solve(target-i,k-1,output,i+1);
        output.pop_back();
    }
}

int main(){
    int target=9,k=3;
    vector<int> output;
    solve(target,k,output,1);
    return 0;
}