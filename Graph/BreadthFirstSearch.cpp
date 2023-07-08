#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> AdjList;
public:
    void addEdge(T u,T v,bool isDirected){
        //isDirected = 0 (undirected) & 1(directed)
        AdjList[u].emplace_back(v);
        if(isDirected==0)
            AdjList[v].emplace_back(u);
    }

    void print(){
        for(auto i:AdjList){
            cout<<i.first<<" -> ";
            for(T j:i.second)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
    int noOfNodes(){
        return AdjList.size();
    }
    void BFS(T src){
        unordered_map<T,bool> visited;
        queue<T> q;
        //add first node to queue
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T temp=q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto i:AdjList[temp])
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
        }
    }
};

int main(){
    Graph<char> g;
    g.addEdge('A','B',0);
    g.addEdge('B','C',0);
    g.addEdge('B','D',0);
    g.addEdge('C','D',0);
    g.addEdge('C','E',0);
    g.addEdge('D','E',0);

    g.print();
    cout<<"No of Nodes : "<<g.noOfNodes()<<"\n";
    g.BFS('A');
    return 0;
}