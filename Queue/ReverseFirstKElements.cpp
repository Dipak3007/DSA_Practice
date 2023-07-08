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

//using stack
void reverseFirstK(queue<int> &q,int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        int t=q.front();
        q.pop();
        q.push(t);
    }
}

int main(){
    queue<int> q;
    int n,k;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter k : ";
    cin>>k;
    while(n--)
        q.push(rand()%100);
    print(q);
    reverseFirstK(q,k);
    cout<<"\nReversed Queue\n";
    print(q);
    return 0;
}