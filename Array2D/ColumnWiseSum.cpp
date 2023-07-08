#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}},ans[]={0,0,0,0},i,j,r=3,c=4;
    for(i=0;i<c;i++){
        for(j=0;j<r;j++)
            ans[i]+=arr[j][i];
    }
    for(i=0;i<c;i++)
        cout<<ans[i]<<" ";
    return 0;
}