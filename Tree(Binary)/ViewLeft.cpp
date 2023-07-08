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


    Output
    1 2 4 8
    Left-Most node from each level
*/

void leftView(TreeNode *root){
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    int level=0;
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(!temp){
            level++;
            if(!q.empty())  q.push(nullptr);
        }
        else{
            if(level==ans.size())   ans.emplace_back(temp->val);
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }
    }

    for(auto i:ans)
            cout<<i<<" ";
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
    cout<<"\nLeft View\n";
    leftView(root);
    return 0;
}