#include <iostream>
using namespace std;

int expo(int a,int n){
    if(n==0)
        return 1;
    int e=expo(a,n/2);
    if(n&1) return e*e*a;   //if n&1 =1, n is odd and if n&1=0, nis even
    return e*e;
}

/*
using loop,
int ans=1;
while(n){
    if(n&1) ans*=a;
    a*=a;
    n>>=1;      //n=n>>1(right shift by 1 bit) means n=n/2;
}

*/

int main()
{
    cout<<expo(2,7);
    return 0;
}