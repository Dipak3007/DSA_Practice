//binary search implementation

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[],int n,int k){
    int l=0,u=n-1,mid;
    while(l<=u){
        mid=l+(u-l)/2;  //to avoid integer overflow (l+u)/2 is writeen as l +(u-l)/2
        if(A[mid]==k) return mid;
        else if(A[mid]>k) u=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main(){
    int n=10,A[]={1,2,3,4,5,6,7,8,9,10},k=12;        //array must be sorted or monotonic
    int i=binarySearch(A,n,k);
    if(i<0)
        cout<<k<<" not found!";
    else
        cout<<k<<" is found at position "<<i;
    return 0;
}