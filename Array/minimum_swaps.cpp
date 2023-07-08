//find minimum swaps required to bring elements <=k together

#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int> v,int x){
    int i,j,w=0,ans=INT_MAX,c=0,n=v.size();
    for(i=0;i<n;i++)                                //determining window size
        if(v[i]<=x)
            w++;
    for(i=0,j=0;i<=n-w;){                           //sliding window
        if(j==w){
            i++;
            j=0;
            if(w-c<ans)
                ans=w-c;
            c=0;
        }
        else{
            if(v[i+j]<=x)
                c++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> v={2, 7, 9, 5, 8, 7, 4};
    int x=6;
    cout<<minSwap(v,x);
    return 0;
}

//optimised Approach
    // int minSwap(int arr[], int n, int k) {
    //     int i,j,w=0,bad=0;
    //     //find size of window
    //     for(i=0;i<n;i++)
    //         if(arr[i]<=k)
    //             w++;
                
    //     //find no of bad elements in first window
    //     for(i=0;i<w;i++)
    //         if(arr[i]>k)
    //             bad++;
        
    //     int ans=bad;
    //     //determine answer from remaining windows
    //     for(i=0,j=w;j<n;i++,j++){
    //         if(arr[i]>k)
    //             bad--;
    //         if(arr[j]>k)
    //             bad++;
    //         ans=min(ans,bad);
    //     }
    //     return ans;
    // }