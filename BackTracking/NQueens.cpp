/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int n,vector<string>& board){
    int x=row,y=col;
    //check row
    while(y>=0){
        if(board[x][y]=='Q')    return false;
        y--;
    }
    //check upper Left digonal
    x=row,y=col;
    while(x>=0 && y>=0){
        if(board[x][y]=='Q')    return false;
        x--;
        y--;
    }
    //check lower left digonal
    x=row,y=col;
    while(x<n && y>=0){
        if(board[x][y]=='Q')    return false;
        x++;
        y--;
    }
    return true;
}

void solve(vector<string> board,int n,int col){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
        if(isSafe(i,col,n,board)){
            board[i][col]='Q';
            solve(board,n,col+1);
            board[i][col]='.';    //backtracking
        }
}

int main(){
    int n=4;
    vector<string> board(n,string (n,'.'));
    solve(board,n,0);
    return 0;
}