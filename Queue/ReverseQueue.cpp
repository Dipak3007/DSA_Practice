#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q){
    if(!q.empty()){
        int t=q.front();
        q.pop();
        print(q);
        cout<<t<<" ";
        q.push(t);
    }
}

//using recursion
void reverseRec(queue<int> &q){
    if(!q.empty()){
        int t=q.front();
        q.pop();
        reverseRec(q);
        q.push(t);
    }
}

//using stack
void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
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
    reverse(q);
    cout<<"\nReversed Queue\n";
    print(q);
    return 0;
}