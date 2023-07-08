//Search in a sorted array of unknown size

#include<bits/stdc++.h>
using namespace std;

pair<int,int> findRange(int A[],int k){             //finding range by doubling upper_index each time
    int l=0,u=1;
    while(A[u]<k){
        l=u;
        u*=2;
    }
    return make_pair(l,u);
}

int binarySearch(int A[],int k){
    pair<int,int> p=findRange(A,k);
    int l=p.first,u=p.second,mid;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]==k)   return mid;
        else if(A[mid]>k)   u=mid-1;
        else    l=mid+1;
    }
    return -1;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},k=13;        //array must be sorted or monotonic
    int i=binarySearch(A,k);
    if(i<0)
        cout<<k<<" not found!";
    else
        cout<<k<<" is found at position "<<i;
    return 0;
}