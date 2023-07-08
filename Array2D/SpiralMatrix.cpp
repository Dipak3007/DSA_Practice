#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}},i,j,r=4,c=3;
    cout<<"Given Matrix:- \n";
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

    //first print starting row, then ending column, then ending row, then starting column
    int startr=0,endr=r-1,startc=0,endc=c-1;
    cout<<"\nSpiral traversal:- \n";
    while(startr<=endr && startc<=endc){
        for(i=startc;i<=endc;i++)
            cout<<arr[startr][i]<<" ";
        startr++;
        if(!(startr<=endr && startc<=endc))
            break;
        for(i=startr;i<=endr;i++)
            cout<<arr[i][endc]<<" ";
        endc--;
        if(!(startr<=endr && startc<=endc))
            break;
        for(i=endc;i>=startc;i--)
            cout<<arr[endr][i]<<" ";
        endr--;
        if(!(startr<=endr && startc<=endc))
            break;
        for(i=endr;i>=startr;i--)
            cout<<arr[i][startc]<<" ";
        startc++;
    }
    return 0;
}