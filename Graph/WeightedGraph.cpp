#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    map<T,list<pair<T,int>>> AdjList;
public:
    void addEdge(T u,T v,int weight,bool isDirected){
        //isDirected = 0 (undirected) & 1(directed)
        AdjList[u].emplace_back(make_pair(v,weight));
        if(isDirected==0)
            AdjList[v].emplace_back(make_pair(u,weight));
    }

    void print(){
        for(auto i:AdjList){
            cout<<i.first<<" -> ";
            for(auto j:i.second)
                cout<<"("<<j.first<<","<<j.second<<") ";
            cout<<"\n";
        }
    }
};

int main(){
    Graph<char> g;
    g.addEdge('A','B',3,0);
    g.addEdge('B','C',9,0);
    g.addEdge('B','D',2,0);
    g.addEdge('C','D',5,0);
    g.addEdge('C','E',8,0);
    g.addEdge('D','E',4,0);

    g.print();
    return 0;
}