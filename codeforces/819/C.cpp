#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int T, mn[2000010], a[3], b[3], c[3];
ll e[233], n, m, s, ans;
vector<int> M, N, S;
 
void dfs1(int cur, ll x) {
    if (x >= m) return;
    if (cur == S.size()) { ans++; return; }
    if (!(s / x % S[cur])) dfs1(cur, x * S[cur]);
    dfs1(cur + 1, x);
}
 
void dfs2(int cur, ll x, int coef) {
    if (!x || cur == M.size()) { ans += x * coef; return; }
    dfs2(cur + 1, x, coef);
    dfs2(cur + 1, x / e[cur], -coef);
}
 
int main() {
    scanf("%d", &T);
    for (int i = 2; i <= 2000000; i++) if (!mn[i]) {
        for (int j = i; j <= 2000000; j += i) mn[j] = i;
    }
    while (T--) {
        m = n = s = 1;
        M.clear(), N.clear(), S.clear();
        auto fact = [&](int x, vector<int> &V) {
            while (x > 1) {
                int t = mn[x];
                while (!(x % t)) x /= t;
                V.push_back(t);
            }
        };
        auto upd = [&](vector<int> &V) {
            sort(V.begin(), V.end());
            V.resize(unique(V.begin(), V.end()) - V.begin());
        };
        for (int i = 0; i < 3; i++) {
            scanf("%d", &a[i]);
            fact(a[i], M), m *= a[i];
        }
        for (int i = 0; i < 3; i++) {
            scanf("%d", &b[i]);
            fact(b[i], N), n *= b[i];
        }
        for (int i = 0; i < 3; i++) {
            scanf("%d", &c[i]);
            if (!i) c[i] *= 2;
            fact(c[i], S), s *= c[i];
        }
        upd(N), upd(M), upd(S);
        ans = s % m == 0;
        dfs1(0, 1);
        s = __gcd(s, m);
        for (int i = 0; i < M.size(); i++) {
            if (m / s % M[i]) { e[i] = n + 1; continue; }
            ll t = s;
            e[i] = 1;
            while (!(t % M[i])) t /= M[i], e[i] *= M[i];
            if (n / M[i] < e[i]) e[i] = n + 1;
            else e[i] *= M[i];
        }
        dfs2(0, n, 1);
        /*
        for (ll i = 1; i <= n; i++) {
            bool flag = 1;
            for (int j = 0; j < M.size(); j++) {
                flag &= (__gcd(i, m) % e[j] > 0);
            }
            if (flag) ans++;
        }
        for (ll i = 1; i <= n; i++) {
            if (!(s % __gcd(i, m))) ans++;
        }
        for (ll i = 1; i < m; i++) {
            if (!(s % i)) ans++;
        }
        */
        printf("%lld\n", ans);
    }
    return 0;
}
