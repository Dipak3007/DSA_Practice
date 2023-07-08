//Find Pivot(minimum) Element in a sorted and rotated array

#include<bits/stdc++.h>
using namespace std;

int findPivot(int A[],int n){
    int l=0,u=n-1,mid;
    while(l<u){
        if(A[l]<A[u])
            return l;
        mid=l+(u-l)/2;
        if(A[mid]>=A[l])
            l=mid+1;
        else
            u=mid;
    }
    return l;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8},n=8,p=findPivot(A,n);
    cout<<"Pivot element is "<<A[p]<<" at index "<<p;
    return 0;
}