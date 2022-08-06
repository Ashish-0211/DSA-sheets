#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeInterval(vector<vector<int>> matrix)
{
    vector<vector<int>> ans;
    if (matrix.size() == 0)
        return ans;
    sort(matrix.begin(), matrix.end());
    ans.push_back(matrix[0]);
    for (int i = 1; i < matrix.size(); i++)
    {
        if (ans.back()[1] >= matrix[i][0])
            ans.back()[1] = max(ans.back()[1], matrix[i][1]);
        else
            ans.push_back(matrix[i]);
    }
    return ans;
}
void print(vector<vector<int>> m)
{
    int n = m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << m[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "Enter the number of intervals :"
         << "\n";
    cin >> n;
    vector<vector<int>> interval(n, vector<int>(2));
    cout << "Enter the inervals :"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> interval[i][j];
    }
    cout << "Before merging :"
         << "\n";
    print(interval);
    vector<vector<int>> ans = mergeInterval(interval);
    cout << "After marging :"
         << "\n";
    print(ans);
    return 0;
}