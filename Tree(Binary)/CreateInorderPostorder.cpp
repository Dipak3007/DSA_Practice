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
    inorder = 4 8 2 5 1 6 3 7
    postorder = 8 4 5 2 6 7 3 1

    Output (Level Order)
    1
    2 3
    4 5 6 7
    8

            1
          /   \
         2     3
        / \   / \
       4   5  6  7
        \
         8
*/

//Tree Creation using inorder and postorder traversals
TreeNode* createTree(unordered_map<int,int> inMap,vector<int> postorder,int &postIndex,int inStart,int inEnd){
    if(postIndex<0 || inStart>inEnd)  return nullptr;

    int x=postorder[postIndex--],pos=inMap[x];
    TreeNode* temp=new TreeNode(x);
    temp->right=createTree(inMap,postorder,postIndex,pos+1,inEnd);
    temp->left=createTree(inMap,postorder,postIndex,inStart,pos-1);
    return temp;
}

void levelOrder(TreeNode *root){
    if(root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                cout<<"\n";
                if(!q.empty())  q.push(nullptr);
            }
            else{
                cout<<temp->val<<" ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
    }
}

int main(){
    vector<int> inorder={4,8,2,5,1,6,3,7},postorder={8,4,5,2,6,7,3,1};
    int postIndex=inorder.size()-1,i;
    unordered_map<int,int> inMap;   //stores inorder index of each element
    for(i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;
    TreeNode *root=createTree(inMap,postorder,postIndex,0,inorder.size()-1);
    cout<<"Level order of tree formed :-\n";
    levelOrder(root);
    return 0;
}