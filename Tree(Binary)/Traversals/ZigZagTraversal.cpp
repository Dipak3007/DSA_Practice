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
    1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

            1
          /   \
         2     4
        / \     \
       3   5     7
          / \     \
         6   8     9
                  / \
                 10  11

    Output
    1
    4 2
    3 5 7
    9 8 6
    10 11
*/

void zigZagLevelOrder(TreeNode* root){
    if(root){
        vector<int> ans;
        queue<TreeNode*> q;
        bool left=true;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                if(!left){
                    for(int i=ans.size()-1;i>=0;i--)     cout<<ans[i]<<" ";
                    left=true;
                }
                else{
                    for(int i:ans)  cout<<i<<" ";
                    left=false;
                }
                cout<<"\n";
                ans.clear();
                if(!q.empty())  q.push(nullptr);
            }
            else{
                ans.emplace_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
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
    cout<<"\nZig Zag Level Order\n";
    zigZagLevelOrder(root);
    return 0;
}