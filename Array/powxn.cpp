#include <bits/stdc++.h>
using namespace std;
double power(double n, double x)
{
    double ans = 1.0;
    long long nn = x;
    if (nn < 0)
        nn = -1 * nn;

    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * n;
            nn--;
        }
        else
        {
            n = n * n;
            nn = nn / 2;
        }
    }
    if (x < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}
int main()
{
    double x, n;
    cout << "Enter the values :"
         << "\n";
    cin >> n >> x;
    double ans = power(n, x);
    cout << "Answer is :"
         << "\n";
    cout << ans << "\n";
    return 0;
}