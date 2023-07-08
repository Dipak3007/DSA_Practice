//Find first and last position of an element in sorted array

//lower_bound(A,A+n,k) can be used to find first occurence
//upper_bound(A,A+n,k)-1 can be used to find last occurence 

#include<bits/stdc++.h>
using namespace std;

//by using single function but not efficient
pair<int,int> findFirstAndLastPos(int A[],int n,int k){
    int l=0,u=n-1,mid,first=-1,last=-1;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[mid]==k){
            first=last=mid;
            while(A[first-1]==k)  first--;
            while(A[last+1]==k)   last++;
            break;
        }
        else if(A[mid]<k)   l=mid+1;
        else u=mid-1;
    }
    return make_pair(first,last);
}

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
    int A[]={1,2,3,4,5,5,5,5,5,5,6,7,8},n=13,k=9;
    /* pair<int,int> p=findFirstAndLastPos(A,n,k);
    if(p.first==-1 && p.second==-1)
        cout<<k<<" not found!";
    else{
        cout<<"First pos of "<<k<<" : "<<p.first;
        cout<<"\nLast pos of "<<k<<" : "<<p.second;
    } */

    int first=findFirstPos(A,n,k),last=findLastPos(A,n,k);
    if(first==-1 && last==-1)
        cout<<k<<" not found!";
    else{
        cout<<"First pos of "<<k<<" : "<<first;
        cout<<"\nLast pos of "<<k<<" : "<<last;
    }

    /* if(lower_bound(A,A+n,k)==A+n && upper_bound(A,A+n,k)==A+n)
        cout<<k<<" not found!";
    else{
        cout<<"First pos of "<<k<<" : "<<lower_bound(A,A+n,k)-A;
        cout<<"\nLast pos of "<<k<<" : "<<upper_bound(A,A+n,k)-A-1;
    } */
    return 0;
}