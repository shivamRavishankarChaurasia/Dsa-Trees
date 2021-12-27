#include<iostream>
#define SPACE 5;
using namespace std;
class TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int val){
        value=val;
        left=NULL;
        right=NULL;
    }
};
class BinarySearchClass {
    public:
    TreeNode* root;
    BinarySearchClass(){
        root=NULL;

    }
    // isEmpty() function 
     bool isTreeEmpty(){
         if(root==NULL){
             return true;

         }
         else{
             return false;
         }
     }
    //  Insert Function 
     void insertANode(TreeNode* n){
         if(root==NULL){
             root=n;
             cout<<"Inserted as a root node "<<endl;
         }
         else{
            TreeNode* temp = root;
             while(temp!=NULL){
                 if(n->value==temp->value){
                     return;
                     cout<<"Value exist of the same value "<<"Enter other value "<<endl;
                 }
                 else if((n->value<temp->value) && (temp->left==NULL)){
                     temp->left=n;
                     cout<<"Value inserted at the left "<<endl;
                     break;
                 }
                 else if(n->value<temp->value){
                    temp=temp->left;
                 }
                 else if((n->value>temp->value)&&(temp->right==NULL)){
                     cout<<"Value inserted at the right "<<endl;
                     temp->right=n;

                 }
                 else{
                     temp=temp->right;
                 }
             }
         }
     }
    //  print tree function 
    void print2D(TreeNode* r ,int space ){
        if(r==NULL)  //BaseCase condition 
            return;
        space = space+SPACE; //Increase distance levels
        print2D(r->right,space ); //Process right child 
        cout<<endl;
        for (int i = SPACE; i < space ; i++)
        {
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print2D(r->left,space);  //Process left child 
        
        
    }
    //  PreOrder Traversal
     void PreOrder(TreeNode* r){
         if(r==NULL){
             return;
         }
         else{

             cout<<r->value<<" ";
            //  Recursive call on left subtree
             PreOrder(r->left);
            //  Recursive call on the right subtree;
             PreOrder(r->right);
         }


     }
    //  Inorder function
     void inOrder(TreeNode* r){
         if(r==NULL){
             return;
         }
         inOrder(r->left);
         cout<<r->value<<" ";
         inOrder(r->right);
     }
    //  Postorder function 
     void postOrder(TreeNode* r){
         if(r==NULL){
             return;
         }
         postOrder(r->left);
         postOrder(r->right);
         cout<<r->value<<" ";
     }
    // Seach function
     TreeNode* searchANode(int val){
         if(r==NULL){
             return;
         }
         else{
             TreeNode* temp=root;
             while(temp!=NULL){
                 if(val==temp->value){
                     return temp;
                 }
                 else if(val<temp->value){
                     temp=temp->left;
                 }
                 else{
                     temp=temp->right;
                 }
             }
             return NULL;
         }
     }
    //Height of the tree
    TreeNode* height(TreeNode* r){
        if(root==NULL){
            return -1;

        }
        else{
            lheight=height(r->left);
            rheight=height(r->right);
            if(lheight>rheight){
                return (lheight+1);
            }
            else{
                return (rheight+1);
            }
        }
    }
    void BFS(TreeNode* r){
        h=height(r);
        for(int i=0;i<=h;i++){
            printLevelOrder(r,i);
        }
    }
    void printLevelOrder(TreeNode* r ,int level){
        if(r==NULL){
            return;
        }
        else{
            if(level==0){
                cout<<level->val<<" ";
            }
            else{
                printLevelOrder(r->left,level-1);
                printLevelOrder(r->right,level-1);
            }
        }
    }
};
int main(){
    BinarySearchClass obj;
    int option,v;
    do{
        cout<<"What are the operation do you want to perform ?"<<"select Option number .Enter 0 to exit ."<<endl;
        cout<<"1.Insert a Node "<<endl;
        cout<<"2.Search Node "<<endl;
        cout<<"3.Delete Node"<<endl;
        cout<<"4.Print BST values "<<endl;
        cout<<"5.Clear Screen "<<endl;
        cout<<"6.Exit Program "<<endl;
        // In the heap memory a object of TreeNode is created and in stack memory a pointer of TreeNode is Created and point to object in heap memory
        // heap is related to dynamic memory allocation
     cin>>option;
           TreeNode* new_node = new TreeNode();   //Have global scope and use throughout these program
     switch(option){
         case 0:
         break;
         case 1:
         cout<<"INSERT"<<endl;
         cout<<"Enter the value of tree node to insert in BST  :";
         cin>>v;
         new_node->value=v;
         obj.insertANode(new_node);
         cout<<endl;
         break;
         case 2:
         cout<<"SEARCH"<<endl;
         cout<<"Enter the value of the tree Node to Search in BST : "<<endl;
         cin>>v;
         new_node= obj.searchANode(v);
         if(new_node!=NULL){
             cout<<"Value found "<<endl;
         }
         else{
             cout<<"Value not found "<<endl;
         }
         break;
         case 3:
         cout<<"DELETE"<<endl;
         break;
         case 4:
         cout<<"PRINT"<<endl;
         obj.print2D(obj.root,5);
         obj.PreOrder(obj.root);

         break;
         case 5:
         cout<<"HEIGHT OF THE TREE "<<endl;
         cout<<"Height : "<<obj.height(obj.root)<<endl;
         break;
         case 6:
         system("cls");
         break;
         default:
         cout<<"ENter the proper Option number "<<endl;

         

    

        

     }

    }while(option!=0);
    return 0;
}