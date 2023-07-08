//print all path from (0,0) to (n-1,n-1) where only Down and Right moves allowed

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int j,int n,string output){
    if(i==n || j==n)    return;
    if(i==n-1 && j==n-1){
        cout<<output<<"\n";
        return;
    }
    output+="R";
    solve(i,j+1,n,output);
    output.pop_back();
    output+="D";
    solve(i+1,j,n,output);
}

int main(){
    int n=3;
    string output;
    solve(0,0,n,output);
    return 0;
}