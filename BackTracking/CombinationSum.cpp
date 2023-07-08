/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> candidates,int target,vector<int> output,int currPos){
    if(target<0)    return;
    if(target==0){
        for(int i:output)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    for(int i=currPos;i<candidates.size();i++){
        output.emplace_back(candidates[i]);
        solve(candidates,target-candidates[i],output,i);
        output.pop_back();
    }
}

int main(){
    int target=8;
    vector<int> candidates={2,3,5},output;
    solve(candidates,target,output,0);
    return 0;
}