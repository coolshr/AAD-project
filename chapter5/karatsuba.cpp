#include <bits/stdc++.h>
using namespace std;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}

string addBitStrings(string first, string second)
{
    string result;
    int length = makeEqualLength(first, second);
    int carry = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        int sum = (firstBit ^ secondBit ^ carry) + '0';
        result = (char)sum + result;
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry)
        result = '1' + result;

    return result;
}

int multiplyiSingleBit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

long int multiply(string X, string Y)
{
    int n = makeEqualLength(X, Y);

    if (n == 0)
        return 0;
    if (n == 1)
        return multiplyiSingleBit(X, Y);

    int fh = n / 2;
    int sh = (n - fh);

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}
int div(string *quotient, int *n)
{
    //int n = strlen(quotient);
    int carry = 0;
    char temp[*n];
    for (int i = 0; i < *n; i++)
    {
        temp[i] = '0' + (10 * carry + (*quotient)[i] - '0') / 2;
        carry = (10 * carry + (*quotient)[i] - '0') % 2;
    }
    //int i = 1;
    if (temp[0] == '0')
    {
        for (int i = 1; i < *n; i++)
        {
            (*quotient)[i - 1] = temp[i];
        }
        (*quotient)[*n - 1] = '\0';
        *n = *n - 1;
    }
    else
        for (int i = 0; i < *n; i++)
        {
            (*quotient)[i] = temp[i];
        }

    return carry;
}
string complement_2(string s1)
{
    int n = s1.length();
    string ans;
    int temp;
    int carry = 1;
    for (int i = 0; i < n; i++)
        ans = ans + "1";
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1[i] == '1')
            temp = carry;
        else
            temp = 1 + carry;

        ans[i] = (char)('0' + (temp % 2));
        carry = temp / 2;
    }
    return ans;
}
string to_bin(string s, int negative)
{
    string ans;
    int index = 0;
    int n = s.length();
    float tem = 3.4 * (n) + 4;
    for (int i = 0; i < (int)tem; i++)
        ans = ans + "0";
    while (n > 0)
    {
        ans[index++] = div(&s, &n) + '0';
    }
    reverse(ans.begin(), ans.end());
    if (negative)
    {
        ans = complement_2(ans);
    }
    return ans;
}
int main()
{
    long long int a, b;
    cout << "Enter A and B - " << endl;
    cin >> a >> b;
    string s1 = to_bin(to_string(a), 0);
    string s2 = to_bin(to_string(b), 0);
    cout << "A in binary is: " << s1 << endl;
    cout << "B in binary is: " << s2 << endl;
    cout << "A * B is: " << multiply(s1, s2) << endl;
}
