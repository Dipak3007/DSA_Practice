#include<bits/stdc++.h>
using namespace std;

//using dfs with backtracking
bool dfs(int start,vector<bool> &visited,vector<bool> &visitBackTrack,vector<vector<int>> &adj){
    visited[start]=true;
    visitBackTrack[start]=true;
    for(auto i:adj[start]){
        if(!visited[i] && dfs(i,visited,visitBackTrack,adj))    return true;
        else if(visited[i] && visitBackTrack[i])  return true;
    }
    visitBackTrack[start]=false;
    return false;
}

bool isCyclic(int &v,vector<vector<int>> &adj){
    vector<bool> visited(v,false),visitBackTrack(v,false);
    bool ans=false;
    for(int i=0;i<v;i++)
        if(!visited[i])
            if(dfs(i,visited,visitBackTrack,adj)) return true;
    return false;
}

int main(){
    int v=4;
    vector<vector<int>> adj={{1},{2},{3},{3}};
    cout<<"Graph Cyclic or not : "<<isCyclic(v,adj);
    return 0;
}