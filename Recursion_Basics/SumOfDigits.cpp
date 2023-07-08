#include <iostream>
using namespace std;

long sumDigit(int n){
    if(n==0)
        return 0;
    return n%10 + sumDigit(n/10);
}

int main()
{
    int x=985647132;
    cout<<sumDigit(x);
    return 0;
}