#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> num, int target)
{
    vector<vector<int>> res;

    if (num.empty())
        return res;
    int n = num.size();
    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++)
    {

        int target_3 = target - num[i];

        for (int j = i + 1; j < n; j++)
        {

            int target_2 = target_3 - num[j];

            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {

                int two_sum = num[front] + num[back];

                if (two_sum < target_2)
                    front++;

                else if (two_sum > target_2)
                    back--;

                else
                {

                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    res.push_back(quadruplet);
                    while (front < back && num[front] == quadruplet[2])
                        ++front;
                    while (front < back && num[back] == quadruplet[3])
                        --back;
                }
            }
            while (j + 1 < n && num[j + 1] == num[j])
                ++j;
        }

        while (i + 1 < n && num[i + 1] == num[i])
            ++i;
    }

    return res;
}
void print(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "enter the size of the array :"
         << "\n";
    cin >> n;
    cout << "enter the value in the array :"
         << "\n";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "enter the target :"
         << "\n";
    int target;
    cin >> target;
    cout << "The quadruples are :"
         << "\n";
    vector<vector<int>> ans = fourSum(v, target);
    print(ans);
    return 0;
}