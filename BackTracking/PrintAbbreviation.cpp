/*
input
str="ABC"

output
["ABC","AB1","A2","A1C","1BC","1B1","2C","3"]
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string s,int i,string o,int next){
    if(i==s.length()){
        int n=s.length()-o.length()-next;
        if(n)   cout<<n;
        cout<<o;
        if(next)    cout<<next;
        cout<<"\n";
        return;
    }
    o+=s[i];
    next--;
    solve(s,i+1,o,next);
    o.pop_back();
    next++;
    solve(s,i+1,o,next);
}

int main()
{
    string s="ABC",output;
    int next=s.length();
    solve(s,0,output,next);
    return 0;
}