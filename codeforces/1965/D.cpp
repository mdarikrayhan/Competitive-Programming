// LUOGU_RID: 160620438
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int T, n, m, tot;
int a[MAXN], b[MAXN];
int c[MAXN], s[MAXN], d[MAXN];
map<int, int> mp;

void init() {
    m = tot = 0;
    mp.clear();
}

int construct(int len) {
    int idx = (len + 1) / 2;
    for (int i = m; i >= 1; i--) {
        b[i] -= b[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        // printf("check %d %d %d\n", i, idx, b[i]);
        if (idx == len + 1 - idx) c[idx] = b[i];
        else c[idx] = c[len + 1 - idx] = b[i] / 2;
        --idx;
    }
    int res = 0;
    for (int i = 1; i <= len; i++) {
        res += c[i];
        // printf("%d ", c[i]);
    }
    // puts("");
    tot = 0;
    for (int i = 1; i <= len; i++) {
        int sum = 0;
        for (int j = i; j <= len; j++) {
            sum += c[j];
            s[++tot] = sum;
        }
    }
    return res;
}

int diff() {
    vector<int> f, g;
    for (int i = 1; i <= tot; i++) {
        f.push_back(s[i]);
    }
    for (int i = 1; i < n * (n + 1) / 2; i++) {
        g.push_back(a[i]);
    }
    sort(f.begin(), f.end());
    sort(g.begin(), g.end());
    if (f.size() < g.size()) swap(f, g);
    while (!g.empty() && f.back() == g.back()) {
        f.pop_back();
        g.pop_back();
    }
    return f.back();
}

void solve() {
    scanf("%d", &n);
    init();
    for (int i = 1; i < n * (n + 1) / 2; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    for (auto [x, y] : mp) {
        if (y & 1) 
            b[++m] = x;
    }
    // printf("m: %d\n", m);
    sort(b + 1, b + m + 1);
    // for (int i = 1; i <= m; i++) {
    //     printf("%d ", b[i]);
    // }
    // puts("");
    if (m == (n + 1) / 2 - 1) {
        int y = construct(n - 2);
        int x = diff();
        int mis = 2 * x - y;
        mp[mis]++;
        // printf("mis: %d\n", mis);
    } else {
        vector<int> odd, even;
        for (int i = 1; i <= m; i++) {
            if (b[i] & 1) odd.push_back(b[i]);
            else even.push_back(b[i]);
        }
        if (!odd.empty() && !even.empty()) {
            // puts("11111");
            int mis;
            if (n & 1) {
                if (odd.size() == 1) mis = odd[0];
                else mis = even[0];
            } 
            else mis = odd[0];
            mp[mis]++;
            // printf("mis: %d\n", mis);
        } else {
            // puts("22222");
            int y = construct(n + 2);
            int x = diff();
            int mis = 2 * x - y;
            mp[mis]++;
            // printf("mis: %d\n", mis);
        }
    }
    m = 0;
    for (auto [x, y] : mp) {
        if (y & 1)
            b[++m] = x;
    }
    sort(b + 1, b + m + 1);
    // for (int i = 1; i <= m; i++) {
    //     printf("%d ", b[i]);
    // }
    // puts("");
    construct(n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", c[i]);
    }
    puts("");
}


int main() {
    scanf("%d", &T);
    while (T--) solve();
}