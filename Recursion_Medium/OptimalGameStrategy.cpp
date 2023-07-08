/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coins of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
*/

#include<bits/stdc++.h>
using namespace std;

int game(int A[],int i,int j){
    if(i>j) return 0;
    int c1=A[i]+min(game(A,i+2,j),game(A,i+1,j-1));
    int c2=A[j]+min(game(A,i+1,j-1),game(A,i,j-2));
    return max(c1,c2);
}

int main(){
    int A[]={20,30,2,2,2,10},n=6;
    cout<<game(A,0,n-1);
    return 0;
}