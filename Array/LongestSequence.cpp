#include <bits/stdc++.h>
using namespace std;
int longestSequence(vector<int> &num)
{
    set<int> st;
    for (int i : num)
        st.insert(i);
    int longest = 0;
    for (int i : num)
    {
        if (!st.count(i - 1))
        {
            int currentNum = i;
            int curentStreak = 1;
            while (st.count(currentNum + 1))
            {
                currentNum += 1;
                curentStreak += 1;
            }
            longest = max(longest, curentStreak);
        }
    }
    return longest;
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
    int ans = longestSequence(v);
    cout << "Longest sequence is :" << ans << "\n";
    return 0;
}