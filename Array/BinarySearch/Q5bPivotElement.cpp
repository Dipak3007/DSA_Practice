//Find Pivot(Maximum) Element in a sorted and rotated array

#include<bits/stdc++.h>
using namespace std;

int findMax(int A[],int n){
    int l=0,u=n-1,mid;
    while(l<u){
        if(A[u]>A[l])
            return u;
        mid=l+ceil((u-l)/2.0);
        if(A[mid]<=A[u])
            u=mid-1;
        else
            l=mid;
    }
    return u;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8},n=8,p=findMax(A,n);
    cout<<"Pivot element is "<<A[p]<<" at index "<<p;
    return 0;
}