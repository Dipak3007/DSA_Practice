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

//height is max nodes between root and a leaf
int heightNode(TreeNode* root){
    if(!root)   return 0;
    return 1+max(heightNode(root->left),heightNode(root->right));
}

//height is max edges between root and a leaf
int heightEdge(TreeNode* root){
    if(!root)   return 0;
    if(!root->left && !root->right)   return 0;
    return 1+max(heightEdge(root->left),heightEdge(root->right));
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
    cout<<"\nHeight (max nodes) = "<<heightNode(root);
    cout<<"\nHeight (max edges) = "<<heightEdge(root);
    return 0;
}