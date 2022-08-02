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
    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);
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
bool validate(Tnode *root, int min, int max)
{
    if (!root)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return validate(root->left, min, root->data - 1) and validate(root->right, root->data + 1, max);
}
bool checkBST(Tnode *root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return validate(root, min, max);
}
int main()
{
    Tnode *root = nullptr;
    cout << "Enter the value to be inserted in the bst :"
         << "\n";
    takeInput(root);
    if (checkBST(root))
        cout << "IT is a valid bst "
             << "\n";
    else
        cout << "Not a valid bst "
             << "\n";
    return 0;
}