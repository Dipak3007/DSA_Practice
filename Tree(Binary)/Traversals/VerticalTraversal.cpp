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


    Output          Horizontalal Distance from root
    8                           -3
    4                           -2
    2 9 10                      -1
    1 5 6                        0
    3                            1
    7                            2
    11                           3
*/

void getKey(TreeNode* root,int key,unordered_map<TreeNode*,int> &horiDist){
    if(root){
        horiDist[root]=key;
        getKey(root->left,key-1,horiDist);
        getKey(root->right,key+1,horiDist);
    }
}

void verticalOrder(TreeNode *root){
    unordered_map<TreeNode*,int> horiDist;
    getKey(root,0,horiDist);
    map<int,vector<int>> m;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        m[horiDist[temp]].emplace_back(temp->val);
        if(temp->left)  q.push(temp->left);
        if(temp->right)  q.push(temp->right);
    }

    for(auto i:m){
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
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
    cout<<"\nVertical Order\n";
    verticalOrder(root);
    return 0;
}