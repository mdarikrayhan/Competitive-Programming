#include <bits/stdc++.h>
using namespace std;

# define ll long long
# define FOR(i, a, b) for (int i=a; i<b; i++)
# define RFOR(i, a, b) for (int i=a; i>=b; i--)
# define all(x) (x).begin(), (x).end()
# define vi vector <int>
# define vll vector <long long>
# define vpi vector<pair<int,int>>
# define vpll vector <pair<long long, long long>>
# define mapi map<int,int>
# define mapll map<ll,ll>
# define endl "\n"
# define yes cout<<"YES\n"
# define no cout<<"NO\n"
# define zeus ios_base::sync_with_stdio(false); cin.tie(nullptr);

ll M = 1e9 + 7;
ll INF = 1e6;

ll binpow (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

bool cmp (pair <ll, ll> &a, pair <ll, ll> &b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

bool pred (vector <ll> &a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    vll a(n), ans;
    FOR (i, 0, n) cin >> a[i];
    set <ll> s;
    mapll freq;
    for (int i = 0; i <= n; i++) s.insert(i);
    for (auto &val : a) {
        ++freq[val];
        s.erase(val);
    }
    deque <ll> wrong;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) wrong.push_back(i);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (pred(a)) break;
        int mex = *s.begin();
        if (mex == n) {
            int replace = wrong.front();
            ans.push_back(replace + 1);
            --freq[a[replace]];
            if (freq[a[replace]] == 0) s.insert(a[replace]);
            a[replace] = mex;
            freq[mex]++;
            s.erase(mex);
        }
        else {
            ans.push_back(mex + 1);
            wrong.erase(lower_bound(all(wrong), mex));
            --freq[a[mex]];
            if (freq[a[mex]] == 0) s.insert(a[mex]);
            a[mex] = mex;
            freq[mex]++;
            s.erase(mex);
        }
    }
    cout << ans.size() << endl;
    for (auto &val : ans) cout << val << " ";
    cout << endl;
}

signed main() {
    zeus;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}