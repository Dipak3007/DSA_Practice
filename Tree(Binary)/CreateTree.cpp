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

TreeNode* createTree(){
    int x;
    cout<<" Enter Data (-1 for NULL) : ";
    cin>>x;
    if(x==-1)   return nullptr;
    TreeNode *temp=new TreeNode(x);
    cout<<"Left of "<<x;
    temp->left=createTree();
    cout<<"Right of "<<x;
    temp->right=createTree();
    return temp;
}

int main(){
    TreeNode *root=createTree();
    return 0;
}