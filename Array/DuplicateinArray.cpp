#include <bits/stdc++.h>
using namespace std;
void findDuplicate(vector<int> &nums)
{
    int duplicate = 0;
    int slow = 0;
    int fast = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    cout << "Duplicate is :" << slow << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    cout << "Enter elements in the array :"
         << "\n";
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    findDuplicate(a);
    return 0;
}