#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int value;
    TreeNode* right;
    TreeNode* left;
    TreeNode(){
        value=0;
        right=NULL;
        left=NULL;

    }
    TreeNode* (int v){
         value=v;
        right=NULL;
        left=NULL;
    }
};
class BST{
    public:
    TreeNode* root;
    BST(){
        root=NULL;
    }

    // Insert a node in the tree;
    void insertANode(TreeNode* new_node){
        if(root==NULL){
            root=new_node;
        }
        else{
            TreeNode*temp=root;
            while(temp!=NULL){
                if(temp->val==new_node->val){
                    return;

                }
                else if((temp->val>new_node->val) && (temp->left==NULL)){
                      temp->left=new_node;
                }
                else if(temp->val>new_node->val){
                   temp=temp->left;
                }
                else if((temp->val<new_node->val) && (temp->right==NULL){
                    temp->right=new_node;
                }
                else{
                    temp=temp->right;
                }
            }

        }
    }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(0);
    root->right= new TreeNode(5);
    root->left= new TreeNode()

    return 0;
}