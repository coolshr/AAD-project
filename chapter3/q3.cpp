/*
We maintain a variable ans which is like the stack length. We check the current character, if it is B and there is a 
character in the stack we can bomb it and decremetn ans. Otherwise we can't and increment ans 
*/

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
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'B' && ans)
                ans--;
            else
                ans++;
        }
        cout << ans << endl;
    }
}