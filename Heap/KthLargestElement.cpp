#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;        //min heap or min priority queue
    int i;
    for(i=0;i<k;i++)    pq.push(v[i]);
    for(;i<v.size();i++)
        if(v[i]>pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    return pq.top();
}
int main(){
    vector<int> v={3,2,3,1,2,4,5,5,6};
    int k=4;
    cout<<kthLargest(v,k);
    return 0;
}