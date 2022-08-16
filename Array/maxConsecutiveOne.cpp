#include <bits/stdc++.h>
using namespace std;
int consecutiveOne(vector<int> v)
{
    int count = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            count++;
        }
        else if (v[i] == 0)
        {
            ans = max(ans, count);
            count = 0;
        }
    }
    return ans;
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
    int ans = consecutiveOne(v);
    cout << "Maximum consecutive one :"
         << "\n";
    cout << ans;
    return 0;
}