//used to find single source shortest path distance and applicable for both directed and undirected graph
//FAILS ON NEGATIVE WEIGHT CYCLE BUT WORKS PERFECTLY IF CYCLE IS NOT PRESENT
//It can find graph contains negative cycle or not

#include<bits/stdc++.h>
using namespace std;

class comp{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};

//It doesn't uses adjecency matrix or list, instead it uses only edges
//TC : O(v*E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> minDist(V,INT_MAX);
    minDist[S]=0;
    for(int i=1;i<V;i++)
        for(auto j:edges)
            if(minDist[j[0]]!=INT_MAX && minDist[j[0]]+j[2]<minDist[j[1]])
                minDist[j[1]]=minDist[j[0]]+j[2];
        
    //check negative cycle present or not
    for(auto j:edges)
        if(minDist[j[0]]!=INT_MAX && minDist[j[0]]+j[2]<minDist[j[1]])
            return {-1};
    return minDist;
}

int main(){
    int v=3,source=2;
    vector<vector<int>> edges={{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    vector<int> minDist=bellman_ford(v,edges,source);
    for(int i=0;i<v;i++){
        cout<<"Shortest Path from "<<source<<" to "<<i<<" : ";
        if(minDist[i]==INT_MAX)    cout<<"INF\n";
        else cout<<minDist[i]<<"\n";
    }
    return 0;
}