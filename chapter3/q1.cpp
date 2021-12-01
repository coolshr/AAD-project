/*
Optimum Substructure property - After each selection, we are left with a subproblem (arrangment of n' boys and m' girls)
Geedy Choice property - We first choose as many BG paors as we can and then choose the gender who have the more number
*/




#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int b, g;
    cin >> b >> g;
    if (b > g)
    {
        for (int i = 0; i < g; i++)
            cout << "BG";
        for (int i = 0; i < b - g; i++)
            cout << "B";
    }
    else
    {
        for (int i = 0; i < b; i++)
            cout << "GB";
        for (int i = 0; i < g - b; i++)
            cout << "G";
    }
    cout << endl;
    // return 0;
}