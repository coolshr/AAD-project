#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cout << "Enter a and b: " << endl;
    cin >> a >> b;
    int ans = 0;
    if (a > b)
        ans = gcd(a, b);
    else
        ans = gcd(b, a);
    cout << ans << endl;
}