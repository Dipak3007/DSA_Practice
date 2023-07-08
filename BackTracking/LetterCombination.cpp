/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
2---> abc
3---> def
4---> ghi
5---> jkl
6---> mno
7---> pqrs
8---> tuv
9---> wxyz
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string digits,int i,string output,unordered_map<char,string> m){
    if(i==digits.length()){
        cout<<output<<"\t";
        return;
    }
    string temp=m[digits[i]];
    for(char it:temp){
        output+=it;
        solve(digits,i+1,output,m);
        output.pop_back();
    }
}

int main(){
    string digits="9274",output;
    unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    solve(digits,0,output,m);
    return 0;
}