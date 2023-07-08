#include<bits/stdc++.h>
using namespace std;
    
int main(){
    vector<int> arr={0,4,3,2,1};
    int n=arr.size();
    stack<int> st;
	st.push(-1);
	for(int i=n-1;i>=0;i--){
	    int t=arr[i];
        while(st.top()>=t)
            st.pop();
	    arr[i]=st.top();
	    st.push(t);
	}

    for(int i:arr)
        cout<<i<<" ";
    return 0;
}