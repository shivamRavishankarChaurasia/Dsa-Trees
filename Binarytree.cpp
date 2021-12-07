#include <iostream>
#define SPACE 10

using namespace std;
class TreeNode
{
public:
    int value; //data,key
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
    bool isTreeEmpty()
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
    // Insertion of a node
    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Node Inserted as a root node " << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value already exit ,"
                         << "Insert another value !" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Node Inserted at the left !" << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted at the right!" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
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

    void printPreOrder(TreeNode *r) //node-left-right
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->value << "  ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }
    void printInOrder(TreeNode *r) //left-node-right
    {
        printInOrder(r->left);
        cout << r->value << " ";
        printInOrder(r->right);
    }
    void printPostOrder(TreeNode *r)
    {
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->value << " ";
    }

    // Searching a Node in the Tree
    TreeNode *iterativeSearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
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
            int lHeight = height(r->left);
            int rHeight = height(r->right);
            if (lHeight > rHeight)
            {
                return (lHeight + 1);
            }
            else
            {
                return (lHeight + 1);
            }
        }
    }

    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->value << " ";
        }
        else
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r, i);
        }
    }

    // Deleting a node in BST
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    TreeNode *DeleteNode(TreeNode *r, int v)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (v < r->value)
        {
            r->left = DeleteNode(r->left, v);
        }
        else if (v > r->value)
        {
            r->right = DeleteNode(r->right, v);
        }
        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = DeleteNode(r->right, temp->value);
            }
        }
        return r;
    }
};

int main()
{
    BST obj;
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
            cout << "Insert" << endl;
            cout << "Enter value of tree node to search in BST:" << endl;
            cin >> val;
            new_node->value = val;
            obj.root=obj.insertRecursive(obj.root,new_node);
            // obj.insertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "Search" << endl;
            cout << "Enter the value of node to search :";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                cout << "Value found " << endl;
            }
            else
            {
                cout << "Value not found " << endl;
            }
            break;

        case 3:
            cout << "Delete" << endl;
            cout << "Enter the value that has to be deleted in BST :" << endl;
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.DeleteNode(obj.root, val);
                cout << "Value deleted" << endl;
            }
            else
            {
                cout << "Value not found " << endl;
            }

            break;
        case 4:
            cout << "Print2D :" << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print LevelOrder BFS :" << endl;
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            cout << "PRE-ORDER: ";
            obj.printPreOrder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.printInOrder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.printPostOrder(obj.root);

            break;
        case 5:
            cout << "Tree Height " << endl;
            cout << "Height :" << obj.height(obj.root) << endl;

            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter the proper Option Number " << endl;
        }

    } while (option != 0);

    return 0;
}
