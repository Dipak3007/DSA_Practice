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

void preorder(TreeNode *root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
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
    cout<<"\nPreorder ==> ";
    preorder(root);
    cout<<"\nInorder ==> ";
    inorder(root);
    cout<<"\nPostorder ==> ";
    postorder(root);
    return 0;
}