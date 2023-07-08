//find first negative number in each window. If no negative number present in window, store 0.
#include<bits/stdc++.h>
using namespace std;

/*
Approach 1: Traverse through each window
    TC - O(n*k)
    SC - O(1)
*/
// vector<int> solve(vector<int> v,int n,int k){
//     vector<int> ans;
//     for(int i=0;i<=n-k;i++){
//         int f=0;
//         for(int j=i;j<i+k;j++){
//             if(v[j]<0){
//                 ans.emplace_back(v[j]);
//                 f=1;
//                 break;
//             }
//         }
//         if(f==0)    ans.emplace_back(0);
//     }
//     return ans;
// }

/*
Approach 2: use Queue for each window
    TC - O(n*k)
    SC - O(k)
*/
vector<int> solve(vector<int> v,int n,int k){
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<k;i++)
        if(v[i]<0)  q.push(i);
    if(q.empty())   ans.emplace_back(0);
    else    ans.emplace_back(v[q.front()]);
    for(int i=k;i<n;i++){
        if(v[i]<0)  q.push(i);
        if(!q.empty() && q.front()==i-k) q.pop();
        if(q.empty())   ans.emplace_back(0);
        else    ans.emplace_back(v[q.front()]);
    }
    return ans;
}

int main(){
    vector<int> v={12,-1,-7,8,-15,30,16,28};
    int n=v.size(),k=3,i;
    vector<int> ans=solve(v,n,k);
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}