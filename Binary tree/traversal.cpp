#include <bits/stdc++.h>
using namespace std;
class Tnode
{
public:
    int data;
    Tnode *left, *right;
    Tnode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Tnode *buildTree(Tnode *root)
{
    cout << "Enter the data :"
         << "\n";
    int data;
    cin >> data;
    root = new Tnode(data);
    if (data == -1)
        return NULL;
    cout << "Enter data for inserting in left of :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
vector<vector<int>> levelOrder(Tnode *root)
{
    vector<vector<int>> levels;
    if (!root)
        return levels;

    queue<Tnode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Tnode *node = q.front();
            temp.push_back(node->data);
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        levels.push_back(temp);
    }
    return levels;
}
void inorder(vector<int> &in, Tnode *root)
{
    if (!root)
        return;

    inorder(in, root->left);
    in.push_back(root->data);
    inorder(in, root->right);
}
void preorder(vector<int> &pre, Tnode *root)
{
    if (!root)
        return;
    pre.push_back(root->data);
    preorder(pre, root->left);
    preorder(pre, root->right);
}
void postorder(vector<int> &post, Tnode *root)
{
    if (!root)
        return;
    postorder(post, root->left);
    postorder(post, root->right);
    post.push_back(root->data);
}
vector<vector<int>> verticalTraversal(Tnode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    vector<vector<int>> vertical;
    queue<pair<Tnode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Tnode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->data);
        if (node->left)
            q.push({node->left, {x - 1, y + 1}});

        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }
    for (auto it : nodes)
    {
        vector<int> col;
        for (auto i : it.second)
        {
            col.insert(col.end(), i.second.begin(), i.second.end());
        }
        vertical.push_back(col);
    }
    return vertical;
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
void printlevel(vector<vector<int>> level)
{
    for (int i = 0; i < level.size(); i++)
    {
        for (int j = 0; j < level[i].size(); j++)
            cout << level[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    Tnode *root = NULL;
    root = buildTree(root);
    cout << "level order traversal :"
         << "\n";
    vector<vector<int>> level = levelOrder(root);
    printlevel(level);
    vector<int> in, pre, post;
    cout << "inorder traversal :"
         << "\n";
    inorder(in, root);
    print(in);
    cout << "Preorder traversal :"
         << "\n";
    preorder(pre, root);
    print(pre);
    cout << "Postorder traversal :"
         << "\n";
    postorder(post, root);
    print(post);
    cout << "Vertical order traversal :"
         << "\n";
    vector<vector<int>> vertical = verticalTraversal(root);
    printlevel(vertical);
    return 0;
}