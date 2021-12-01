/*
We have a2-D array dp where the dp[i][j] represents teh number of legal ways to stack j tiles using 
i different sizes of tiles. Now d[i][j] = sum(dp[i-x][j-1]) as for all legal arangements of i-1 tiles we can
add one more tile to the bottom and make a legal arrangement of i tiles
But we also have the constraint of k so we have to subtract sum(dp[i-x][j-k-1]) 
as we will have to use k symbols for such configurations
Now we will have one more array which will be the prefix summ to make the calculation faster
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = 0;
        prefix[0][i] = 1;
    }
    for (int i = 0; i < m + 1; i++)
        prefix[i][0] = dp[i][0] = 1;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            dp[i][j] = prefix[i - 1][j];
            if (j > k)
                dp[i][j] -= prefix[i - 1][j - k - 1];
        }
        for (int j = 0; j < n + 1; j++)
            prefix[i][j] += dp[i][j] + prefix[i][j - 1];
    }
    cout<<dp[m][n]<<endl;
}