#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    Input
    1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 -1 7 -1 11 -1 -1

            1
          /   \
         2     3
        / \   / \
       4   5  6  7
      / \    /    \
     8   9  10    11


    Output              key
    1 3 7 11             0
    2 5 6                1
    4 9 10               2
    8                    3

    Approach
    A key is given to each node such that
        - Left node key = 1 + root node key
        - Right node key = root node key
*/

void solve(TreeNode* root,int key,map<int,vector<int>> &ans){
    if(root){
        ans[key].emplace_back(root->val);
        solve(root->left,key+1,ans);
        solve(root->right,key,ans);
    }
}

void diagonalTraversal(TreeNode *root) {
    map<int,vector<int>> ans;
    solve(root,0,ans);
    for(auto i:ans){
        for(int j=0;j<i.second.size();j++)
            cout<<i.second[j]<<" ";
        cout<<"\n";
    }
}

//Tree Creation
TreeNode* createTree(){
    int x;
    cin>>x;
    if(x==-1)   return nullptr;
    return new TreeNode(x,createTree(),createTree());
}

int main(){
    TreeNode *root=createTree();
    cout<<"\nDiagonal Traversal\n";
    diagonalTraversal(root);
    return 0;
}