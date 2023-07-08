#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},i,j,r=3,c=3;
    cout<<"Given Matrix:- \n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

    //left to right for even row, right to left for odd row
    cout<<"\nWave traversal:- \n";
    for(i=0;i<r;i++){
        if(i%2){
            for(j=c-1;j>=0;j--)
                cout<<arr[i][j]<<" ";
        }
        else{
            for(j=0;j<c;j++)
                cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}