//find factorial of a large number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=20,i,j;
    vector<int> v(1,1);
    for(i=2;i<=n;i++){
        int p,rem=0;
        for(j=0;j<v.size();j++){
            p=v[j]*i+rem;
            v[j]=p%10;
            rem=p/10;
        }
        while(rem){
            v.emplace_back(rem%10);
            rem/=10;
        }
    }
    for(i=v.size()-1;i>=0;i--)
        cout<<v[i];
    return 0;
}