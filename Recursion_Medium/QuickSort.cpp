//choose A[i] one by one and place them in correct place such that all A[j]<=A[i] where j<i and all A[j]>A[i] where j>i

#include <bits/stdc++.h>
using namespace std;

/*
more understandable partion

int partition(vector<int> &A,int l,int u){
    int pivot=A[l],c=0,i,j;
    for(i=l+1;i<=u;i++)
        if(A[i]<=pivot)
            c++;
    int pivotPoint=l+c;
    swap(A[l],A[pivotPoint]);
    i=l;j=u;
    while(i<pivotPoint && j>pivotPoint){
        while(A[i]<=pivot)   i++;
        while(A[j]>pivot)   j--;
        if(i<pivotPoint && j>pivotPoint)
            swap(A[i++],A[j--]);
    }
    return pivotPoint;
}
*/

int partition(vector<int> &A,int l,int u){
    int pivot=A[u],j=l;
    for(int i=l;i<u;i++)
        if(A[i]<=pivot)
            swap(A[j++],A[i]);
    swap(A[j],A[u]);
    return j;
}

void quickSort(vector<int> &A,int l,int u){
    if(l<u){
        int p=partition(A,l,u);
        quickSort(A,l,p-1);
        quickSort(A,p+1,u);
    }
}

int main()
{
    vector<int> A={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21};
    quickSort(A,0,A.size()-1);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    return 0;
}