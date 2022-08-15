#include <bits/stdc++.h>
using namespace std;
int solve(string str)
{
    int n = str.size();
    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int len = 0;
    while (right < n)
    {
        if (mpp[str[right]] != -1)
            left = max(mpp[str[right]] + 1, left);
        mpp[str[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
int main()
{
    string str;
    cout << "Enter the string :"
         << "\n";
    cin >> str;
    int ans = solve(str);
    cout << "Longest substring without repeating character :"
         << "\n";
    cout << ans << "\n";
    return 0;
}