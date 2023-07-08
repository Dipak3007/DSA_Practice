//Count the number of ways to cover a distance with 1,2 and 3 steps

#include <iostream>
using namespace std;

long ways(int n){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    return ways(n-1)+ways(n-2)+ways(n-3);
}

int main()
{
    int x=4;
    cout<<ways(x);
    return 0;
}