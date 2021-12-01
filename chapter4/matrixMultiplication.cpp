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
        cin >> a[i];                                        // The dimensions of matrix i is a[i-1] x a[i]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9 + 7));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }
    cout << dp[1][n - 1] << endl;
}