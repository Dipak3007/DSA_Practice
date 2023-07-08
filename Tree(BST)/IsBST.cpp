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
    Input (BST)
    100 50 20 -1 -1 70 -1 -1 150 130 -1 -1 170 -1 -1

           100
          /   \
        50    150
       /  \   /  \
      20  70 130 170

    Input (Not BST)
    1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 -1 7 -1 11 -1 -1

            1
          /   \
         2     3
        / \   / \
       4   5  6  7
      / \    /    \
     8   9  10    11

*/

//using range
bool isBST(TreeNode* root,int start,int end){
    if(!root)   return true;
    return isBST(root->left,start,root->val) && isBST(root->right,root->val,end) && (root->val>start && root->val<end);
}

/*
    using inorder
    pred is set to INT_MIN
    and traversal is start from left most node
    for each node it is checked whether that node is greater than pred or not
    pred is updated every time
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

//Tree Creation
TreeNode* createTree(){
    int x;
    cin>>x;
    if(x==-1)   return nullptr;
    return new TreeNode(x,createTree(),createTree());
}

int main(){
    TreeNode *root=createTree();
    cout<<"\nLevel Order of BST\n";
    levelOrder(root);
    cout<<"\nBST or not : "<<isBST(root,INT_MIN,INT_MAX);
    return 0;
}