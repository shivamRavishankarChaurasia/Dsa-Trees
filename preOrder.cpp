// Iterative code for preorder traversal using stack
#include<bits/stdc++.h>
using namespace std;
// A binary tree Node has value , left , right child
struct node{
    int data;
    struct node* left;
    struct node*  right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
// struct node* new_node(int data){
// struct node* node= new struct node;
// node->data=data;
// node->left=NULL;
// node->right=NULL;
// return (node);

// }
/* vector<vector<int>>preOrder(node* root){
    vector<vector<int>>preorder;
    if(root==NULL){
        return preorder;
    }
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()){
        root=s.top();
        s.pop();
        preorder.push_back(root->val);
        if(root->right!=NULL){
            s.push(root->right);
        }
        if(root->left!=NULL){
            s.push(root->left);
        }
    }
    return preorder;

} */

void iterativepreOrder(node* root){
    if(root==NULL){
        return;
    }
    stack<node*>s1;
    s1.push(root);
    while(!s1.empty()){
        struct node* node  = s1.top();
        cout<<node->data<<" ";
        s1.pop();
        if(node->right!=NULL){
            s1.push(node->right);
        }
        if(node->left!=NULL){
            s1.push(node->left);
        }
    }
}
int main(){
    /* struct node* root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2); */
    struct node* root = new_node(10);
    root->left = new_node(8);
    root->right = new_node(2);
    root->left->left = new_node(3);
    root->left->right = new_node(5);
    root->right->left = new_node(2);
    iterativepreOrder(root);
    return 0;
}