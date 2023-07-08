#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> AdjList;
    unordered_map<T,bool> visited;
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

    //using iteration
    void DFS(T src){
        stack<T> st;
        //add first node to queue
        st.push(src);
        visited[src]=true;
        while(!st.empty()){
            T temp=st.top();
            st.pop();
            cout<<temp<<" ";
            for(auto i:AdjList[temp])
                if(!visited[i]){
                    st.push(i);
                    visited[i]=true;
                }
        }
    }

    //using recursion
    void DFSrec(T src){
        if(!visited[src]){
            cout<<src<<" ";
            visited[src]=true;
            for(auto i:AdjList[src])
                DFSrec(i);
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
    g.DFSrec('A');
    return 0;
}