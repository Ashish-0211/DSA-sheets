#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v)
{
    int n = v.size();
    int majority = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majority = v[i];
        }
        if (majority == v[i])
            count++;
        else
            count--;
    }
    return majority;
}
int main()
{
    int n;
    cout << "Enter size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int majority = majorityElement(v);
    cout << "Majority elemnt is :"
         << "\n";
    cout << majority << "\n";
    return 0;
}