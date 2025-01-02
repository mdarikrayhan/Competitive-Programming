#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;
typedef vector<pll> vp;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define len(s) (int)s.size()
#define print(x) cout << x << '\n'
#define nl cout << '\n'
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define py print("YES")
#define pn print("NO");
#define pk print("OK");
#define mp make_pair

void printv(vector<ll> v)
{
    int n = v.size();
    rep(i, n)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vl t(n + 1), l(n + 1), r(n + 1);
    t[0] = 0, l[0] = m, r[0] = m;
    REP(i, 1, n)
    {
        cin >> t[i] >> l[i] >> r[i];
    }
    ll left = m, right = m;
    // pk;
    REP(i, 1, n)
    {
        // cout << left << " " << right << endl;
        ll k = t[i] - t[i - 1];
        ll a = abs(l[i] - left), b = abs(r[i] - right), c = abs(l[i] - right), d = abs(r[i] - left);
        // print(left<<" "<<right<<" "<<l[i]<<" "<<r[i]);
        if (l[i] <= left and r[i] >= right)
        {
            left = max(l[i], left - k);
            right = min(r[i], right + k);
        }
        else if (l[i] <= left and r[i] < right)
        {
            if (left <= r[i])
            {
            }
            else if (a > k and b > k and c > k and d > k)
            {
                pn;
                return;
            }
            left = max(l[i], left - k);
            right = r[i];
        }
        else if (l[i] > left and r[i] >= right)
        {
            if(l[i]<=right){
            }
            else if (a > k and b > k and c > k and d > k)
            {
                pn;
                return;
            }
            left = l[i];
            right = min(r[i], right + k);
        }
        else if (l[i] > left and r[i] < right)
        {
            left = l[i];
            right = r[i];
        }
    }
    py;
}

signed main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}