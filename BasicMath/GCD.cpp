//Find GCD of two numbers
/*
Euclid's Algorithm
    gcd(a,b)=gcd(a-b,b)
    gcd(a,b)=gcd(a%b,b)
*/

#include<bits/stdc++.h>
using namespace std;

//Iterative Approach
int gcd(int a,int b){
    if(a==0)    return b;
    if(b==0)    return a;
    while(a!=b){
        if(a>b) a-=b;
        else    b-=a;
    }
    return a;
}

/*
int gcd(int a,int b){
    while(true){
        if(a==0)    return b;
        if(b==0)    return a;
        if(a>b) a%=b;
        else    b%=a;
    }
    return -1;
}
*/

/*
recursive approach
here, a>b

int gcd(int a,int b){
    if(a==0)    return b;
    return gcd(a%b,b);              //gcd(a%b,b) can be replaced by gcd(a-b,b)
}
*/

int main(){
    int a=72,b=16;
    cout<<gcd(a,b);
    return 0;
}