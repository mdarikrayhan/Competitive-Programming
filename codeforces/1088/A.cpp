#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define arr(type, data) type<data>
#define YES cout << "YES"
#define yes cout << "yes"
#define NO cout << "NO"
#define no cout << "no"
#define int long long
#define endl '\n'
#define vc2d(n, m, type, name) vector<vector<type>> name(n, vector<type> (m))
#define scan(d, n) for (int i = 0; i < n; i++) cin >> d[i];
#define print(d, n) for (int i = 0; i < n; i++) cout << d[i] << ' ';
#define all(d) d.begin(), d.end()
string P = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string p = "abcdefghijklmnopqrstuvwxyz";

void ablablabla()
{   
    int x; cin >> x;
    if (x == 1) cout << -1;
    else if (x == 2) cout << x << ' ' << x;
    else cout << x-1  << ' ' << x-1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ablablabla();
        cout << endl;
    }
    
    return 0;
}