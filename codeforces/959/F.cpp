// LUOGU_RID: 159518111
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;

const int N = 200005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, m, v[N];
struct xj {
    int p[32], cnt;
    void clear() {
        memset(p, 0, sizeof p);
    }
    void ins(int x) {
        dF(i, 31, 0) {
            if (x >> i & 1) {
                if (!p[i]) {
                    p[i] = x;
                    cnt ++;
                    return ;
                }
                x ^= p[i];
            }
        }
    }
    int chk(int x) {
        dF(i, 31, 0) {
            if (x >> i & 1) {
                if (!p[i]) {
                    return 0;
                }
                x ^= p[i];
            }
        }
        return 1;
    }
} a[N];
int qpow(int a, int b = mod - 2) {
    int res = 1; 
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 1, n) {
        cin >> v[i];
        a[i] = a[i - 1];
        a[i].ins(v[i]);
    }
    F(i, 1, m) {
        int l, x;
        cin >> l >> x;
        if (!a[l].chk(x)) {
            cout << "0\n";
        } else {
            cout << qpow(2, l - a[l].cnt) << '\n';
        }
    }
    return 0;
}
