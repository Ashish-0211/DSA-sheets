#include <bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void print(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the nxn matrix :"
         << "\n";
    cin >> n;
    cout << "Enter the value in the matrix :"
         << "\n";
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << "Matrix before change :"
         << "\n";
    print(matrix);
    transpose(matrix);
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    cout << "Matrix after change :"
         << "\n";
    print(matrix);
    return 0;
}