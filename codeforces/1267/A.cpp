#include <bits/stdc++.h>
#define int i64
using namespace std;

using i64 = long long;

const int MAXN = 4e5 + 5;

struct Node{
    int a, b, t;
}s[MAXN];

int n;
int pos[MAXN], cnt;

int Min[MAXN], pp[MAXN];

vector<int> ins[MAXN];
vector<int> del[MAXN];

multiset<int> S;

bool cmp(Node a, Node b) {
    return a.a < b.a;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        pos[++cnt] = a;
        pos[++cnt] = b - t + 1;
        s[i] = (Node) {a, b, t};
    }
    sort(s + 1, s + n + 1, cmp);
    sort(pos + 1, pos + cnt + 1);
    cnt = unique(pos + 1, pos + cnt + 1) - pos - 1;
    memset(Min, 0x3f, sizeof(Min));
    for (int i = n; i >= 1; i--) {
        Min[i] = min(Min[i + 1], s[i].a + s[i].t);
        pp[i] = s[i].a;
    }
    for (int i = 1; i <= n; i++) {
        int a = s[i].a, b = s[i].b, t = s[i].t;
        ins[lower_bound(pos + 1, pos + cnt + 1, a) - pos].push_back(t);
        del[lower_bound(pos + 1, pos + cnt + 1, b - t + 1) - pos].push_back(t);
    }
    int ans = 0, now = 0;
    for (int i = 0; i <= cnt; i++) {
        for (auto o : ins[i]) {
            S.insert(o);
        }
        for (auto o : del[i]) {
            S.erase(S.find(o));
        }
        // cout << now << ' ' << ans << ' ' << i << ' ' << pos[i] << '\n';
        // for (auto o : S) cout << o << ' ';
        // cout << '\n';
        if (now >= pos[cnt] || now >= pos[i + 1]) {
            continue;
        }
        if (S.empty()) {
            if (i != cnt) {
                now = Min[lower_bound(pp + 1, pp + n + 1, now) - pp], ans++;
            }
        } else {
            int tt = *S.begin(), g = (pos[i + 1] - 1 - now) / tt;
            now += g * tt, ans += g;
            now = min(now + tt, Min[lower_bound(pp + 1, pp + n + 1, now) - pp]);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}