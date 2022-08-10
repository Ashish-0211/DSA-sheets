#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
        return false;
    int m = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[mid / m][mid % m] == target)
            return true;
        if (matrix[mid / m][mid % m] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int n, m;
    cout << "enter row and columns of the matrix"
         << "\n";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    cout << "Enter element to be searched in the matrix :"
         << "\n";
    int target;
    cin >> target;
    if (searchMatrix(matrix, target))
        cout << "Found element "
             << "\n";
    else
        cout << "Not found "
             << "\n";
    return 0;
}