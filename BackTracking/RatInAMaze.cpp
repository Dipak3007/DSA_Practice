/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,vector<vector<bool>> m,int n,vector<vector<bool>> visited){
    if((i>=0 && i<n) && (j>=0 && j<n) && !visited[i][j] && m[i][j]) return true;
    return false;
}

void solve(int i,int j,vector<vector<bool>> m,int n,string path,vector<vector<bool>> visited){
    if(i==n-1 && j==n-1){
        cout<<path<<"\n";
        return;
    }
    visited[i][j]=true;

    if(isSafe(i,j+1,m,n,visited)){
        path+="R";
        solve(i,j+1,m,n,path,visited);
        path.pop_back();
    }

    if(isSafe(i+1,j,m,n,visited)){
        path+="D";
        solve(i+1,j,m,n,path,visited);
        path.pop_back();
    }

    if(isSafe(i,j-1,m,n,visited)){
        path+="L";
        solve(i,j-1,m,n,path,visited);
        path.pop_back();
    }

    if(isSafe(i-1,j,m,n,visited)){
        path+="U";
        solve(i-1,j,m,n,path,visited);
    }
}

int main(){
    int n=4;
    vector<vector<bool>> m={{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}},visited(n,vector<bool> (n,false));
    if(!m[0][0]) cout<<"-1";
    else{
        string path;
        solve(0,0,m,n,path,visited);
    }
    return 0;
}