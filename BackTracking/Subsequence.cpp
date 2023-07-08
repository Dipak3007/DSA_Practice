#include <bits/stdc++.h>
using namespace std;

void subsequence(string s,int n,string o){
    if(n==s.length()){
        cout<<o<<"\n";
        return;
    }
    subsequence(s,n+1,o);
    o+=s[n];
    subsequence(s,n+1,o);
}

int main()
{
    string s="abc",o="";
    int n=3;
    subsequence(s,0,o);
    return 0;
}