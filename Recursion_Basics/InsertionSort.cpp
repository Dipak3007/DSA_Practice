#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A,int index){
    if(index<A.size()){
        int key=A[index],j;
        for(j=index-1;j>=0 && A[j]>key;j--)
            A[j+1]=A[j];
        A[j+1]=key;
        insertionSort(A,index+1);
    }
}

int main()
{
    vector<int> A={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21};
    insertionSort(A,1);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    return 0;
}