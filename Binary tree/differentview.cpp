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
        this->left = left;
        this->right = right;
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
        return nullptr;
    cout << "Enter the value for inserting in left :"
         << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the value for inserting in right :"
         << "\n";
    root->right = buildTree(root->right);
    return root;
}
vector<int> topview(Tnode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> mp;
    queue<pair<Tnode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Tnode *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
            mp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
        ans.push_back(it.second);

    return ans;
}
vector<int> bottomview(Tnode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> mp;
    queue<pair<Tnode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Tnode *node = it.first;
        int line = it.second;
        mp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto i : mp)
        ans.push_back(i.second);

    return ans;
}
vector<int> rightview(Tnode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Tnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Tnode *node = q.front();
            q.pop();
            if (i == n - 1)
                ans.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
}
vector<int> leftview(Tnode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Tnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Tnode *node = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main()
{
    Tnode *root = NULL;
    root = buildTree(root);
    vector<int> leftView, rightView, topView, bottomView;
    cout << "topview :"
         << "\n";
    topView = topview(root);
    print(topView);
    cout << "Bottom view :"
         << "\n";
    bottomView = bottomview(root);
    print(bottomView);
    cout << "Right view :"
         << "\n";
    rightView = rightview(root);
    print(rightView);
    cout << "Left view :"
         << "\n";
    leftView = leftview(root);
    print(leftView);
    return 0;
}