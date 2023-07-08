#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &v,int k){
    priority_queue<int> pq;        //max heap or max priority queue
    int i;
    for(i=0;i<k;i++)    pq.push(v[i]);
    for(;i<v.size();i++)
        if(v[i]<pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    return pq.top();
}
int main(){
    vector<int> v={3,2,3,1,2,4,5,5,6};
    int k=3;
    cout<<kthSmallest(v,k);
    return 0;
}