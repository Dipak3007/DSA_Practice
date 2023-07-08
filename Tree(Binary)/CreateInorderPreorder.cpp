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
    inorder = 3 5 6 10 12 11
    preorder = 10 5 3 6 11 12

    Output (Level Order)
    10
    5 11
    3 6 12

           10
          /  \
         5    11
        /\    /
       3  6  12
*/

//Tree Creation using inorder and preorder traversals
TreeNode* createTree(unordered_map<int,int> inMap,vector<int> preorder,int &preIndex,int inStart,int inEnd){
    if(preIndex==preorder.size() || inStart>inEnd)  return nullptr;

    int x=preorder[preIndex++],pos=inMap[x];
    TreeNode* temp=new TreeNode(x);
    temp->left=createTree(inMap,preorder,preIndex,inStart,pos-1);
    temp->right=createTree(inMap,preorder,preIndex,pos+1,inEnd);
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
    vector<int> inorder={3,5,6,10,12,11},preorder={10,5,3,6,11,12};
    int preIndex=0,i;
    unordered_map<int,int> inMap;   //stores inorder index of each element
    for(i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;
    TreeNode *root=createTree(inMap,preorder,preIndex,0,inorder.size()-1);
    cout<<"Level order of tree formed :-\n";
    levelOrder(root);
    return 0;
}