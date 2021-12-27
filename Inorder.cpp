#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>inOrder(TreeNode* root){
    vector<int>inorder;
    if(root==NULL){
        return inorder;

    }
    stack<TreeNode*>s;
    TreeNode* node = root;
    while(true){
        if(node!=NULL){
            s.push(node);
            node=node->left;
        }
        else{
            if(s.empty()==true) break;
            node=s.top();
            s.pop();
            inorder.push_back(node->val);
            node=node->right;

        }
    }
    return inorder
}
int main(){
    return 0;

}