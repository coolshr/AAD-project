#include <bits/stdc++.h>

using namespace std;

long long int Fib(long long int arr[], long long int x)
{
    if (arr[x] != -1)
        return arr[x];
    else if (x == 0 || x == 1)
    {
        arr[x] = 1;
        return 1;
    }
    else
    {
        arr[x] = Fib(arr, x - 1) + Fib(arr, x - 2);
        return arr[x];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 100;
    // cout << "Enter the index of Fibonacci number " << endl;
    // cin >> n;
    long long int arr[n + 1];
    for (int i = 0; i < n + 1; i++)
        arr[i] = -1;
    cout << Fib(arr, n) << endl;
}