//Search an element in 2D sorted array

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int A[][3],int n,int m,int k){
    int l=0,u=n-1,mid,r=-1;
    while(l<=u){
        mid=l+(u-l)/2;
        if(k>=A[mid][0] && k<=A[mid][m-1]){
            r=mid;
            break;
        }
        else if(k<A[mid][0])    u=mid-1;
        else    l=mid+1;
    }
    if(r==-1)   return false;
    l=0,u=m-1;
    while(l<=u){
        mid=l+(u-l)/2;
        if(A[r][mid]==k){
            cout<<"Pos ==> "<<r<<","<<mid<<"\n";
            return true;
        }
        else if(A[r][mid]>k)    u=mid-1;
        else    l=mid+1;
    }
    return false;
}

int main(){
    int A[][3]={{1,5,9},{14,20,21},{30,34,43}},k=14,n=3,m=3;
    if(binarySearch(A,n,m,k))   cout<<k<<" found!";
    else    cout<<k<<" not found!";
    return 0;
}