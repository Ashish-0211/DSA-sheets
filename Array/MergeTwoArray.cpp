#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    cout << "\n";
}
void mergeArray(vector<int> &a, vector<int> &b, int n, int m)
{
    for (int i = 0; i < n; i++)
        a[m + i] = b[i];
    int gap = ceil((n + m) / 2);
    int start = 0;
    int end = start + gap;
    while (gap >= 1)
    {
        start = 0;
        end = start + gap;
        while (end < (m + n))
        {
            if (a[start] > b[end])
                swap(a[start], b[end]);
            start++;
            end++;
        }
        if (gap == 1)
            break;
        else if (gap % 2)
            gap = gap / 2 + 1;
        else
        {
            gap = gap / 2;
        }
    }
}
void mergeNaive(vector<int> &a, vector<int> &b, int n, int m)
{
    int i = m - 1;
    int j = n - 1;
    int end = m + n - 1;
    while (i >= 0 and j >= 0)
    {
        if (a[i] > b[j])
            a[end--] = a[i--];
        else
            a[end--] = b[j--];
    }
    while (j >= 0)
        a[end--] = b[j--];
}
int main()
{
    int n, m;
    cout << "Enter the size of the 1st array :"
         << "\n";
    cin >> m;
    cout << "Enter the size of the 2nd array :"
         << "\n";
    cin >> n;
    vector<int> a(m), b(n);
    cout << "Enter in the first array :"
         << "\n";
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "Enter in the second array :"
         << "\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];
    print(a);
    print(b);
    cout << "Modified array is :"
         << "\n";
    mergeArray(a, b, m, n);
    print(a);
    mergeNaive(a, b, m, n);
    print(a);
    return 0;
}