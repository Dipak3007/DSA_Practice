//count element such that A[i]>A[j] and i<j

#include <bits/stdc++.h>
using namespace std;

//by recursion, TC=O(nlogn) ; SC=O(n)
int merge(vector<int> &A,int l,int mid,int u){
    int c=0,n1=mid-l+1,n2=u-mid,i,j,k=l;
    vector<int> v1(n1),v2(n2);
    for(i=0;i<n1;i++)
        v1[i]=A[k++];
    for(j=0;j<n2;j++)
        v2[j]=A[k++];
    
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if(v1[i]<=v2[j])
            A[k++]=v1[i++];
        else{
            A[k++]=v2[j++];
            c+=((mid+1)-(l+i));
        }
    }
    while(i<n1) A[k++]=v1[i++];
    while(j<n2) A[k++]=v2[j++];
    return c;
}

int mergeSort(vector<int> &A,int l,int u){
    int c=0;
    if(l<u){
        int mid=l+(u-l)/2;
        c+=mergeSort(A,l,mid);
        c+=mergeSort(A,mid+1,u);
        c+=merge(A,l,mid,u);
    }
    return c;
}

//by iteration, TC=O(n2) ; SC=O(1)
int invertionCount(vector<int> &A){
    int c=0;
    for(int i=0;i<A.size();i++)
        for(int j=i+1;j<A.size();j++)
            if(A[i]>A[j])
                c++;
    return c;
}

int main()
{
    vector<int> A={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21};
    cout<<"Invertion Count : " <<mergeSort(A,0,A.size()-1)<<endl;
    // cout<<"Invertion Count : " <<invertionCount(A)<<endl;
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    return 0;
}