/*
We start from the end and loop iteratively and at each step we take the minimum of a[i] and prev - 1, that is the
current number of toffees and one less than taken last time
If this comes out to be 0 we break
Greedy choice - At each step we can select the number of toffees selected to create an optimum solution
Optimum substructure property - After each selection, the problem is reduced to a subproblem
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long int ans = a[n - 1];
    int prev = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int t = min(a[i], prev - 1);
        if (t == 0)
            break;
        ans += t;
        prev = t;
    }
    cout << ans;
}