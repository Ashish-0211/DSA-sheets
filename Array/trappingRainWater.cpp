#include <bits/stdc++.h>
using namespace std;
int trapWater(vector<int> nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxLeft = 0;
    int maxRight = 0;
    while (left <= right)
    {
        if (nums[left] <= nums[right])
        {
            if (nums[left] >= maxLeft)
                maxLeft = nums[left];
            else
            {
                res += maxLeft - nums[left];
            }
            left++;
        }
        else
        {
            if (nums[right] >= maxRight)
            {
                maxRight = nums[right];
            }
            else
            {
                res += maxRight - nums[right];
            }
            right--;
        }
    }
    return res;
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
    int ans = trapWater(v);
    cout << "Water is traped :" << ans << "\n";
    return 0;
}