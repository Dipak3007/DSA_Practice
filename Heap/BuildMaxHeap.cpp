#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &v,int i,int heapSize){
    int l=2*i,r=2*i+1,largest=i;
    if(l<=heapSize && v[l]>v[largest])  largest=l;
    if(r<=heapSize && v[r]>v[largest])  largest=r;
    if(largest!=i){
        swap(v[largest],v[i]);
        maxHeapify(v,largest,heapSize);
    }
}

int main(){
    vector<int> v={INT_MIN,5,3,17,10,84,19,6,22,9};
    int i,n=v.size()-1;         //n=heapsize
    for(int i=n/2;i>=1;i--)
        maxHeapify(v,i,n);

    for(i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}