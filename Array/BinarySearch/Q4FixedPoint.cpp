//find fixed point ie value=index in a sorted array

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[],int n){
    int l=0,u=n-1,mid;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]==mid) return mid;
        else if(A[mid]>mid) u=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main(){
    int n=5,A[]={-10,-5,0,3,7};
    int i=binarySearch(A,n);
    if(i<0)
        cout<<"Fixed point not found!";
    else
        cout<<i<<" is a Fixed point.";
    return 0;
}