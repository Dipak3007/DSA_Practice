#include <iostream>
using namespace std;

void bubbleSort(int A[],int n){
    if(n>1){
        int c=0;
        for(int i=0;i<n-1;i++)
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
                c++;
            }
        if(!c)  return;
        bubbleSort(A,n-1);
    }
}

int main()
{
    int A[]={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21},n=11;
    bubbleSort(A,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}