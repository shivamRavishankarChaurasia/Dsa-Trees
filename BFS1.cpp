#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        data=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int d){
        data=d;
        left=NULL;
        right=NULL;

    }
}
vector<vector<int>>levelOrder(TreeNode* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* current = q.front();
            q.pop();
            if(node->left!=NULL ) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);

        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    return 0;
}