#include <bits/stdc++.h>
using namespace std;
int removeDuplicate(vector<int> &v)
{
    int i = 0;
    int n = v.size();
    for (int j = 1; j < n; j++)
    {
        if (v[i] != v[j])
        {
            i++;
            v[i] = v[j];
        }
    }
    return i + 1;
}
void print(vector<int> v, int k)
{
    for (int i = 0; i < k; i++)
        cout << v[i] << " ";
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the values in the array :"
         << "\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k = removeDuplicate(v);
    cout << "After the operation :"
         << "\n";
    print(v, k);
    return 0;
}