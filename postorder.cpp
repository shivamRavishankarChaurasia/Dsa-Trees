// Iterative approch using 2 and 1 stack
// Using 2 Stack 
#include<bits/stdc++.h>
using namespace std;
vector<int>iterativePostorder(TreeNode* root){
vector<int>postorder;
if(root==NULL){
    return postorder;

}
stack<TreeNode*>s1,s2;
s1.push(root);
while(!s1.empty()){
    root=s1.top();
    s1.pop();
    s2.push_back(root);
    if(root->left!=NULL){
        s1.push(root->left);

    }
    if(root->right!=NULL){
        s2.push(root->right);
    }
}
while(!s2.empty()){
    postorder.push_back(s2.top()->val);
    s2.pop();

}
return postorder;
}
int main(){
    return 0;
}
