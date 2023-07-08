/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
    - Each of the digits 1-9 must occur exactly once in each row.
    - Each of the digits 1-9 must occur exactly once in each column.
    - Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,char val,vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        if(board[row][i]==val)  return false;
        if(board[i][col]==val)  return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)    return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(board[i][j]=='.'){
                for(char val='1';val<='9';val++)
                    if(isSafe(i,j,val,board)){
                        board[i][j]=val;
                        if(solve(board))    return true;
                        board[i][j]='.';    //backtracking
                    }
                return false;
            }
    return true;
}

int main(){
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solve(board);
    for(int i=0;i<9;i++){
        if(i%3==0) cout<<"\n";
        for(int j=0;j<9;j++){
            if(j%3==0) cout<<"\t";
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}