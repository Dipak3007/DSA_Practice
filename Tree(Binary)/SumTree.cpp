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
    70 20 10 -1 -1 10 -1 -1 30 -1 -1

           70
          /   \
         20   30
        / \
      10   10
    
    For every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value
*/

pair<int,bool> sumTree(TreeNode* root){
    if(!root)   return make_pair(0,true);
    if(!root->left && !root->right) return make_pair(root->val,true);

    pair<int,bool> left=sumTree(root->left);
    pair<int,bool> right=sumTree(root->right);
    return make_pair(root->val+left.first+right.first,left.second && right.second && left.first+right.first==root->val);
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
    cout<<"\nSum tree or not : "<<sumTree(root).second;
    return 0;
}