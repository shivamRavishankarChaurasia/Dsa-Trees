// Preorder,inoder,postorder traversal using stack
#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    struct node* left;
    struct node* right;
    node(int val){
        value=val;
        left=NULL;
        right=NULL;
    }
};
vector<int>preposinoTraversal(node* root){
    stack<pair<node*,int>>s;
    s.push({root,1});
    vector<int>pre,post,ino;
    while(!s.empty()){
        auto temp=s.top();
        s.pop();
        // This is for preorder
        if(temp.second==1){
            pre.push_back(temp.first->value);
            temp.second++;
            s.push(temp);
            
            if(temp.first->left!=NULL){
             s.push({temp.first->left,1});
            }
        }
        else if(temp.second==2){
            ino.push_back(temp.first->value);
            temp.second++;
            s.push(temp);
            if(temp.first->right!=NULL){
                s.push({temp.first->right,1});
            }
        }
        else{
            post.push_back(temp.first->value);
        }
    }
    return pre;
}
int main(){
     struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left = new node(3);
    root->left->right=new node(4);
    root->right->left =new node(6);
    root->right->right=new node(7);
    preposinoTraversal(root);
    return 0;
}