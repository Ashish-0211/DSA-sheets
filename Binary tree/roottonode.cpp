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
        this->data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Tnode *buildTree(Tnode *root)
{
    cout << "Enter the value to be inserted in node :"
         << "\n";
    int data;
    cin >> data;
    root = new Tnode(data);
    if (data == -1)
        return nullptr;
    cout << "Enter the left of the node :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the right of the node :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
bool getPath(Tnode *root, vector<int> &path, int node)
{
    if (!root)
        return false;
    path.push_back(root->data);

    if (node == root->data)
        return true;

    if (getPath(root->left, path, node) || getPath(root->right, path, node))
        return true;
    path.pop_back();
    return false;
}
void print(vector<int> v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << "\n";
}
int main()
{
    Tnode *root = nullptr;
    root = buildTree(root);
    int node;
    cin >> node;
    vector<int> path;
    bool res = getPath(root, path, node);
    cout << "The path of the root to node " << node << "\n";
    print(path);
    return 0;
}