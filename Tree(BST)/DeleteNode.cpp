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

TreeNode* deleteNode(TreeNode* root,int target){
    if(!root)   return nullptr;
    if(root->val==target){
        if(!root->left && !root->right){                    //0 child
            delete root;
            return nullptr;
        }
        else if(root->left && !root->right){               //1 child (only left)
            TreeNode *temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){                //1 child (only right)
            TreeNode *temp=root->right;
            delete root;
            return temp;
        }
        else{                                               //2 child
            TreeNode *pred=root->left;
            while(pred->right)  pred=pred->right;
            root->val=pred->val;
            root->left=deleteNode(root->left,pred->val);
            return root;
        }
    }
    else if(root->val>target)
        root->left=deleteNode(root->left,target);
    else
        root->right=deleteNode(root->right,target);
    return root;
}

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
    int x;
    cout<<"\nEnter the node you want to delete : ";
    cin>>x;
    root=deleteNode(root,x);
    cout<<"\nLevel Order of New BST\n";
    levelOrder(root);
    return 0;
}