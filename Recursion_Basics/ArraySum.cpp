#include <iostream>
using namespace std;

int sum(int A[],int n){
    if(n<0)    return 0;
    return A[n]+sum(A,n-1);
}

int main()
{
    int A[]={2, 4, 7, 10, 19, 21, 23, 24, 34, 43, 56},n=11;
    cout<<sum(A,n-1);
    return 0;
}