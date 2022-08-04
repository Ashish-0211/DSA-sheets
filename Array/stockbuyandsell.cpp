#include <bits/stdc++.h>
using namespace std;
int profit(vector<int> nums)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        minPrice = min(minPrice, nums[i]);
        maxProfit = max(maxProfit, nums[i] - minPrice);
    }
    return maxProfit;
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    cout << "Enter the values in the array :"
         << "\n";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = profit(v);
    cout << "Profits is :"
         << "\n";
    cout << ans << "\n";
    return 0;
}