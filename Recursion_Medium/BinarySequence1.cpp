/*
given n, find all binary sequences of length 2n such that sum of first n bits and last n bits is same
input
2
output
0000
0101
0110
1010
1001
1111
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int leftSum,int rightSum,vector<char> output,int i,int j){
    if(i<j){
        output[i]='0';
        output[j]='0';
        solve(leftSum,rightSum,output,i+1,j-1);
        output[i]='0';
        output[j]='1';
        solve(leftSum,rightSum+1,output,i+1,j-1);
        output[i]='1';
        output[j]='0';
        solve(leftSum+1,rightSum,output,i+1,j-1);
        output[i]='1';
        output[j]='1';
        solve(leftSum+1,rightSum+1,output,i+1,j-1);
    }
    else if(leftSum==rightSum){
        for(auto i:output)
            cout<<i;
        cout<<"\n";
    }
}

int main(){
    int n=3,ls=0,rs=0;
    vector<char> output(2*n);
    solve(ls,rs,output,0,2*n-1);
    return 0;
}