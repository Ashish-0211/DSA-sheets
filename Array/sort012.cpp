#include <bits/stdc++.h>
using namespace std;
void sort012(vector<int> &v)
{
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    while (mid <= high)
    {
        switch (v[mid])
        {
        case 0:
            swap(v[low++], v[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(v[mid], v[high--]);
            break;
        }
    }
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    cout << "enter the value sin the vector :"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "array after sorting :"
         << "\n";
    sort012(v);
    print(v);
    return 0;
}