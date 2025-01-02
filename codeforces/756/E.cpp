// LUOGU_RID: 160121841
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 6e5 + 5;
const ll mod = 1e9 + 7;
const ll px = 1e9;

int n;
int b[maxn], c[maxn];
ll a[maxn], f[maxn], g[maxn], sum[maxn];
char s[maxn];

struct big {
    int pos, val[1205];

    big() { memset(val, 0, sizeof(val)); val[0] = 1; }

    big operator+ (const big& x) {
        big res;
        res.val[0] = 0;
        for(int i = 0; i <= 1200; i++) {
            res.val[i] += val[i] + x.val[i];
            if(res.val[i] >= px) res.val[i] -= px, res.val[i+1]++;
        }
        return res;
    }

    big operator- (const big& x) {
        big res;
        res.val[0] = 0;
        for(int i = 0; i <= 1200; i++) {
            res.val[i] += val[i] - x.val[i];
            if(res.val[i] < 0) res.val[i] += px, res.val[i+1]--;
        }
        return res;
    }

    big operator* (ll x) {
        big res;
        res.val[0] = 0;
        for(int i = 0; i <= 1200; i++) {
            ll tmp = val[i] * x;
            res.val[i] += tmp % px, res.val[i+1] += tmp / px;
            if(res.val[i] >= px) res.val[i] -= px, res.val[i+1]++;
        }
        return res;
    }

    big operator/ (ll x) {
        big res;
        res.val[0] = 0;
        res.pos = pos;
        ll tmp = 0;
        for(int i = pos; i >= 0; i--) {
            res.val[i] = (tmp + val[i]) / x;
            tmp = (tmp + val[i]) % x * px;
            if(!res.val[i] && i == res.pos) res.pos--;
        }
        return res;
    }

    void init(char* s) {
        int n = strlen(s+1);
        val[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1200; j >= 0; j--) {
                ll tmp = val[j] * 10ll;
                val[j] = tmp % px;
                val[j+1] += tmp / px;
            }
            val[0] += s[i] - '0';
            for(int j = 0; j <= 1200; j++)
                if(val[j] >= px) val[j] -= px, val[j+1]++;
        }
        pos = 1200;
    }

    bool empty() {
        for(int i = 0; i <= 1200; i++)
            if(val[i]) return false;
        return true;
    }
} m, D[10005];

int main() {
    scanf("%d", &n);
    a[1] = 1;
    for(int i = 2; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    scanf("%s", s+1);
    m.init(s);

    big now = m;
    for(int i = 2; i <= n; i++) {
        if(now.empty()) { n = i-1; break; }
        if(a[i] != 1) {
            big tmp = now / a[i];
            c[i] = (now - tmp * a[i]).val[0];
            now = tmp;
        }
    }
    int limit = 0;
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        memcpy(g, f, sizeof(long long[limit + 1]));
        memset(f, 0, sizeof(long long[limit + 1]));
        for(int j = c[i]; j <= limit; j += a[i])
            f[j / a[i]] = g[j];
        limit = limit / a[i] + b[i];
        for(int j = 1; j <= limit + 1; j++)
            sum[j] = (sum[j-1] + f[j-1]) % mod;
        for(int j = 0; j <= limit; j++)
            f[j] = (sum[j+1] - sum[max(0, j - b[i])] + mod) % mod;
    }
    for(int i = 1; i <= 1200; i++)
        if(now.val[i]) { printf("%d\n", 0); return 0; }
    if(now.val[0] > limit) { printf("%d\n", 0); return 0; }
    printf("%lld\n", f[now.val[0]]);
    return 0;
}