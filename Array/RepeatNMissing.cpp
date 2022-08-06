#include <bits/stdc++.h>
using namespace std;
void findMandR(vector<int> nums)
{
    int xor1;
    int set_bit;
    int i;
    int x = 0;
    int y = 0;
    int n = nums.size();
    xor1 = nums[0];
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ nums[i];

    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
    set_bit = xor1 and (~(xor1 - 1)); // get the rightmost bits
    for (i = 0; i < n; i++)
    {
        if (nums[i] and set_bit)
            x = x ^ nums[i];
        else
            y = y ^ nums[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (i and set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }
    int x_count = 0;
    for (i = 1; i < n; i++)
    {
        if (nums[i] == x)
            x_count++;
    }
    if (x_count == 0)
    {
        cout << y << " " << x << "\n";
        return;
    }
    cout << x << " " << y << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of the array :"
         << "\n";
    cin >> n;
    cout << "Enter the elements in the array :"
         << "\n";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    findMandR(nums);
    return 0;
}