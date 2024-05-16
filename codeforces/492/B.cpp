/**
 *  author: x-iy <...> 
**/

// Always code as if the guy who ends up maintaining your code is a VIOLENT PSYCHOPATH who knows where you live.

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF INT_MAX
#define EPS INT_MIN
#define MOD 1000000007ll
#define PI (double)2*acos(0.0)

#define endl '\n'
#define sqr(x) (x) * (x)	
#define len(x) (ll)x.size()

#define rep1(a) for (ll _{}; _ < ll(a); ++_)
#define rep2(i, a) for (ll i{}; i < ll(a); ++i)
#define rep3(i, a, b) for (ll i{a}; i < ll(b); ++i)
#define rep4(i, a, b, c) for (ll i{a}; i < ll(b); i += (c))
#define rev1(a) for (ll _{(a)-1}; _ >= ll(0); --_)
#define rev2(i, a) for (ll i{(a)-1}; i >= ll(0); --i)
#define rev3(i, b, a) for (ll i{(b)-1}; i >= ll(a); --i)
#define rev4(i, b, a, c) for (ll i{(b)-1}; i >= ll(a); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rev(...) overload4(__VA_ARGS__, rev4, rev3, rev2, rev1)(__VA_ARGS__)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define pb push_back
#define em emplace_back
#define st first
#define nd second

using namespace std;

void PS () {
    int n, l;
    double r{};
    cin >> n >> l;

    vector<int> v(n);
    for (auto& it : v) cin >> it;
    sort(all(v));

    if (v[0] != 0 || v[n-1] != l) r = max(v[0], l-v[n-1]);
    
    rep(i, 1, n) if ((v[i] - v[i-1])/2.0 > r)
        r += ((v[i] - v[i-1]) / 2.0 - r);
    cout << r;        

}         

int main () {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    	
    int t{1};
    //cin >> t;

    cout << setprecision(10);
    while (t--)
        PS();
    
    cin.get();
    return 0;
}
