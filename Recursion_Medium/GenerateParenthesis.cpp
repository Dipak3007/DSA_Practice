#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int open,int close,string output){
    if(open==0 && close==0){
        cout<<output<<"\n";
        return;
    }
    if(open==close)     generateParenthesis(open-1,close,output+"(");
    else if(open==0)    generateParenthesis(open,close-1,output+")");
    else{
        generateParenthesis(open-1,close,output+"(");
        generateParenthesis(open,close-1,output+")");
    }
}

int main()
{
    int n=4;
    string output;
    generateParenthesis(n,n,output);
    return 0;
}