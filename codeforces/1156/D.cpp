// LUOGU_RID: 160177684
// https://www.luogu.com.cn/problem/CF1156D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, m;
int root, mxs, sum;

vector<int> del, siz;
vector<vector<vector<int>>> adj;
vector<int> q1, q2, q;
int res = 0;

void get_root(int x, int fa) {
    siz[x] = 1;
    int s = 0;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        get_root(y, x);
        siz[x] += siz[y];
        s = max(s, siz[y]);
    }
    s = max(s, sum - siz[x]);
    if (s < mxs) {
        mxs = s;
        root = x;
    }
}
// v = 0 -> 00
// v = 1 -> 01
// v = 2 -> 10
// v = 3 -> 11

void get_dis(int x, int fa, int v) {
    q1[v]++;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        if (v == 0 && w == 0) {
            get_dis(y, x, 0);
        } else if (v == 0 && w == 1) {
            get_dis(y, x, 1);
        } else if (v == 1 && w == 1) {
            get_dis(y, x, 1);
        } else if (v == 2 && w == 0) {
            get_dis(y, x, 2);
        } else if (v == 3 && w == 0) {
            get_dis(y, x, 2);
        } else if (v == 3 && w == 1) {
            get_dis(y, x, 3);
        }
    }
}

void calc(int x) {
    q2 = vector<int> (4);
    vector<vector<int>> q;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        q1 = vector<int> (4);
        if (w == 0) {
            get_dis(y, x, 0);
        } else {
            get_dis(y, x, 3);
        }
        q.push_back(q1);
        q2[0] += q1[0];
        q2[1] += q1[1];
        q2[2] += q1[2];
        q2[3] += q1[3];
    }
    // v = 0 -> 00
    // v = 1 -> 01
    // v = 2 -> 10
    // v = 3 -> 11
    // 点分治经典分类讨论计数
    for (int i = 0; i < q.size(); i++) {
        res += q[i][0] * (q2[0] + q2[1] + q2[3] - q[i][0] - q[i][1] - q[i][3] + 1);
        res += q[i][2] * (q2[3] - q[i][3] + 1);
        res += q[i][3] * (q2[3] - q[i][3] + 1);
    }
    res += q2[0] + q2[1] + q2[3];
}

void divide(int x) {
    calc(x);
    del[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        mxs = sum = siz[y];
        get_root(y, 0);
        divide(root);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n;
    del = vector<int> (n + 1);
    siz = vector<int> (n + 1);
    adj = vector<vector<vector<int>>> (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    mxs = sum = n;
    get_root(1, 0);
    get_root(root, 0);
    divide(root);
    cout << res << endl;
    return 0;
}
