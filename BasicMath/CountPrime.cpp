//Count no of primes strictly less than n
/*
SEIVE OF ERASTOSTHENES

    TC= n/2 + n/3 + n/5 + n/7 + ......
      = n*( 1/2 + 1/3 + 1/5 + 1/7 + ..... )
      = n*log(log(n))       [as 1/2 + 1/3 + 1/5 + 1/7 + ... = log(log(n)) , it is in harmonic Progression]
      =O(n*log(log(n)))

    SC= O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int countPrime(int n){
    if(n==0 || n==1)    return 0;
    vector<bool> prime(n,true);
    prime[0]=prime[1]=false;
    int ans=0,i,j;
    for(i=2;i<n;i++)
        if(prime[i]){
            ans++;
            for(j=2*i;j<n;j+=i)
                prime[j]=false;
        }
    return ans;
}

int main(){
    int n=30;
    cout<<countPrime(n);
    return 0;
}