#include <bits/stdc++.h>
using namespace std;
class Tnode
{
public:
    int data;
    Tnode *left;
    Tnode *right;
    Tnode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Tnode *insertIntoBST(Tnode *&root, int data)
{
    if (!root)
    {
        root = new Tnode(data);
        return root;
    }
    if (root->data < data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
        root->left = insertIntoBST(root->left, data);
}
void takeInput(Tnode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}
bool searchNode(Tnode *root, int data)
{
    if (!root)
        return false;
    if (root->data == data)
        return true;
    if (root->data < data)
        searchNode(root->right, data);

    else
        searchNode(root->left, data);
}
int main()
{
    Tnode *root = nullptr;
    cout << "Enter value to create th bst :"
         << "\n";
    takeInput(root);
    cout << "Search a node in the bst :"
         << "\n";
    int node = 0;
    cin >> node;
    if (searchNode(root, node))
        cout << "Node found "
             << "\n";
    else
    {
        cout << "Node not found"
             << "\n";
    }

    return 0;
}