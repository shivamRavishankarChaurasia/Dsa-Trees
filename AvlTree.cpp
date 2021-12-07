#include <iostream>
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};
class AVL
{
public:
    TreeNode *root;
    AVL()
    {
        root = NULL;
    }
    bool isEmpty()
    {
        if (root = NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int height(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            lHeight = height(r->left);
            rHeight = height(r->right);
        }
        if (height > rHeight)
        {
            return (lHeight + 1);
        }
        else
        {
            return (rHeight + 1);
        }
    }
    // get balance factor function of Node N
    int getBalanceFactor(TreeNode *n)
    {
        if (n == NULL)
        {
            return -1;
        }
        else
        {
            return (height(n->left) - height(n->right));
        }
    }
    // rightrotaate function 
    TreeNode *rightRotate(TreeNode *y)
    {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;
        // Perform Rotation
        x->right = y;
        y->left = T2;
        return x;
    }
    // leftrotaate function 
    TreeNode *leftRotate(TreeNode *x)
    {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;
        // Perform Rotation
        y->left = x;
        x->right = T2;
        return y;
    }
    TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            return r;
        }
        if (new_node->value < r->value)
        {
            r->left = insertRecursive(r->left, new_node);
        }
        else if (new_node->value > r->value)
        {
            r->right = insertRecursive(r->right, new_node);
        }
        else
        {
            cout << "No duplicated are allowed!" << endl;
        }
        return r;
    }

    int bf = getBalanceFactor(r);
    if((bf > 1 && new_node->value < r->left->value))
    {
        return rightRotate(r);
    }
    if((bf < -1) && (new_node->value > r->right->value))
    {
        return leftRotate(r);
    }
    if ((bf > 1) && (new_node->value > r->left->value))
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if ((bf < -1) && (new_node->value < r->right->value))
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space = space + SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << "  ";
        }
        cout << r->value << "\n";
        print2D(r->left, space);
    }
};

int main()
{
    AVL obj;
    int option, val;
    do
    {
        cout << "What operation do you want to perform ? "
             << "Select Option Number .Enter 0 to exit." << endl;
        cout << "1.Insert Node" << endl;
        cout << "2.Search Node" << endl;
        cout << "3.Delete Node" << endl;
        cout << "4.Print BST values" << endl;
        cout << "5.Height of the tree " << endl;
        cout << "6.Clear Screen" << endl;
        cout << "0.Exit Program" << endl;
        cin >> option;
        TreeNode *new_node = new TreeNode();
        switch (option)
        {
        case 1:

            break;
        
        default:
            break;
        }
    return 0;
}