#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> v)
{
    vector<int> majority;
    int size = v.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < size; i++)
    {
        if (v[i] == num1)
            count1++;
        else if (v[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = v[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 == v[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (num1 == v[i])
            count1++;
        else if (num2 == v[i])
            count2++;
    }
    if (count1 > (size / 3))
        majority.push_back(num1);
    if (count2 > (size / 3))
        majority.push_back(num2);
    return majority;
}
int main()
{
    int n;
    cout << "Enter size of the array :"
         << "\n";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> majority;
    majority = majorityElement(v);
    cout << "Majority elemnt is :"
         << "\n";
    for (auto i : majority)
        cout << i << " ";
    return 0;
}