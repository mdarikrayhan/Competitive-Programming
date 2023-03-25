#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int a, b;
    cin >> a >> b;
    long long int c = min(a, b);
    a-=c;
    b-=c;
    long long int d = max(a, b);
    cout << c << " " << d / 2 << nl;
    return 0;
}