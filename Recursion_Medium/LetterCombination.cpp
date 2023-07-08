//Leetcode- Letter Combination of a phone number

#include <bits/stdc++.h>
using namespace std;

void solve(string digit,string output,unordered_map<char,string> m,int index,vector<string> &ans){
    if(index==digit.length()){
        ans.emplace_back(output);
        return;
    }
    string temp=m[digit[index]];
    for(int i=0;i<temp.length();i++){
        output+=temp[i];
        solve(digit,output,m,index+1,ans);
        output.pop_back();
    }
}

vector<string> letterCombination(string digit){
    string output;
    unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans;
    solve(digit,output,m,0,ans);
    return ans;
}

int main()
{
    string digit="927";
    vector<string> ans=letterCombination(digit);
    for(auto i:ans)
        cout<<i<<"\n";
    return 0;
}