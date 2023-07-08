#include <iostream>
using namespace std;

bool isSorted(int A[],int n){
    if(n==0)    return true;
    if(A[n]<A[n-1]) return false;
    return isSorted(A,n-1);
}

int main()
{
    int A[]={2, 4, 7, 10, 19, 21, 23, 24, 34, 43, 56},n=11;
    if(isSorted(A,n-1))
        cout<<"Sorted!!!";
    else
        cout<<"Not Sorted!!!";
    return 0;
}