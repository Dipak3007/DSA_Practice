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


    Output
    1 - 2 - 4 - 8 - 9 - 5 - 3 - 6 - 10 - 7 - 11 -X
    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null. The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

//using morris traversal
void flatten(TreeNode *root){
    TreeNode *curr=root;
    while(curr){
        if(curr->left){
            TreeNode *pred=curr->left;
            while(pred->right)  pred=pred->right;
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
        curr=curr->right;
    }
}

//to check whether inorder and preorder are same
void inOrder(TreeNode *root){
    if(root){
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
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
    cout<<"\nFlatten Tree\n";
    flatten(root);
    inOrder(root);
    return 0;
}