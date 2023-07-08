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
    100 50 150 20 70 130 170 -1

    Output
           100
          /   \
        50    150
       /  \   /  \
      20  70 130 170

*/

void levelOrder(TreeNode* root){
    if(!root)   return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        TreeNode *temp=q.front();
        q.pop();
        if(!temp){
            cout<<"\n";
            if(!q.empty())  q.push(nullptr);
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

TreeNode* buildBST(TreeNode* root,int x){
    if(!root)    return new TreeNode(x);
    if(x<root->val) root->left=buildBST(root->left,x);
    else    root->right=buildBST(root->right,x);
    return root;
}

//BST Creation - Build BST till -1 is not entered
TreeNode* createBST(){
    TreeNode *root=nullptr;
    int x;
    cin>>x;
    while(x!=-1){
        root=buildBST(root,x);
        cin>>x;
    }
    return root;
}

int main(){
    TreeNode *root=createBST();
    cout<<"\nLevel Order of BST\n";
    levelOrder(root);
    return 0;
}