//Find peak in a mountain array
//peak example, A=[0,1,2,3,4,2,0], here peak=4, 0<i<n-1

#include<bits/stdc++.h>
using namespace std;

int findPeak(int A[],int n){
    int l=0,u=n-1,mid;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]>A[mid-1] && A[mid]>A[mid+1])  return mid;
        else if(A[mid]>A[mid-1] && A[mid]<A[mid+1]) l=mid+1;
        else u=mid-1;
    }
    return -1;
}

int main(){
    int A[]={0,2,4,6,3,2,1},n=7;
    cout<<"Peak of mountain ==> "<<A[findPeak(A,n)];
    return 0;
}