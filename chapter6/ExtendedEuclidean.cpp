#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> extendedEuclidean(int a, int b)
{
    if (b == 0)
        return make_tuple(1, 0, a);
    else
    {
        auto t = extendedEuclidean(b, a % b);
        int x = get<0>(t);
        int y = get<1>(t);
        return make_tuple(y, (x - ((a / b) * y)), get<2>(t));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cout << "Enter two numbers a and b: " << endl;
    cin >> a >> b;
    tuple<int, int, int> result;
    if (a > b)
        result = extendedEuclidean(a, b);
    else
        result = extendedEuclidean(b, a);
    cout<< "x: " << get<0>(result) << " y: " << get<1>(result) << " gcd: " << get<2>(result) << endl;    
}