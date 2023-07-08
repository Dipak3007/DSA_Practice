#include <bits/stdc++.h>
using namespace std;

class NQueue{
    vector<int> A,front,rear,next;
    int free;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        A=vector<int> (s,0);
        front=vector<int> (n,-1);
        rear=vector<int> (n,-1);
        next=vector<int> (s);
        for(int i=0;i<s-1;i++)
            next[i]=i+1;
        next[s-1]=-1;
        free=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(free==-1)    return false;
        int i=free;
        free=next[i];
        if(front[m-1]==-1)  front[m-1]=i;
        else    next[rear[m-1]]=i;
        next[i]=-1;
        rear[m-1]=i;
        A[i]=x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1]==-1)    return -1;
        int i=front[m-1];
        front[m-1]=next[i];
        next[i]=free;
        free=i;
        return A[i];
    }
};