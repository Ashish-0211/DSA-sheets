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
        insertIntoBST(root, data);
    cin >> data;
}
vector<vector<int>> levelOrder(Tnode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<Tnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size--)
        {
            Tnode *node = q.front();
            temp.push_back(node->data);
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    Tnode *root = nullptr;
    cout << "Enter data to create BST :"
         << "\n";
    takeInput(root);
    cout << "Level order traversal of the tree :"
         << "\n";
    vector<vector<int>> level = levelOrder(root);
    print(level);
    return 0;
}