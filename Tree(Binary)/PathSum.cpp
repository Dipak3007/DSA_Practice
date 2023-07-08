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
    5 4 11 7 -1 -1 2 -1 -1 -1 8 9 -1 -1 4 5 -1 -1 1 -1 -1

            5
          /   \
         4     8
        /     / \
       11    9   4
      / \       / \
     7   2     5   1
    
    TargetSum = 22

    Given the root of a binary tree and an integer targetSum, print all root-to-leaf path such that adding up all the values along the path equals targetSum.

    Output
    5 -> 4 -> 11 -> 2
    5 -> 8 -> 9
    5 -> 8 -> 4 -> 5
*/

void solve(TreeNode* root,int sum,int targetSum,vector<int> output){
    output.emplace_back(root->val);
    if(!root->left && !root->right && sum==targetSum){
        int i;
        for(i=0;i<output.size()-1;i++)
            cout<<output[i]<<" -> ";
        cout<<output[i]<<"\n";
        return;
    }
    if(root->left) solve(root->left,sum+root->left->val,targetSum,output);
    if(root->right) solve(root->right,sum+root->right->val,targetSum,output);
}

void pathSum(TreeNode* root,int targetSum){
    if(root){
        vector<int> output;
        solve(root,root->val,targetSum,output);
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
    int targetSum;
    cout<<"Enter Target Sum : ";
    cin>>targetSum;
    pathSum(root,targetSum);
    return 0;
}