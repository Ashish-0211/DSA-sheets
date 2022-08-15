#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &num)
{
    int n = num.size();
    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += num[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mp.count(sum))
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return maxi;
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements in the array :"
         << "\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int longest = solve(v);
    cout << "Longest subarray with sum 0 is :" << longest << "\n";
    return 0;
}