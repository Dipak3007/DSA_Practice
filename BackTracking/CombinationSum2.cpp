/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination
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
        if(i>currPos && candidates[i]==candidates[i-1]) continue;
        output.emplace_back(candidates[i]);
        solve(candidates,target-candidates[i],output,i+1);
        output.pop_back();
    }
}

int main(){
    int target=8;
    vector<int> candidates={10,1,2,7,6,1,5},output;
    sort(candidates.begin(),candidates.end());
    solve(candidates,target,output,0);
    return 0;
}