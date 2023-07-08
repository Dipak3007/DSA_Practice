#include<bits/stdc++.h>
using namespace std;

//for undirected graph
//using BFS becaunse in BFS whenever a node is visited first, it is shortest path
void printShortestPath(int &v,vector<vector<int>> &adj,int source,int destination){
    vector<bool> visited(v,false);
    vector<int> parent(v,-1);
    queue<int> q;
    q.push(source);
    visited[source]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto i:adj[temp]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=temp;
                if(i==destination)  break;
                q.push(i);
            }
        }
    }

    for(int i=destination;i!=-1;i=parent[i])
        cout<<i<<" <- ";
}

int main(){
    int v=8,source=0,destination=7;
    vector<vector<int>> adj={{1,2,3},{0,4},{0,7},{0,5},{1,7},{3,6},{5,7},{}};
    cout<<"Shortest Path from "<<source<<" to "<<destination<<" : ";
    printShortestPath(v,adj,source,destination);
    return 0;
}