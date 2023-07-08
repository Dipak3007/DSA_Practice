#include<bits/stdc++.h>
using namespace std;

//using 0-indexing
int parent(int i){
    return ceil(i/2)-1;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}


void maxHeapify(vector<int> &v,int i,int heapSize){
    int l=left(i),r=right(i),largest=i;
    if(l<heapSize && v[l]>v[largest])  largest=l;
    if(r<heapSize && v[r]>v[largest])  largest=r;
    if(largest!=i){
        swap(v[largest],v[i]);
        maxHeapify(v,largest,heapSize);
    }
}
void buildMaxHeap(vector<int> &v,int heapSize){
    for(int i=parent(heapSize);i>=0;i--)
        maxHeapify(v,i,heapSize);
}

void heapSort(vector<int> &v){             //largest element is sent to end
    int heapSize=v.size();
    buildMaxHeap(v,heapSize);
    for(int i=heapSize-1;i>0;i--){
        swap(v[0],v[i]);
        buildMaxHeap(v,--heapSize);
    }
}

int main(){
    vector<int> v={5,3,17,10,84,19,6,22,9};
    heapSort(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}