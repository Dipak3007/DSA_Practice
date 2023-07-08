//reference- Love Babbar Graph lecture 6 PDF(find bridge in a graph)

#include<bits/stdc++.h>
using namespace std;

void dfs(int source,int parent,int &timer,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &discoveryTime,vector<int> &lowestDiscoveryTime){
    visited[source]=true;
    discoveryTime[source]=lowestDiscoveryTime[source]=timer;

    for(auto i:adj[source]){
        if(visited[i] && i!=parent){
            lowestDiscoveryTime[source]=min(lowestDiscoveryTime[source],discoveryTime[i]);
        }
        else if(!visited[i]){
            timer++;
            dfs(i,source,timer,adj,visited,discoveryTime,lowestDiscoveryTime);
            lowestDiscoveryTime[source]=min(lowestDiscoveryTime[source],lowestDiscoveryTime[i]);
            if(lowestDiscoveryTime[i]>discoveryTime[source])    cout<<source<<" - "<<i<<"\n";
        }
    }
}

void criticalEdge(int n, vector<vector<int>>& adj) {
    vector<int> discoveryTime(n,0),lowestDiscoveryTime(n,0);
    vector<bool> visited(n,false);
    int timer=0,parent=-1,source=0;
    dfs(source,parent,timer,adj,visited,discoveryTime,lowestDiscoveryTime);
}

int main(){
    int v=4;
    vector<vector<int>> adj={{1,2},{0,2,3},{0,1},{1}};
    cout<<"Critical Edges (Bridges) in given graph are :-\n";
    criticalEdge(v,adj);
    return 0;
}