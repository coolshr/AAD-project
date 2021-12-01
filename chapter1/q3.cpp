#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, temp;
        pair<int, int> tmp;
        cin >> n >> x;
        vector<pair<int, int>> a;
        unsigned long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            tmp.first = temp;
            tmp.second = 1;
            a.push_back(tmp);
            ans += temp;
        }
        int i = 0;
        while (1)
        {
            if (a[i].first % x == 0)
            {
                ans += a[i].first * a[i].second;
                tmp.first = a[i].first / x;
                tmp.second = x * a[i].second;
                a.push_back(tmp);
                i++;
            }
            else
                break;
        }
        cout << ans << endl;
    }
}