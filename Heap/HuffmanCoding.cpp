#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class comp{
public:
    bool operator()(TreeNode* a,TreeNode* b){
        return a->val > b->val;
    }
};

void preOrder(TreeNode*root,string temp,vector<string> &ans){
    if(!root->left && !root->right){
        ans.emplace_back(temp);
        return;
    }
    preOrder(root->left,temp+"0",ans);
    preOrder(root->right,temp+"1",ans);
}

void huffmanCodes(string S,vector<int> f,int N) {
	priority_queue<TreeNode*,vector<TreeNode*>,comp> minHeap;
	for(int i=0;i<N;i++)    minHeap.push(new TreeNode(f[i]));
	while(minHeap.size()>1){
		TreeNode *left=minHeap.top();
        minHeap.pop();
        TreeNode *right=minHeap.top();
        minHeap.pop();
        minHeap.push(new TreeNode(left->val+right->val,left,right));
    }
		    
    TreeNode *root=minHeap.top();
    vector<string> ans;
    preOrder(root,"",ans);
    for(string i:ans)
        cout<<i<<"\n";
}

int main(){
    string s="abcdef";
    vector<int> freq={5,9,12,13,16,45};
    cout<<"Huffman code in order of preorder traversal :-\n";
    huffmanCodes(s,freq,s.length());
    return 0;
}