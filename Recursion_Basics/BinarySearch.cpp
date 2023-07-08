#include <iostream>
using namespace std;

int binarySearch(int target,int A[],int l,int u){
    if(l>u)    return -1;
    int mid=l+(u-l)/2;
    if(A[mid]==target)  return mid;
    if(A[mid]>target)   return binarySearch(target,A,l,mid-1);
    return binarySearch(target,A,mid+1,u);
}

int main()
{
    int A[]={2, 4, 7, 10, 19, 21, 23, 24, 34, 43, 56},n=11,target=43;
    cout<<"Element Found at position : "<<binarySearch(target,A,0,n-1);
    return 0;
}