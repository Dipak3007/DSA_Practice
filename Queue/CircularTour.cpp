/*
    Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
        1. The amount of petrol that every petrol pump has.
        2. Distance from that petrol pump to the next petrol pump.
    Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between. Assume for 1 litre petrol, the truck can go 1 unit of distance.
    If there exists multiple such starting points, then the function must return the first one out of those, return -1 otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

int tour(vector<int> petrol,vector<int> distance,int n){
    int start=0,remainingPetrol=0,remainingDistance=0,i;
    for(i=0;i<n;i++){
        remainingPetrol+=(petrol[i]-distance[i]);
        if(remainingPetrol<0){
            remainingDistance+=remainingPetrol;
            remainingPetrol=0;
            start=i+1;
        }
    }
    if(remainingDistance+remainingPetrol>=0)    return start;
    return -1;
}

int main(){
    vector<int> petrol={4,6,7,4,7},distance={6,5,3,10,3};
    cout<<tour(petrol,distance,petrol.size());
    return 0;
}