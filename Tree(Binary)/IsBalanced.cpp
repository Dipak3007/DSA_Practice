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

//A tree is balanced if difference of height of left sub-tree and right sub-tree is atmost 1
pair<int,bool> isBalanced(TreeNode* root){
    if(!root)   return make_pair(0,true);
    pair<int,bool> left=isBalanced(root->left);
    pair<int,bool> right=isBalanced(root->right);
    return make_pair(1+max(left.first,right.first),left.second && right.second && abs(left.first-right.first)<=1);
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
    cout<<"\nBalanced or not : "<<isBalanced(root).second;
    return 0;
}