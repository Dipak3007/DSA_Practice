//check whether a number is prime or not

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2;i<=sqrt(n);i++)
        if(!(n%i)) return false;
    return true;
}

int main(){
    int n=29;
    if(isPrime(n)) cout<<"Prime\n";
    else cout<<"Not Prime\n";
    return 0;
}