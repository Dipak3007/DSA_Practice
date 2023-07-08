/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int open,int close,string output){
    if(open==0 && close==0){
        cout<<output<<"\n";
        return;
    }
    if(open==close)
        solve(open-1,close,output+"(");
    else if(open==0)
        solve(open,close-1,output+")");
    else{
        solve(open-1,close,output+"(");
        solve(open,close-1,output+")");
    }
}

int main(){
    int n=3;
    string output;
    solve(n,n,output);
    return 0;
}