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
    1 -2 1 -1 0 0 0 3 0 0 -3 0 -2 0 0
    '0' means nullptr

            1
          /   \
        -2    -3
        / \     \
       1   3    -2
      /
    -1
    
    TargetSum = -1

    Given the root of a binary tree and an integer targetSum, print the paths where the sum of the values along the path equals targetSum.
    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes)

    Output
    1 -> -2
    1 -> -2 -> 1 -> -1
    -2 -> 1
    -1
*/

void solve(TreeNode* root,int sum,int targetSum,vector<int> output){
    output.emplace_back(root->val);
    if(sum==targetSum){
        int i;
        for(i=0;i<output.size()-1;i++)
            cout<<output[i]<<" -> ";
        cout<<output[i]<<"\n";
    }
    if(root->left) solve(root->left,sum+root->left->val,targetSum,output);
    if(root->right) solve(root->right,sum+root->right->val,targetSum,output);
}

void pathSum(TreeNode* root,int targetSum){
    if(root){
        vector<int> output;
        solve(root,root->val,targetSum,output);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
    }
}

//Tree Creation
TreeNode* createTree(){
    int x;
    cin>>x;
    if(x==0)   return nullptr;                          //0 means null
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