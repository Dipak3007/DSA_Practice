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

void levelOrder(TreeNode *root){
    if(root){
        queue<TreeNode*> q;
        q.push(root);           //root is sent to queue
        q.push(nullptr);        //seperator in queue indicating end of Level 0
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                cout<<"\n";
                if(!q.empty())  q.push(nullptr);
                /*
                    Every nullptr(seperator) indicates that all children are pushed into queue.
                    Thus, next level is completed, thus a seperator(nullptr) is pushed into queue.
                */
            }
            else{
                cout<<temp->val<<" ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
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
    cout<<"\nLevel Order\n";
    levelOrder(root);
    return 0;
}