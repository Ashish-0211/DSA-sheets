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
    cout << "Enter th value to be added in the node :"
         << "\n";
    int data;
    cin >> data;
    Tnode *root = new Tnode(data);
    if (data == -1)
        return NULL;
    cout << "Enter the value to be inserted in the left :"
         << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the value to be inserted in the right :"
         << "\n";
    root->right = buildTree(root->right);
    return root;
}
int heightOfTreeDfs(Tnode *root)
{
    if (!root)
        return 0;
    int leftTree = heightOfTreeDfs(root->left);
    int rightTree = heightOfTreeDfs(root->right);

    return 1 + max(leftTree, rightTree);
}
int heightOfTreeBfs(Tnode *root)
{
    int height = 0;
    if (!root)
        return height;
    queue<Tnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Tnode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        height++;
    }
    return height;
}
int main()
{
    Tnode *root = NULL;
    root = buildTree(root);
    cout << "Height of the tree using dfs is :"
         << "\n";
    int height = heightOfTreeDfs(root);
    cout << height << "\n";
    int heightbfs = heightOfTreeBfs(root);
    cout << "Height of the tree using bfs is:"
         << "\n";
    cout << heightbfs << "\n";
    return 0;
}