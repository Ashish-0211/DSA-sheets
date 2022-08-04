#include <bits/stdc++.h>
using namespace std;
int maximumSum(vector<int> nums)
{
    int size = nums.size();
    int current = 0;
    int ans = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        current += nums[i];
        ans = max(ans, current);
        if (current < 0)
            current = 0;
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
    cout << "Enter values in the vector :"
         << "\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int result = maximumSum(v);
    cout << "maximum sum subarray is :"
         << "\n";
    cout << result << "\n";
    return 0;
}