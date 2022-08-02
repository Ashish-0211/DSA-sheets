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
        this->left = left;
        this->right = right;
    }
};
Tnode *buildTree(Tnode *root)
{
    cout << "Enter value of node :"
         << "\n";
    int data;
    cin >> data;
    root = new Tnode(data);
    if (data == -1)
        return nullptr;
    cout << "Enter the value of the left node of :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the value of the right node of :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
int widthOfTree(Tnode *root)
{
    if (!root)
        return 0;
    int width = 0;
    queue<pair<Tnode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int currMin = q.front().second;
        int leftmost = 0, rightmost = 0;
        for (int i = 0; i < size; i++)
        {
            Tnode *node = q.front().first;
            int curr_id = q.front().second - currMin;
            q.pop();
            if (i == 0)
                leftmost = curr_id;
            if (i == size - 1)
                rightmost = curr_id;
            if (node->left)
                q.push({node->left, curr_id * 2 + 1});
            if (node->right)
                q.push({node->right, curr_id * 2 + 2});
        }
        width = max(width, rightmost - leftmost + 1);
    }
    return width;
}
int main()
{
    Tnode *root = nullptr;
    root = buildTree(root);
    int width = widthOfTree(root);
    cout << "Width of the tree is :"
         << "\n";
    cout << width << "\n";
    return 0;
}
