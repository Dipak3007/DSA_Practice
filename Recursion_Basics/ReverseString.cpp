#include <iostream>
using namespace std;

void revStr(string &s,int i,int j){
    if(i>=j) return;
    swap(s[i],s[j]);
    revStr(s,i+1,j-1);
}

int main()
{
    string s="I am a boy";
    revStr(s,0,s.length()-1);
    cout<<s;
    return 0;
}