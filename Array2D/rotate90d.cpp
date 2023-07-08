#include<bits/stdc++.h>
using namespace std;

void transpose(int arr[][4],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++)
            swap(arr[i][j],arr[j][i]);
    }
}

void reverse(int arr[][4],int r,int c){
    for(int i=0;i<c/2;i++){
        for(int j=0;j<r;j++)
            swap(arr[j][i],arr[j][c-i-1]);
    }
}

int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},i,j,r=4,c=4;
    cout<<"Before rotation:- \n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

    //for 90d rotation first transpose the matrix, then reverse it column wise
    transpose(arr,r,c);
    reverse(arr,r,c);
    cout<<"\nAfter rotation:- \n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}