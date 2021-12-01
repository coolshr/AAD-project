#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cout << "Enter the number of activities: " << endl;
    cin >> n;
    cout << "Enter the start and end times: " << endl;
    vector<tuple<int, int, int>> v;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back(make_tuple(start, end, i));
    }
    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
         { return get<1>(a) < get<1>(b); });
    cout << "The activities are: " << endl;
    cout << "Activity Number\tActivity Start Time\tActivity Finish Time" << endl;
    int i = 0;
    cout << get<2>(v[i]) + 1 << "\t\t\t" << get<0>(v[i]) << "\t\t\t" << get<1>(v[i]) << endl;
    for (int j = 1; j < n; j++)
    {
        if (get<0>(v[j]) >= get<1>(v[i]))
        {
            i = j;
            cout << get<2>(v[i]) + 1 << "\t\t\t" << get<0>(v[i]) << "\t\t\t" << get<1>(v[i]) << endl;
        }
    }
}