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
    Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a BST

    Input
    1 4 2 -1 -1 4 -1 -1 3 2 -1 -1 5 4 -1 -1 6 -1 -1

            1
          /   \
         4     3
        / \   / \
       4   4  2  5
                / \
               4   6
    
    Output
    20
    (3+2+5+4+6)

*/

struct Ans {
    int mini,maxi,sum;
    bool isBST;
    Ans() {}
    Ans(int mini,int maxi,int sum,bool isBST) : mini(mini), maxi(maxi), sum(sum), isBST(isBST) {}
};

/*
    every node contains four values
        - minimum value it can accept
        - maximum value it can accept
        - sum of tree till now
        - a flag which checks current subtree is BST or not
*/
Ans solve(TreeNode* root,int &ans){
    if(!root)   return Ans(INT_MAX,INT_MIN,0,true);
    Ans left=solve(root->left,ans);
    Ans right=solve(root->right,ans);
    Ans curr;
    curr.mini=min(left.mini,root->val);
    curr.maxi=max(right.maxi,root->val);
    curr.sum=root->val+left.sum+right.sum;
    curr.isBST=left.isBST && right.isBST && (root->val>left.maxi && root->val<right.mini);
    if(curr.isBST)  ans=max(ans,curr.sum);
    return curr;
}

int maxSumBST(TreeNode* root){
    int ans=0;
    solve(root,ans);
    return ans;
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
    cout<<"\nLargest BST sum : "<<maxSumBST(root);
    return 0;
}