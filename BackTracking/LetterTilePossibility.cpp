/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string tiles,int n,vector<bool> visited,string output,unordered_set<string> &ans){
    for(int i=0;i<n;i++)
        if(!visited[i]){
            output+=tiles[i];
            visited[i]=true;
            ans.insert(output);
            solve(tiles,n,visited,output,ans);
            output.pop_back();
            visited[i]=false;
        }
}

int main(){
    string tiles="AAB",output;
    int n=tiles.length();
    vector<bool> visited(n,false);
    unordered_set<string> ans;
    solve(tiles,n,visited,output,ans);
    cout<<ans.size();
    return 0;
}