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
    2                           -1
    1                            0
    3                            1
    7                            2
    11                           3

    Top node from each column
*/

void topView(TreeNode *root){
    map<int,int> horiDist;

    queue<pair<TreeNode*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<TreeNode*,int> temp=q.front();
        q.pop();
        if(!horiDist[temp.second])  horiDist[temp.second]=temp.first->val;
        if(temp.first->left)  q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right)  q.push(make_pair(temp.first->right,temp.second+1));
    }

    for(auto i:horiDist)
            cout<<i.second<<" ";
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
    cout<<"\nTop View\n";
    topView(root);
    return 0;
}