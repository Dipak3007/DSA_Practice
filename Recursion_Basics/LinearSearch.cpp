#include <iostream>
using namespace std;

int linearSearch(int target,int A[],int n){
    if(n<0) return -1;
    if(A[n]==target)    return n;
    return linearSearch(target,A,n-1);
}

int main()
{
    int A[]={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21},n=11,target=43;
    cout<<"Element Found at position : "<<linearSearch(target,A,n-1);
    return 0;
}