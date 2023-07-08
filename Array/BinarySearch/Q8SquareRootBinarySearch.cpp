//find Square root using binary search

#include<bits/stdc++.h>
using namespace std;

int findSqrt(int n){
    int l=0,u=n,mid,ans;
    while(l<u){
        mid=l+(u-l)/2;
        long p=(long)mid*mid;
        if(p==n) return mid;
        else if(p>n)    u=mid-1;
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int n=47;
    cout<<"Square root of "<<n<<" = "<<findSqrt(n);
    return 0;
}