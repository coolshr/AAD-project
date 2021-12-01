#include <bits/stdc++.h>

using namespace std;

int Fib(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return Fib(x - 1) + Fib(x - 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 45;
    // cout << "Enter the index of Fibonacci number " << endl;
    // cin >> n;
    cout << Fib(n) << endl;
}