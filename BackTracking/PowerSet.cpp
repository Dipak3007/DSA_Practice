#include <bits/stdc++.h>
using namespace std;

void subset(vector<int> A,int n,vector<int> output){
    if(n<0){
        for(auto i: output)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    subset(A,n-1,output);
    output.emplace_back(A[n]);
    subset(A,n-1,output);
}

int main()
{
    vector<int> A={1, 2, 3},output;
    int n=3;
    subset(A,n-1,output);
    return 0;
}