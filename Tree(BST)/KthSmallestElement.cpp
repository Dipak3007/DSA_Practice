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

//using morris traversal
int kthSmallest(TreeNode *root,int k){
    TreeNode *curr=root;
    int ans=0;
    while(curr){
        if(!curr->left){
            k--;
            ans=curr->val;
            curr=curr->right;
        }
        else{
            TreeNode *pred=curr->left;
            while(pred->right && pred->right!=curr)  pred=pred->right;
            if(!pred->right){
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=nullptr;
                k--;
                ans=curr->val;
                curr=curr->right;
            }
        }
        if(k==0)    return ans;
    }
    return ans;
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
    int k;
    cout<<"\nEnter k : ";
    cin>>k;
    cout<<kthSmallest(root,k);
    return 0;
}