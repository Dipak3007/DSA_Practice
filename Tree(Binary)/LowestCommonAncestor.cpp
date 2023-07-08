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

    p=9
    q=5

    Output
    2
*/

//The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)
TreeNode* lowestCommonAncestor(TreeNode* root,int p,int q){
    if(!root || root->val==p || root->val==q)   return root;
    TreeNode *left=lowestCommonAncestor(root->left,p,q);
    TreeNode *right=lowestCommonAncestor(root->right,p,q);

    if(!left && !right) return nullptr;
    else if(left && !right) return left;
    else if(!left && right) return right;
    else return root;
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
    int p,q;
    cout<<"Enter p : ";
    cin>>p;
    cout<<"Enter q : ";
    cin>>q;
    cout<<"\nLowest Common Ancestor of "<<p<<" and "<<q<<" : "<<lowestCommonAncestor(root,p,q)->val;
    return 0;
}