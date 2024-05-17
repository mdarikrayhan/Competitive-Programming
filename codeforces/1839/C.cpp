/*
 ___      ___     ______     _______    ________     __      _____  ___
|"  \    /"  |   /    " \   /"      \  /"       )   /""\    (\"   \|"  \
 \   \  //   |  // ____  \ |:        |(:   \___/   /    \   |.\\   \    |
 /\\  \/.    | /  /    ) :)|_____/   ) \___  \    /' /\  \  |: \.   \\  |
|: \.        |(: (____/ //  //      /   __/  \\  //  __'  \ |.  \    \. |
|.  \    /:  | \        /  |:  __   \  /" \   :)/   /  \\  \|    \    \ |
|___|\__/|___|  \"_____/   |__|  \___)(_______/(___/    \___)\___|\____\)

*/

// You are given an array a of length n and the sky is blue...
// if there are multiple possible answers print any of them.

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
const ll Modd = 998244353;
#define dq deque
#define speed ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ppb pop_back
#define ppf pop_front
#define gcd __gcd
#define sz(x) (x).size()
#define lcm(a, b) (a * b / gcd(a, b))
#define ceil(x, y) (x + y - 1) / y
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pf push_front
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod(x) x = ((x % Modd) + Modd) % Modd
#define yon(x) cout << (x ? "YES\n" : "NO\n")

void Morsan_Solve()
{
    // cout << setprecision(20) << fixed;
    // Start..
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0;i < n;i++)
        cin >> a[i];
    if (a.back() == 1)
    {
        cout << "NO\n";
        return;
    }
    int i = n - 1;
    while (sz(a))
    {
        int cnt0 = -1, cnt1 = 0;
        while (i >= 0 && a[i] == 0)
            a.ppb(), cnt0++, i--;
        while (i >= 0 && a[i] == 1)
            a.ppb(), cnt1++, i--;
        cnt0 += cnt1;
        while (cnt0--)
            b.pb(0);
        b.pb(cnt1);
    }
    cout << "YES\n";
    for (int i = 0;i < n;i++)
        cout << b[i] << " ";
    cout << '\n';
    // End..
}
int main()
{
    speed;
    int t = 1;
    cin >> t;
    while (t--)
        Morsan_Solve();
    return 0;
}

// Authored by Morsan...
// Next level : "specialist"