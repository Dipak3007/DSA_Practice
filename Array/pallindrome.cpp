#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n/2;i++)
        if(v[i]!=v[n-1-i])
            return false;
    return true;
}

int main(){
    // vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    vector<int> v={4,5,3,2,1,2,3,5,4};
    if(isPallindrome(v))
        cout<<"Array is pallindrome.";
    else
        cout<<"Not Pallindrome. ";
    return 0;
}