/*
This problem uses dp twice 
Once when we calculate the array a which represents if s[i] == s[i+1] if true then a[i] is set to 1 else 0
Now we have to count all 1 instances in the array a between the query numbers
To calculate teh sum faster we calculate the prefix sum 
It is the sum of all the elements in the array a from 0 to i
Now for each query we just have to print prefix[r -1 ] - prefix[l -1]
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<pair<int, int>> v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i].first >> v[i].second;
    vector<int> a(s.length(), 0);
    for (int i = 0; i < s.length() - 1; i++)
        a[i] = (s[i] == s[i + 1]) ? 1 : 0;
    vector<int> prefix(s.length() + 1);
    prefix[0] = 0;
    for (int i = 1; i <= s.length(); i++)
        prefix[i] = prefix[i - 1] + a[i - 1];
    for (int i = 0; i < q; i++)
    {
        int ans = prefix[v[i].second - 1] - prefix[v[i].first - 1];
        cout << ans << endl;
    }
}