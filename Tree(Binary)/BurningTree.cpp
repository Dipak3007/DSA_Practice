/*
    Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
*/

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
    1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1

            1
         /     \
        2       3
      /  \        \
     4    5        6
         / \        \
        7   8        9
                      \
                      10

    Target - 8

    Output
    7

    Explaination
    If leaf with the value 8 is set on fire. 
    After 1 sec: 5 is set on fire.
    After 2 sec: 2, 7 are set to fire.
    After 3 sec: 4, 1 are set to fire.
    After 4 sec: 3 is set to fire.
    After 5 sec: 6 is set to fire.
    After 6 sec: 9 is set to fire.
    After 7 sec: 10 is set to fire.
    It takes 7s to burn the complete tree.

    Approach
    Level Order Traversal will be used but by using Target Node as root
    ans its two children and parent will be treated as children.

    Two additional Data structure will be used
        - one to store parent of each node
        - other to check whether node is burning or not
*/

//to set parent of each node
void setParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
    if(root->left){
        parent[root->left]=root;
        setParent(root->left,parent);
    }
    if(root->right){
        parent[root->right]=root;
        setParent(root->right,parent);
    }
}

//to find target node
TreeNode* findTarget(TreeNode* root,int target){
    if(!root)   return nullptr;
    if(root->val==target)  return root;
    TreeNode *left=findTarget(root->left,target);
    TreeNode *right=findTarget(root->right,target);
    if(left)    return left;
    if(right)   return right;
    return nullptr;
}

int minTime(TreeNode* root, int target) 
{
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_map<TreeNode*,bool> isBurning;
    parent[root]=nullptr;
    setParent(root,parent);

    TreeNode *t=findTarget(root,target);
    int ans=0;
    queue<TreeNode*> q;
    q.push(t);
    isBurning[t]=true;
    q.push(nullptr);
    while(!q.empty()){
        TreeNode *front=q.front();
        q.pop();
        if(!front){
            ans++;
            if(!q.empty())  q.push(nullptr);
        }
        else{
            if(parent[front] && !isBurning[parent[front]]){
                q.push(parent[front]);
                isBurning[parent[front]]=true;
            }
            if(front->left && !isBurning[front->left]){
                q.push(front->left);
                isBurning[front->left]=true;
            }
            if(front->right && !isBurning[front->right]){
                q.push(front->right);
                isBurning[front->right]=true;
            }
        }
    }
    return ans-1;
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
    int target;
    cout<<"Enter Target : ";
    cin>>target;
    cout<<minTime(root,target);
    return 0;
}