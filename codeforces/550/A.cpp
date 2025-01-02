#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ve vector
#define pb push_back
#define int long long
#define pll pair<int, int>
#define fi first
#define se second
const int inf = 0x7fffffff;

void solve()
{
    string s1, a = "AB", b = "BA";
    cin >> s1;
    int k = s1.find(a);
    if (k != -1){
        k = s1.find(b, k + 2);
        if (k != -1){
            cout << "YES\n";
            return ;
        }
    }
    k = s1.find(b);
    if (k != -1){
        k = s1.find(a, k + 2);
        if (k != -1){
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
}

/*
BACFAB


*/
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)solve();
    return 0;
}