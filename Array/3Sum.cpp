#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ThreeSum(vector<int> num, int target)
{
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 2; i++)
    {
        if (i == 0 || (i > 0 and num[i] != num[i - 1]))
        {
            int low = i + 1;
            int high = num.size() - 1;
            int sum = 0 - num[i];
            while (low < high)
            {
                if (num[low] + num[high] == sum)
                {
                    vector<int> temp(3, 0);
                    temp[0] = num[i];
                    temp[1] = num[low];
                    temp[2] = num[high];
                    ans.push_back(temp);
                    while (low < high and num[low] == num[low + 1])
                        low++;
                    while (low < high and num[high] == num[high - 1])
                        high--;

                    low++;
                    high--;
                }
                else if (num[low] + num[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
    return ans;
}
void print(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";

        cout << "\n";
    }
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
    int target;
    cout << "Enter the target :"
         << "\n";
    cin >> target;
    vector<vector<int>> ans = ThreeSum(v, target);
    print(ans);
    return 0;
}