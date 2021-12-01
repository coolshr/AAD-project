#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> lis(n, 1);
    int maxLis = 0, max_index = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                lis[i] = max(lis[j] + 1, lis[i]);
                if (lis[i] > maxLis)
                {
                    maxLis = lis[i];
                    max_index = i;
                }
            }
        }
    }
    cout << "Max length of Longest increasing subsequence is - " << maxLis << endl;
    cout << "The elements of the longest increasing subsequence are - " << endl;
    vector<int> ans;
    for (int i = max_index; i >= 0; i--)
    {
        if (lis[i] == maxLis)
        {
            ans.push_back(v[i]);
            maxLis--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}