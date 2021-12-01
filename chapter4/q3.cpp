#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d, f, target;
    cin >> d >> f >> target;
    int ans = 0;
    vector<vector<int>> dp(target + 1, vector<int>(d + 1, 0));
    for (int i = 1; i <= target && i <= f; i++)
        dp[i][1] = 1;

    for (int j = 2; j <= d; j++)
    {
        for (int i = 1; i <= target; i++)
        {
            for (int k = 1; k < i && k <= f; k++)
                dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % mod;
        }
    }
    cout<<dp[target][d]<<endl;
}