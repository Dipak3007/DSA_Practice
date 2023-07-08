//find an element in rotated and sorted array

#include<bits/stdc++.h>
using namespace std;

int findPivot(int A[],int n){
    int l=0,u=n-1,mid;
    while(l<u){
        mid=l+(u-l)/2;
        if(A[l]<A[u])   return l;
        if(A[mid]>=A[l])    l=mid+1;
        else    u=mid;
    }
    return l;
}

int binarySearch(int A[],int n,int k,int l,int u){
    while(l<=u){
        int mid=l+(u-l)/2;
        if(A[mid]==k)   return mid;
        else if(A[mid]>k)   u=mid-1;
        else    l=mid+1;
    }
    return -1;
}

int main(){
    int A[]={4,5,6,1,2,3},n=6,k=1,p=findPivot(A,n),ans;
    if(k==A[p]) ans=p;
    else if(k<=A[n-1]) ans=binarySearch(A,n,k,p,n-1);
    else ans=binarySearch(A,n,k,0,p-1);
    if(ans==-1)
        cout<<k<<" not found!";
    else
        cout<<k<<" is found at pos "<<ans;
    return 0;
}