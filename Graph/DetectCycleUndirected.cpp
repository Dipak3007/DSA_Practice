#include<bits/stdc++.h>
using namespace std;

//using bfs
bool bfs(int source,vector<bool> &visited,vector<vector<int>> &adj){
    queue<pair<int,int>> q;
    q.push(make_pair(source,-1));
    visited[source]=true;
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();

        for(int i:adj[temp.first]){
            if(!visited[i]){
                q.push(make_pair(i,temp.first));
                visited[i]=true;
            }
            else{
                if(i!=temp.second)  return true;
            }
        }
    }
    return false;
}

//using dfs with stack
bool dfs(int source,vector<bool> &visited,vector<vector<int>> &adj){
    stack<pair<int,int>> st;
    st.push(make_pair(source,-1));
    visited[source]=true;
    while(!st.empty()){
        pair<int,int> temp=st.top();
        st.pop();

        for(int i:adj[temp.first]){
            if(!visited[i]){
                st.push(make_pair(i,temp.first));
                visited[i]=true;
            }
            else{
                if(i!=temp.second)  return true;
            }
        }
    }
    return false;
}

//using dfs with recursion
bool dfsRec(pair<int,int> start,vector<bool> &visited,vector<vector<int>> &adj){
    int source=start.first;
    for(int i:adj[source]){
        //check if neighbour is not parent
        if(i==start.second) continue;
        if(visited[i])   return true;
        visited[i]=true;
        if(dfsRec(make_pair(i,source),visited,adj))    return true;
    }
    return false;
}

bool isCyclic(int &v,vector<vector<int>> &adj){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(!visited[i])
            if(dfs(i,visited,adj))  return true;
        
    /* for calling recursive function
        if(!visited[i]){
            visited[i]=true;
            if(dfsRec(make_pair(i,-1),visited,adj))  return true;
        }
    */
    return false;
}

int main(){
    int v=5;
    vector<vector<int>> adj={{1},{0,2,4},{1,3},{2,4},{1,3}};
    cout<<"Graph Cyclic or not : "<<isCyclic(v,adj);
    return 0;
}