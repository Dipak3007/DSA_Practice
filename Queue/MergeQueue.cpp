/*
    split the given queue into two parts
    and merge them by taking one one elements from both new queues

    eg
    Q ==> 1 2 3 4 5 6 7 8 9 10
    output ==> 1 5 2 6 3 7 4 8 9 10
*/

#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q){
    if(!q.empty()){
        int t=q.front();
        cout<<t<<" ";
        q.pop();
        print(q);
        q.push(t);
    }
}

void merge(queue<int> &q){
    queue<int> q1;
    int n=q.size();
    while(q.size()>n/2){
        int t=q.front();
        q.pop();
        q1.push(t);
    }

    while(!q1.empty()){
        int t=q1.front();
        q1.pop();
        q.push(t);
        t=q.front();
        q.pop();
        q.push(t);
    }
}

int main(){
    queue<int> q;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    while(n--)
        q.push(rand()%100);
    print(q);
    merge(q);
    cout<<"\nMerged Queue\n";
    print(q);
    return 0;
}