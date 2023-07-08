#include <iostream>
using namespace std;

bool isPallindrome(string s,int i,int j){
    if(i>=j)    return true;
    if(s[i]!=s[j])  return false;
    return isPallindrome(s,i+1,j-1);
}

int main()
{
    string s="MadaM";
    if(isPallindrome(s,0,s.length()-1))
        cout<<"Pallindrome";
    else
        cout<<"Not Pallindrome";
    return 0;
}