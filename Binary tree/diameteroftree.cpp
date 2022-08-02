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
        this->left = NULL;
        this->right = NULL;
    }
};
Tnode *buildTree(Tnode *root)
{
    cout << "Enter the value of the data to be inserted in node :"
         << "\n";
    int data;
    cin >> data;
    root = new Tnode(data);
    if (data == -1)
        return nullptr;
    cout << "Enter the value to be inserted in the left of the node :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the value to be inserted in the right of the node :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
int height(Tnode *root, int &diameter)
{
    if (!root)
        return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    int sumOfHeight = lh + rh;
    diameter = max(diameter, sumOfHeight);
    return 1 + max(lh, rh);
}
int diameterOfTree(Tnode *root)
{
    if (!root)
        return 0;
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int main()
{
    Tnode *root = NULL;
    root = buildTree(root);
    int diameter = diameterOfTree(root);
    cout << "The diameter of the tree :"
         << "\n";
    cout << diameter << "\n";
    return 0;
}