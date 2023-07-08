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
    1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

            1
          /   \
         2     4
        / \     \
       3   5     7
          / \     \
         6   8     9
                  / \
                 10  11

    Output
    1 2 3 6 8 10 11 9 7 4
*/

void traverseLeft(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right) return;
        ans.emplace_back(root->val);
        if(root->left) traverseLeft(root->left,ans);
        else traverseLeft(root->right,ans);
    }
}

void traverseLeaves(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right){
            ans.emplace_back(root->val);
            return;
        }
        traverseLeaves(root->left,ans);
        traverseLeaves(root->right,ans);
    }
}

void traverseRight(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right) return;
        if(root->right) traverseRight(root->right,ans);
        else traverseRight(root->left,ans);
        ans.emplace_back(root->val);
    }
}

void BoundaryOrder(TreeNode* root){
    if(root){
        vector<int> ans;
        ans.emplace_back(root->val);
        traverseLeft(root->left,ans);
        traverseLeaves(root->left,ans);
        traverseLeaves(root->right,ans);
        traverseRight(root->right,ans);
        for(int i:ans)  cout<<i<<" ";
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
    cout<<"\nBoundary Order\n";
    BoundaryOrder(root);
    return 0;
}