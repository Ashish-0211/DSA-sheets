#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pasacalTriangle(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++)
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
    }
    return ans;
}
void print(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "Enter number of rows :"
         << "\n";
    cin >> n;
    vector<vector<int>> matrix = pasacalTriangle(n);
    print(matrix);
    return 0;
}