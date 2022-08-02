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
Tnode *buildTree(Tnode *root)
{
    cout << "Enter the value of the node :"
         << "\n";
    int data;
    cin >> data;
    root = new Tnode(data);
    if (data == -1)
        return nullptr;
    cout << "Enter the value to be inserted in the left of :" << data << "\n";
    root->left = buildTree(root->left);
    cout << "Enter the value to be inserted in the right of :" << data << "\n";
    root->right = buildTree(root->right);
    return root;
}
void allTraversal(Tnode *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    stack<pair<Tnode *, int>> st;
    st.push({root, 1});
    if (root == nullptr)
        return;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else
        {
            postorder.push_back(it.first->data);
        }
    }
}
void print(vector<int> v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main()
{
    Tnode *root = nullptr;
    root = buildTree(root);
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    allTraversal(root, preorder, inorder, postorder);
    cout << "Preorder of the tree is :"
         << "\n";
    print(preorder);
    cout << "Inorder of the tree is :"
         << "\n";
    print(inorder);
    cout << "Postorder of the tree is :"
         << "\n";
    print(postorder);
    return 0;
}