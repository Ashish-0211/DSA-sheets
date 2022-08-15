#include <bits/stdc++.h>
using namespace std;
int RecursiveSolve(int i, int j, int n, int m)
{
    if (i == n - 1 and j == m - 1)
        return 1;
    if (i >= n or j >= m)
        return 0;

    return RecursiveSolve(i + 1, j, n, m) + RecursiveSolve(i, j + 1, n, m);
}
int dpSolve(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 and j == m - 1)
        return 1;
    if (i >= n or j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = dpSolve(i + 1, j, n, m, dp) + dpSolve(i, j + 1, n, m, dp);
}
int combinotricsSolve(int n, int m)
{
    int N = n + m - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;

    return (int)res;
}
int main()
{
    int n, m;
    cout << "Enter value of the n and m :"
         << "\n";
    cin >> n >> m;
    int paths = RecursiveSolve(0, 0, n, m);
    cout << "Number of the paths :"
         << "\n";
    cout << paths << "\n";
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Recursive answer :"
         << "\n";
    int ans = dpSolve(0, 0, n, m, dp);
    cout << ans << "\n";
    int res = combinotricsSolve(n, m);
    cout << "Combinotrics answer :"
         << "\n";
    cout << res << "\n";
    return 0;
}