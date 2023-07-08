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
    1 2 3 5 6 8 4 7 9 10 11

    TC: O(n)
    SC: O(1)
*/

TreeNode* getPredecessor(TreeNode *root){
    TreeNode *curr=root->left;
    while(curr->right && curr->right!=root)
        curr=curr->right;
    return curr;
}

void morrisPreOrder(TreeNode* root){
    TreeNode *curr=root;
    while(curr){
        if(!curr->left){
            cout<<curr->val<<" ";
            curr=curr->right;
        }
        else{
            TreeNode *pred=getPredecessor(curr);
            if(!pred->right){
                cout<<curr->val<<" ";
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=nullptr;
                curr=curr->right;
            }
        }
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
    cout<<"\nMorris Traversal\n";
    morrisPreOrder(root);
    return 0;
}