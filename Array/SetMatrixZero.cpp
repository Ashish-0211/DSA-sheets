#include <bits/stdc++.h>
using namespace std;
void setMatrixtoZero(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, -1);
    vector<int> col(m, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 or col[j] == 0)
                matrix[i][j] = 0;
        }
    }
}
void setMatrixOptimise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
                matrix[i][j] = 0;

            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
}
void printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";

        cout << "\n";
    }
}
int main()
{
    int n, m;
    cout << "Enetr dimensions of the matrix :"
         << "\n";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix before the change :"
         << "\n";
    printMatrix(matrix);
    setMatrixtoZero(matrix);
    cout << "Matrix after change :"
         << "\n";
    printMatrix(matrix);
    return 0;
}