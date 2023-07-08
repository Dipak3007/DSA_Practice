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

int height(TreeNode* root){
    if(!root)   return 0;
    return 1+max(height(root->left),height(root->right));
}

/*
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.The length of a path between two nodes is represented by the number of edges between them.
*/
int diameter(TreeNode* root){
    if(!root)   return 0;
    return max(1+height(root->left)+height(root->right),max(diameter(root->left),diameter(root->right)));
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
    cout<<"\nDiameter = "<<diameter(root)-1;
    return 0;
}