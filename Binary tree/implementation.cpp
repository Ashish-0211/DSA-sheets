#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
TreeNode *buildTree(TreeNode *&root)
{
    cout << "Enter the data :"
         << "\n";
    int data;
    cin >> data;
    root = new TreeNode(data);
    if (data == -1)
        return nullptr;
    cout << "Enter data for inserting in left of :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> level;
    if (!root)
        return level;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            temp.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        level.push_back(temp);
    }
    return level;
}
void inOrder(vector<int> &inorder, TreeNode *root)
{
    if (!root)
        return;
    inOrder(inorder, root->left);
    inorder.push_back(root->data);
    inOrder(inorder, root->right);
}
void preOrder(vector<int> &preorder, TreeNode *root)
{
    if (!root)
        return;

    preorder.push_back(root->data);
    preOrder(preorder, root->left);
    preOrder(preorder, root->right);
}
void postOrder(vector<int> &postorder, TreeNode *root)
{
    if (!root)
        return;
    postOrder(postorder, root->left);
    postOrder(postorder, root->right);
    postorder.push_back(root->data);
}
void printDfs(vector<int> &traversal)
{
    int size = traversal.size();
    for (int i = 0; i < size; i++)
        cout << traversal[i] << " ";

    cout << "\n";
}
void printBfs(vector<vector<int>> &traversal)
{
    int size = traversal.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < traversal[i].size(); j++)
            cout << traversal[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    TreeNode *root = nullptr;
    root = buildTree(root);
    vector<vector<int>> level = levelOrder(root);
    cout << "Level order traversal is :"
         << "\n";

    for (int i = 0; i < level.size(); i++)
    {
        for (int j = 0; j < level[i].size(); j++)
            cout << level[i][j] << " ";

        cout << "\n";
    }
    printBfs(level);
    vector<int>
        preorder, postorder, inorder;
    inOrder(inorder, root);
    preOrder(preorder, root);
    postOrder(postorder, root);
    cout << "Inorder traversal"
         << "\n";
    printDfs(inorder);
    cout << "Postorder traversal"
         << "\n";
    printDfs(postorder);
    cout << "Preorder traversal"
         << "\n";
    printDfs(preorder);
    return 0;
}
