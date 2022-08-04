#include <bits/stdc++.h>
using namespace std;
void permutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    cout << "Enter the array to to be operated :"
         << "\n";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    permutation(v);
    print(v);
    return 0;
}