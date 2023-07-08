#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    if(!s.empty()){
        int t=s.top();
        s.pop();
        print(s);
        cout<<t<<" ";
        s.push(t);
    }
}

void insertBottom(stack<int> &s,int t){
    if(s.empty()){
        s.push(t);
        return;
    }
    int p=s.top();
    s.pop();
    insertBottom(s,t);
    s.push(p);
}

void reverse(stack<int> &s){
    if(!s.empty()){
        int t=s.top();
        s.pop();
        reverse(s);
        insertBottom(s,t);
    }
}

int main(){
    stack<int> s;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    while(n--)
        s.push(rand()%100);
    print(s);
    reverse(s);
    cout<<"\nReversed Stack\n";
    print(s);
    return 0;
}