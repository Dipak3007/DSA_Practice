#include <iostream>
using namespace std;

void spell(int n,string m[]){
    if(n==0)
        return;
    spell(n/10,m);
    cout<<m[n%10];
}

int main()
{
    string m[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int n=431;
    spell(n,m);
    return 0;
}