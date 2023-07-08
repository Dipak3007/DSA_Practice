/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not. Print the index of the celebrity. If no such celebrity is present, Print -1.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Approach #1:
                                    0 1 0
    Let's see the knows matrix ==>  0 0 0
                                    0 1 0

    We can see that the index which is celebrity, it's whole row is 0 and whole column is 1.
    Thus we can check for index whose whole row is 0 and whole column is 1

    Time Complexity : O(n2)
    Space Complexity : O(1)
*/
int findCelebrity(vector<vector<int>> &knows,int n){
    for(int i=0;i<n;i++){
        bool f=true;
        for(int j=0;j<n;j++)
            if(i!=j && (knows[i][j]!=0 || knows[j][i]!=1)){
                f=false;
                break;
            }
        if(f)   return i;
    }
    return -1;
}

/*
    Approach #2:
    Push all the indexes into a stack.
    perform the below operation until size of stack is not 1
        - pop two elements from stack, say a and b
        - if a knows b, a cannot be a celebrity
        - and if a doesn't know b, b cannot be a celebrity, as a celebrity is known to all
        - push the celebrity back to the stack

    The only element left in the stack can be a possible celebrity.
    Now, check fo that element if it's whole row is 0 and whole column is 1. If not then it is not a celebrity.

    Time Complexity : O(n)
    Space Complexity : O(n)
*/
int findCelebritySt(vector<vector<int>> &knows,int n){
    int i;
    stack<int> st;
    for(int i=0;i<n;i++)
        st.push(i);

    while(st.size()>1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();

        (knows[a][b]==1)?st.push(b):st.push(a);
    }

    int t=st.top();
    for(int i=0;i<n;i++)
        if(t!=i && (knows[t][i]!=0 || knows[i][t]!=1))
            return -1;
    return t;
}

int main(){
    vector<vector<int>> knows={{0,1,0},{0,0,0},{0,1,0}};
    int n=knows.size();
    cout<<"Celebrity is : "<<findCelebritySt(knows,n);
    return 0;
}