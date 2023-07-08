//used to find all strongly connected components in a directed graph
#include<bits/stdc++.h>
using namespace std;

//to find the topological sort ordering using dfs
void orderNodes(int start,vector<bool> &visited,vector<vector<int>>& adj,stack<int> &topo){
    visited[start]=true;
    for(auto i:adj[start])
        if(!visited[i]) orderNodes(i,visited,adj,topo);
    topo.push(start);
}

//to transpose the graph(adjecency list)
vector<vector<int>> transpose(int v,vector<vector<int>> &adj){
    vector<vector<int>> newAdj(v);
    for(int i=0;i<v;i++)
        for(int j:adj[i])
            newAdj[j].emplace_back(i);
    return newAdj;
}

//simple dfs traversal using a source node
void dfs(int start,vector<bool> &visited,vector<vector<int>>& adj){
    cout<<start<<" ";
    visited[start]=true;
    for(auto i:adj[start])
        if(!visited[i]) dfs(i,visited,adj);
}

//Function to find the strongly connected components in the graph.
void kosaraju(int V, vector<vector<int>>& adj){
    //step 1: Find Topological order using DFS
    vector<bool> visited(V,false);
    stack<int> topo;
    for(int i=0;i<V;i++)
        if(!visited[i]) orderNodes(i,visited,adj,topo);
        
    //step 2: transpose the graph(adjecency list)
    adj=transpose(V,adj);
        
    //step 3: perform dfs using topo stack
    int ans=0;
    visited=vector<bool> (V,false);
    while(!topo.empty()){
        if(!visited[topo.top()]){
            ans++;
            dfs(topo.top(),visited,adj);
            cout<<"\n";
        }
        topo.pop();
    }
    cout<<"No. of strongly connected components : "<<ans;
}

int main(){
    int v=5;
    vector<vector<int>> adj={{1},{2},{0,3},{4},{}};
    cout<<"Strongly connected components :-\n";
    kosaraju(v,adj);
    return 0;
}