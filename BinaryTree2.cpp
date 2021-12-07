// Binary Tree Insertion in  recursive way
/*
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
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    TreeNode *root;

    BST()
    {
        root = NULL;
    }
    bool isEmptyTree()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
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
            cout << "No duplicated are allowed" << endl;
            return r;
        }
        return r;
    }
};
int main()
{
    int val;
    TreeNode *new_node = new TreeNode();
    Treenode *new_node = TreeNode(1);
    root->left = TreeNode(2);
    root->right = TreeNode(3);
    root->left->left = TreeNode(4);
    root->left->right = TreeNode(5);
    BST obj1;
   
    cin >> val;
    new_node->value = val;
    obj1.root = obj1.insertRecursive(obj1.root, new_node);
    cout << endl;

    return 0;
}
*/
// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/* Function to create a new node */

Node *CreateNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert element in binary tree */

Node *InsertNode(Node *root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// Driver code
int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = InsertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}