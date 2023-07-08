//no of ways to reach destination using 1,2 or 3 jumps

#include <bits/stdc++.h>
using namespace std;

int jump(int n){
    if(n==0)    return 1;
    if(n<0) return 0;
    return jump(n-1)+jump(n-2)+jump(n-3);
}

int main()
{
    int n=4;
    cout<<jump(n);
    return 0;
}