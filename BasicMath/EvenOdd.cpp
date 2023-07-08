//check whether a number is Even or Odd

#include<bits/stdc++.h>
using namespace std;

bool isEven(int n){
    if(n&1) return false;
    /* n&1 because LSB of even is 0 and of odd is 1
    so, for even n&1=0 and for odd n&1=1 */
    return true;
}

int main(){
    int n=28; 
    if(isEven(n)) cout<<"Even\n";
    else cout<<"Odd\n";
    return 0;
}