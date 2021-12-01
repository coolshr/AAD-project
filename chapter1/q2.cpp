#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp = 0;
    cin >> n;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        price.push_back(temp);
    }
    int q;
    cin >> q;
    vector<int> money;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        money.push_back(temp);
    }
    sort(price.begin(), price.end());
    for (int i = 0; i < q; i++)
    {
        auto temp_it1 = upper_bound(price.begin(), price.end(), money[i]);
        if (temp_it1 == price.begin() && *temp_it1 > money[i])
        {
            cout << "0\n";
            continue;
        }
        else
        {
            if (temp_it1 == price.begin())
            {
                cout << "1\n";
                continue;
            }
            else
            {
                if (*(temp_it1 - 1) <= money[i])
                    cout << temp_it1 - price.begin() << "\n";
                else
                    cout << temp_it1 - price.begin() - 1 << "\n";
            }
        }
    }
}