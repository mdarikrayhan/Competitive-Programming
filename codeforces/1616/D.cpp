#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f(i, a, b) for(int i = a; i <= b; i++)
#define fr(i, a, b) for(int i = a; i >= b; i--)
#define pii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define in insert
#define vvec vector<vector<int>>
#define fast ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int N = 5e4 + 5;
int t, n, x, a[N];

signed main()
{
    fast;
    cin >> t;
    while(t--)
    {
        cin >> n;
        f(i, 1, n) cin >> a[i];
        cin >> x;
        f(i, 1, n) a[i] -= x;

        int res = n;
        f(i, 2, n)
            if(a[i] + a[i - 1] < 0 || a[i] + a[i - 1] + a[i - 2] < 0) res--, a[i] = 1e15;
        cout << res << "\n";
    }

}
