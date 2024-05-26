#include <bits/stdc++.h>
using namespace std;

#define sui cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
#define ll long long
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define SZ(x) ((int)(x).size())

const int N = 1e6+50000;
ll n, m, b;
ll dp[N];
pair<ll, pii> f[N];

int main()
{
    sui
    cin >> n >> m >> b;
    //memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) {
        int x, k, mi, num = 0; cin >> x >> k >> mi;
        for (int j = 0; j < mi; j++) {
            int d; cin >> d;d--;
            num += (1 << d);
        }

        f[i] = {k, {x, num}};
    }

    sort(f, f+n);

    for (int i = 1; i < N; i++) dp[i] = 2e18;
    for (int i = n-1; i >= 0; i--) {
        for (int num = 0; num  < (1 << m); num++) {
            if (num == (num ^ f[i].S.S & num | f[i].S.S)) continue;
            //cout << num << " " << dp[num]  << " " << (num ^ f[i].S.S & num | f[i].S.S)<< endl;
            dp[num ^ f[i].S.S & num | f[i].S.S] = min(dp[num ^ f[i].S.S & num | f[i].S.S], dp[num] + f[i].S.F + (num == 0) * f[i].F * b);
        }
    }

    cout << (dp[(1 << m) - 1] == 2e18?-1:dp[(1 << m) - 1]);
    
    return 0;
}
