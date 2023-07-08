/*
given string="123"
output
1 2 3
1 23
12 3
123
*/

#include<iostream>
using namespace std;

void solve(string s,string o,int i){
    if(i==s.length()){
        cout<<o<<"\n";
        return;
    }
    o+=s[i];
    o+=" ";
    solve(s,o,i+1);
    o.pop_back();
    if(s[i+1]!='\0')
        solve(s,o,i+1);
}

int main(){
    string s="123",o;
    solve(s,o,0);
    return 0;
}