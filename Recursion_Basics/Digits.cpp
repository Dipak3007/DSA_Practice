#include <iostream>
using namespace std;

void digit(int n){
    if(n){
        digit(n/10);
        cout<<n%10<<"\n";
    }
}

int main()
{
    int n=675429;
    digit(n);
    return 0;
}