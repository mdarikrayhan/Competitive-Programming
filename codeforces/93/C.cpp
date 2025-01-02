// LUOGU_RID: 160394987
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forr(i,a,n) for(int i=a;i<=n;i++)
#define rep(i,n) forr(i,0,n-1)
#define repp(i,n) forr(i,1,n)
#define pb push_back
#define mp make_pair
#define init(a,i) memset(a,i,sizeof(a))
#define fi first
#define se second
#define mod 1000000007
#define MOD 998244353
#define MAXN 0x3f3f3f3f
int T_, case_;
int n, a[4];
struct op {
    int x, y, z, k;
    op(int xx, int yy, int zz, int kk) {
        x = xx, y = yy, z = zz, k = kk;
    }
};
vector<op>v;
bool suc = 0;
void dfs(int now, int lim) {
    if (suc)return;
    if (now > lim) {
        bool f = 0;
        rep(i, 2)if (a[i] == n)f = 1;
        if (f) {
            suc = 1;
            cout << (int)v.size() << endl;
            if (v.size())
                rep(i, v.size())
                cout << "lea e" << char('a' + v[i].x) << "x, [e" << char('a' + v[i].y) << "x + " << v[i].k << "*e" << char('a' + v[i].z) << "x]\n";
        }
        return;
    }
    rep(x, 2) {
        rep(y, 2) {
            rep(z, 2) {
                rep(kk, 4) {
                    int k = (1 << kk);
                    v.pb(op(x, y, z, k));
                    int tmp = a[x];
                    a[x] = a[y] + a[z] * k;
                    dfs(now + 1, lim);
                    a[x] = tmp;
                    v.pop_back();
                }
            }
        }
    }
}
void solve() {
    cin >> n;
    rep(i, 10) {
        init(a, 0);
        a[0] = 1;
        dfs(1, i);
        if (suc)return;
    }
}
int main() {
    T_ = 1;

    for (case_ = 1;case_ <= T_;case_++)solve();
    return 0;
}