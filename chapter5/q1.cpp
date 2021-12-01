/*
We slove this recursively by first finding the max element in the current subarray and then setting its depth = curDepth
We then recursively call the function for the subarray a[l...m-1] and a[m+1...r] (m is the index of max element)
*/

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &a, vector<int> &depth, int l, int r, int curDepth)
{
    if (r < l)
        return;
    if (l == r)
    {
        depth[l] = curDepth;
        return;
    }
    int m = l;
    for (int i = l + 1; i <= r; i++)
        if (a[i] > a[m])
            m = i;
    depth[m] = curDepth;
    solve(a, depth, l, m - 1, curDepth + 1);
    solve(a, depth, m + 1, r, curDepth + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> depth(n);
        solve(a, depth, 0, n - 1, 0);
        for (int i = 0; i < n; i++)
            cout << depth[i] << " ";
        cout << endl;
    }
}