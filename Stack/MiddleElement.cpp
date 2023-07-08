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

void printMiddle(stack<int> s,int n){
    if(s.size() == n/2+1){
        cout<<"Middle Element = "<<s.top();
        return;
    }
    int t=s.top();
    s.pop();
    printMiddle(s,n);
    s.push(t);
}

int main(){
    stack<int> s;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    while(n--)
        s.push(rand()%100);
    print(s);
    cout<<" <- Top\n";
    printMiddle(s,s.size());
    return 0;
}