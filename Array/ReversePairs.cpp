#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &v, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high and v[i] > 2LL * v[j])
            j++;
        cnt += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid and right <= high)
    {
        if (v[left] <= v[right])
            temp.push_back(v[left++]);

        else
            temp.push_back(v[right++]);
    }
    while (left <= mid)
        temp.push_back(v[left++]);
    while (right <= high)
        temp.push_back(v[right]);
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];

    return cnt;
}
int mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return 1;
    int mid = low + (high - low) / 2;
    int rp = mergeSort(v, 0, mid);
    rp += mergeSort(v, mid + 1, high);
    rp += merge(v, low, mid, high);
    return rp;
}
int main()
{
    int n;
    cin >> n;
    cout << "Enter the size of the array :"
         << "\n";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int reversePair = mergeSort(v, 0, n - 1);
    cout << "Total revrese pairs :"
         << "\n";
    cout << reversePair << "\n";
    return 0;
}