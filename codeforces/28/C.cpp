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
int n, m;
int v[55];
double dp[55][55][55];
double p;
ull nCr(int n, int r) {
    if (r > n)
        return 0;
    r = max(r, n - r);
    ull ans = 1, div = 1, i = r + 1;
    while (i <= n) {
        ans *= i++;
        ans /= div++;
    }
    return ans;
}
double solve(int indx, int rem, int mx) {
    if (indx == m) {
        if (rem > 0)return 0;
        return mx*p;
    }
    double& ret = dp[indx][rem][mx];
    if (ret==ret)return ret;
    ret = 0;
    for (int i = 0; i <= rem; i++) {
        ret +=nCr(rem,i)* 
            solve(indx + 1, rem - i, max(mx, (i + v[indx] - 1) / v[indx]));
    }
    return ret;
}
int main() {

    fast();
    cin >> n >> m;
    for (int i = 0; i < m; i++)cin >> v[i];
    p = 1;
    for (int i = 0; i < n; i++)p /= m;
    mem(dp, -1);
    cout << fixed << setprecision(20);
    cout << solve(0, n, 0);

    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
	 		   		 		  	   		  	  				 	