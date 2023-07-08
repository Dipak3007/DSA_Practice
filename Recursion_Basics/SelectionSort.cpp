#include <iostream>
using namespace std;

void selectionSort(int A[],int n){
    if(n>0){
        int max=0;
        for(int i=1;i<=n;i++)
            if(A[i]>A[max])
                max=i;
        swap(A[n],A[max]);
        selectionSort(A,n-1);
    }
}

int main()
{
    int A[]={4, 7, 2, 10, 23, 19, 24, 56, 34, 43, 21},n=11;
    selectionSort(A,n-1);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}