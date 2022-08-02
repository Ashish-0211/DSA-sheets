#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(int income)
{
    ll tax = 0;
    ll surcharge = 0;
    ll health = 0;
    if (income >= 250000 and income < 500000)
    {
        tax = income * (0.05);
        health = income * (0.04);
        return (tax + health);
    }
    else if (income >= 500000 and income < 750000)
    {
        tax = income * (0.1);
        health = income * (0.04);
        return (health + tax);
    }
    else if (income >= 750000 and income < 1000000)
    {
        tax = income * (0.15);
        health = income * (0.04);
        return (tax + health);
    }
    else if (income >= 1000000 and income < 1250000)
    {
        tax = income * (0.2);
        health = income * (0.04);
        return (tax + health);
    }
    else if (income >= 1250000 and income < 1500000)
    {
        tax = income * (0.25);
        health = income * (0.04);
        return (tax + health);
    }
    else if (income >= 1500000 and income < 5000000)
    {
        tax = income * (0.3);
        health = income * (0.04);
        return (tax + health);
    }
    else
    {
    }
}
int main()
{
    ll income;
    cin >> income;
    ll tax = 0;
    ll surcharge = 0;
    ll health = 0;
    solve(income);
    return 0;
}
