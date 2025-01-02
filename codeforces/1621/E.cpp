// LUOGU_RID: 160339366
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;

int n, m, T;
int a[MAXN];
int f[MAXN], g[MAXN], h[MAXN];

struct Node {
    double avg;
    ll sum;
    int id, k;
    vector<int> b, ans;
    bool operator <(const Node &rhs) const {
        return avg > rhs.avg;
    }
} p[MAXN], tmp;

bool cmp2(Node a, Node b) {
    return a.id < b.id;
}

int Q(int *a, int l, int r) {
    if (r < l) return 0;
    return a[r] - a[l - 1];
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i].k);
        p[i].id = i;
        p[i].b.clear();
        p[i].ans.clear();
        p[i].sum = 0;
        for (int j = 1, x; j <= p[i].k; j++) {
            scanf("%d", &x);
            p[i].b.push_back(x);
            p[i].ans.push_back(1);
            p[i].sum += x;
        }
        // printf("%d %d\n", p[i].sum, p[i].id);
        p[i].avg = 1.0 * p[i].sum / p[i].k;
    }
    sort(p + 1, p + m + 1);
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= m; i++) {
        if (a[i] < p[i].avg) f[i] = 1;
        else f[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        f[i] += f[i - 1];
    }
    for (int i = 1; i < m; i++) {
        if (a[i] < p[i + 1].avg) g[i] = 1;
        else g[i] = 0;
    }
    for (int i = 1; i < m; i++) {
        g[i] += g[i - 1];
    }
    for (int i = 2; i <= m; i++) {
        if (a[i] < p[i - 1].avg) h[i] = 1;
        else h[i] = 0;
    }
    for (int i = 2; i <= m; i++) {
        h[i] += h[i - 1];
    }
    // for (int i = 1; i <= m; i++) {
    //     printf("%.5lf ", p[i].avg);
    // }
    // puts("");
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < p[i].k; j++) {
            double new_avg = 1.0 * (p[i].sum - p[i].b[j]) / (p[i].k - 1);
            tmp.avg = new_avg;
            // printf("%.5lf\n", new_avg);
            int s = lower_bound(p + 1, p + m + 1, tmp) - p;
            if (s == i) {
                if (new_avg > a[s] || Q(f, 1, i - 1) + Q(f, i + 1, m) > 0) 
                    p[i].ans[j] = 0;
                else
                    p[i].ans[j] = 1;
            }
            if (s > i) {
                s -= 1;
                if (new_avg > a[s] || Q(f, 1, i - 1) + Q(f, s + 1, m) + Q(g, i, s - 1) > 0) 
                    p[i].ans[j] = 0;
                else 
                    p[i].ans[j] = 1;
            }
            if (s < i) {
                if (new_avg > a[s] || Q(f, 1, s - 1) + Q(f, i + 1, m) + Q(h, s + 1, i) > 0)
                    p[i].ans[j] = 0;
                else
                    p[i].ans[j] = 1;
            }
            // printf("%d\n", s);
        }
    }
    sort(p + 1, p + m + 1, cmp2);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < p[i].k; j++)
            printf("%d", p[i].ans[j]);
    }
    puts("");
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) solve();   
}