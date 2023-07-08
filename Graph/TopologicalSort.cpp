/*
    TOPOLOGICAL SORT CAN ONLY BE APPLIED ON DIRECTED ACYCLIC GRAPH (DAG)

    using Kahn's Algorithm
    step 1 : Find inDegree of each node
    step 2 : Insert all the nodes in a queue whose indegree is 0
    step 3 : pop one element
    step 4 : decrease indegree of all its neighbours
    step 5 : repeat steps 2 to 4 till queue is not empty
*/

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int v,vector<vector<int>> &adj){
    //Find inDegree of all nodes
    vector<int> inDegree(v,0);
    for(auto i:adj)
        for(auto j:i)
            inDegree[j]++;
    
    //insert elements with indegree 0
    queue<int> q;
    for(int i=0;i<v;i++)
        if(inDegree[i]==0)  q.push(i);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto i:adj[temp]){
            inDegree[i]--;
            if(inDegree[i]==0)  q.push(i);
        }
    }
}

int main(){
    int v=5;
    vector<vector<int>> adj={{1,2},{4},{4},{},{3}};
    cout<<"Topological Sort : ";
    topologicalSort(v,adj);
    return 0;
}