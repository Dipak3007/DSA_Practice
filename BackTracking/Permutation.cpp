#include <bits/stdc++.h>
using namespace std;

void permutation(string s,int n){
    if(n==s.length()){
        cout<<s<<"\n";
        return;
    }
    for(int i=n;i<s.length();i++){
        swap(s[i],s[n]);
        permutation(s,n+1);
    }
}

int main()
{
    string s="abc";
    permutation(s,0);
    return 0;
}