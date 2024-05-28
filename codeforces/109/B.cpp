#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a,n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
void fast();
ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
using namespace std;
vector<ll>v;
int k;
ll mx = 1e12;
void solve( ll num) {
    if (num>mx)return;
    v.push_back(num);
    solve(num * 10 + 4);
    solve(num * 10 + 7);
}
int main() {

    fast();
    solve(0);
    sort(all(v));
    ll pl, pr, vl, vr;
    cin >> pl >> pr >> vl >> vr >> k;
    ll cnt = 0;
    for (int i = 1; i + k < sz(v); i++) {
        ll l = max(0LL, min(v[i], pr) - max(v[i - 1]+1, pl)+1);
        ll r = max(0LL, min(v[i + k] - 1, vr) - max(v[i + k - 1], vl) + 1);
        cnt += l * r;
        l = max(0LL, min(v[i], vr) - max(v[i - 1] + 1, vl) + 1);
        r = max(0LL, min(v[i + k] - 1, pr) - max(v[i + k - 1], pl) + 1);
        cnt += l * r;
        if (k == 1 && v[i] >= pl && v[i] <= pr && v[i] >= vl && v[i] <= vr)cnt--;
    }
    cout << fixed << setprecision(12);
    cout << 1.0 * cnt / ((pr - pl + 1) * (vr - vl + 1));



    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
	  		 	 	 		 		 		   				  				