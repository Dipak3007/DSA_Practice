//Find no of occurence of an element in sorted array

#include<bits/stdc++.h>
using namespace std;

//by using two function where TC= O(log n)
int findFirstPos(int A[],int n,int k){
    int l=0,u=n-1,mid,first=-1;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]==k){
            first=mid;
            u=mid-1;
        }
        else if(A[mid]<k)   l=mid+1;
        else u=mid-1;
    }
    return first;
}

int findLastPos(int A[],int n,int k){
    int l=0,u=n-1,mid,last=-1;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]==k){
            last=mid;
            l=mid+1;
        }
        else if(A[mid]<k)   l=mid+1;
        else u=mid-1;
    }
    return last;
}

int main(){
    int A[]={1,2,3,4,5,5,5,5,5,5,6,7,8},n=13,k=5;
    int first=findFirstPos(A,n,k),last=findLastPos(A,n,k);
    if(first==-1 && last==-1)
        cout<<"No of Occurence of "<<k<<" : 0";
    else
        cout<<"No of Occurence of "<<k<<" : "<<last-first+1;
    return 0;
}