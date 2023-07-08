#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    if(!s.empty()){
        int t=s.top();
        cout<<t<<" ";
        s.pop();
        print(s);
        s.push(t);
    }
}

void insertSorted(stack<int> &s,int t){
    if(s.empty() || s.top()<t){
        s.push(t);
        return;
    }
    int p=s.top();
    s.pop();
    insertSorted(s,t);
    s.push(p);
}

void sortStack(stack<int> &s){
    if(!s.empty()){
        int t=s.top();
        s.pop();
        sortStack(s);
        insertSorted(s,t);
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
    sortStack(s);
    cout<<"\nSorted Stack\n";
    print(s);
    return 0;
}