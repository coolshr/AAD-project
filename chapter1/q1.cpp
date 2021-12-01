#include <bits/stdc++.h>

using namespace std;
// The program works by traversing through the string and checking if the character is upper case, if it is then it is convereted to lower case.
// The character is then checked if it is a vowel, if it is then it is not added to the answer string.
// If the character is not a vowel then it is added to the answer string with a '.'.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char s[101], ans[201] = {'\0'};
    cin >> s;
    int j = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = 'a' + (s[i] - 'A');
        }
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
            ;
        else
        {
            ans[j++] = '.';
            ans[j++] = s[i];
        }
    }
    cout << ans;
}
