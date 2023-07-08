#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A,int l,int u){
    int mid=l+(u-l)/2;
    int n1=mid-l+1,n2=u-mid,i,j,k=l;
    vector<int> v1(n1+1),v2(n2+1);
    for(i=0;i<n1;i++)
        v1[i]=A[k++];
    for(j=0;j<n2;j++)
        v2[j]=A[k++];
    v1[i]=v2[j]=INT_MAX;
    i=j=0;k=l;
    while(k<=u){
        if(v1[i]<v2[j])
            A[k++]=v1[i++];
        else
            A[k++]=v2[j++];
    }
}

void mergeSort(vector<int> &A,int l,int u){
    if(l<u){
        int mid=l+(u-l)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,u);
        merge(A,l,u);
    }
}

int main()
{
    vector<int> A={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21};
    mergeSort(A,0,A.size()-1);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    return 0;
}