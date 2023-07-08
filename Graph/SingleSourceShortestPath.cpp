//using topological sort (can be performed on DAG only)
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int v,vector<vector<pair<int,int>>> &adj,int source){
    vector<int> minDist(v,INT_MAX),inDegree(v,0);
    for(auto i:adj)
        for(auto j:i)
            inDegree[j.first]++;
    
    minDist[source]=0;
    bool found=false;
    queue<int> q;
    for(int i=0;i<v;i++)
        if(inDegree[i]==0)  q.push(i);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        if(temp==source)    found=true;
        for(auto i:adj[temp]){
            if(--inDegree[i.first]==0)    q.push(i.first);
            if(found && minDist[temp]!=INT_MAX)
                minDist[i.first]=min(minDist[i.first],minDist[temp]+i.second);
        }
    }
    return minDist;
}

int main(){
    int v=10,source=0;
    vector<vector<pair<int,int>>> adj={{{2,6},{3,7},{4,9},{6,8},{7,6}},{{2,6},{3,7},{5,10},{6,1},{7,4}},{{3,13},{6,10},{8,8},{9,10}},{{5,3},{6,10},{7,5}},{},{{6,9},{7,7}},{{7,7},{8,8},{9,8}},{{9,1}},{{9,6}},{}};
    vector<int> minDist=shortestPath(v,adj,source);
    for(int i=0;i<v;i++){
        cout<<"Shortest Path from "<<source<<" to "<<i<<" : ";
        if(minDist[i]==INT_MAX)    cout<<"INF\n";
        else cout<<minDist[i]<<"\n";
    }
    return 0;
}