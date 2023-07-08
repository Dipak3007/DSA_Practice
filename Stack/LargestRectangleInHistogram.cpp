#include<bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> heights={2,1,5,6,2,3};
    int n=heights.size(),i;
    vector<int> preSmall(n),nextSmall(n);
    stack<pair<int,int>> pre,next;

    //Finding index of next smaller element of each element 
    next.push(make_pair(-1,n));
    for(i=n-1;i>=0;i--){
        int temp=heights[i];
        while(next.top().first>=temp)
            next.pop();
        nextSmall[i]=next.top().second;
        next.push(make_pair(temp,i));
    }

    //Finding index of previous smaller element of each element 
    pre.push(make_pair(-1,-1));
    for(i=0;i<n;i++){
        int temp=heights[i];
        while(pre.top().first>=temp)
            pre.pop();
        preSmall[i]=pre.top().second;
        pre.push(make_pair(temp,i));
    }

    //finding desired answer
    int ans=INT_MIN;
    for(i=0;i<n;i++){
        int temp=nextSmall[i]-preSmall[i]-1;    //width calculation for each height
        temp*=heights[i];
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}