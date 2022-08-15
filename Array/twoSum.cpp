#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &v, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        if (mp.find(target - v[i]) != mp.end())
        {
            return {mp[target - v[i]], i};
        }
        else
            mp[v[i]] = i;
    }
    return {};
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int target;
    cout << "Enter the target :"
         << "\n";
    cin >> target;
    vector<int> ans = solve(v, target);
    cout << "Target find at :"
         << "\n";
    for (int i = 0; i < 2; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}