#include<bits/stdc++.h>
using namespace std;

int maximumSubArray(vector<int> &v){
    int max=INT_MIN,sum=0,start,end,x=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum>max){
            max=sum;
            start=x;
            end=i;
        }
        if(sum<0){
            sum=0;
            x=i+1;
        }
    }
    cout<<"\nStart index = "<<start<<"\nEnd index = "<<end<<"\n";
    return max;
}

int main(){
    // vector<int> v={5,4,3,6,8,2,12,45,32,87,63};
    vector<int> v={-2,-3,4,-1,-2,1,5,-3};
    cout<<maximumSubArray(v);
    return 0;
}