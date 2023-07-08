/*
    TOPOLOGICAL SORT CAN ONLY BE APPLIED ON DIRECTED ACYCLIC GRAPH (DAG)
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int start,vector<bool> &visited,vector<vector<int>> &adj,stack<int> &ans){\
    visited[start]=true;
    for(auto i:adj[start])
        if(!visited[i]) dfs(i,visited,adj,ans);
    ans.push(start);
}
void topologicalSort(int v,vector<vector<int>> &adj){
    stack<int> ans;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(!visited[i])
            dfs(i,visited,adj,ans);
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

int main(){
    int v=5;
    vector<vector<int>> adj={{1,2},{4},{4},{},{3}};
    cout<<"Topological Sort : ";
    topologicalSort(v,adj);
    return 0;
}