// To check wheather the tree is balanced or not 
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
int heightOfTree(node* root){
    if(root==NULL){
        return 0;
    }
    int leftH=heightOfTree(root->left);
    if(leftH==-1) return -1;
    int rightH=heightOfTree(root->right);
    if(rightH==-1) return -1;

    if(abs(leftH-rightH)>1) return -1;
    return max(leftH,rightH)+1;

}
bool checkBalanced(node* root){
   if(heightOfTree(root)==-1){
       return false;
   }
}
int main(){
    struct node* root=new node(3);
    root->left=new node(9);
    root->right=new node(20);
    root->right->left =new node(15);
    root->right->right=new node(7);
    heightOfTree(root);
    return 0;

}
