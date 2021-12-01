/*
We will make a function solve(l,r,c) which will give the minimum changes for the string s[l..r] to become a c-good string
Now solve(l,r,c) = min(r-l/2 - count(l,mid,c) + solve(mid,r,c+1), r-l/2 - count(mid+1,r,c) + solve(l,mid,c+1))
count(l,r,c) is the number of occurences of c in s[l..r]
This works as the first sum is the second condition and the second sum is the third condition in the question
We will need r-l/2 c charaters and henc ew ecalculate the number of occurences of c in s[l..r]
and add the answer to the later half into it.
For the base case we have if r-l == 1return 0 if s[l] == c else return 1
*/
#include <bits/stdc++.h>

using namespace std;

int count(string s, int l, int r, char c)
{
    int ans = 0;
    for (int i = l; i < r; i++)
        if (s[i] == c)
            ans++;
    return ans;
}

long long int solve(string s, int l, int r, char c)
{
    if (r - l == 1)
    {
        if (s[l] == c)
            return 0;
        else
            return 1;
    }
    int mid = (l + r) / 2;
    int a = count(s, l, mid, c);
    int b = count(s, mid , r, c);
    int x = (r - l ) / 2 - a + solve(s, mid, r, c + 1);
    int y = (r - l ) / 2 - b + solve(s, l, mid, c + 1);
    return min(x, y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int x;
        cin >> x;
        cin >> s;
        cout << solve(s, 0, s.length() , 'a') << endl;
    }
}