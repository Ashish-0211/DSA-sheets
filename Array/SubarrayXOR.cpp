#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v, int b)
{
    map<int, int> mp;
    int count = 0;
    int xorr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        xorr = xorr ^ v[i];
        if (xorr == b)
            count++;
        if (mp.count(xorr ^ b))
            count += mp[xorr ^ b];

        mp[xorr] += 1;
    }
    return count;
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
    cout << "Enter the target :"
         << "\n";
    int target;
    cin >> target;
    int ans = solve(v, target);
    cout << "Longest xor subarray is :" << ans << "\n";
    return 0;
}