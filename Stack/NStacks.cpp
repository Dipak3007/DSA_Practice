#include <bits/stdc++.h>
using namespace std;

class NStack
{
    vector<int> v,top,below;
    int free;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        v=vector<int> (S,0);
        top=vector<int> (N,-1);
        below=vector<int> (S);
        for(int i=0;i<S-1;i++)
            below[i]=i+1;
        below[S-1]=-1;
        free=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(free==-1)    return false;
        int i=free;
        free=below[i];
        below[i]=top[m-1];
        top[m-1]=i;
        v[i]=x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1)    return -1;
        int i=top[m-1];
        top[m-1]=below[i];
        below[i]=free;
        free=i;
        return v[i];
    }
};