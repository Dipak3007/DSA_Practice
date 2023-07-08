//used to find single source shortest path distance and applicable for both directed and undirected graph
//FAILS ON NEGATIVE WEIGHTS

#include<bits/stdc++.h>
using namespace std;

class comp{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

vector<int> shortestPath(int v,vector<vector<pair<int,int>>> &adj,int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> minHeap;               //pair indicates (node , its min distance from source)
    vector<bool> visited(v,false);
    vector<int> minDist(v,INT_MAX);
    minDist[source]=0;
    minHeap.push({source,0});

    while(!minHeap.empty()){
        pair<int,int> temp=minHeap.top();
        visited[temp.first]=true;
        minHeap.pop();
        for(auto i:adj[temp.first])
            if(!visited[i.first] && temp.second+i.second<minDist[i.first]){
                minDist[i.first]=temp.second+i.second;
                minHeap.push({i.first,minDist[i.first]});
                cout<<i.first<<" ";
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