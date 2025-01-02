/*
Mayoeba Yabureru
*/
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> gr(n + 1);
    vector<int> dis(n + 1), del(n + 1), siz(n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    function<void(int, int)> go = [&] (int x, int p) {
        dis[x] = dis[p] + 1;
        for (auto u : gr[x]) {
            if (p == u || del[u]) continue;
            go(u, x);
        }
    };
    go(1, 0);
    function<void(int, int)> goo = [&] (int x, int p) {
        del[x] = 1;
        for (auto u : gr[x]) {
            if (p == u || del[u]) continue;
            goo(u, x);
        }
    };

    function<void(int, int, int &)> dfs = [&] (int x, int p, int &size) {
        siz[x] = 1;
        size ++;
        for (auto u : gr[x]) {
            if (p == u || del[u]) continue;
            dfs(u, x, size);
            siz[x] += siz[u];
        }
    };
    int size = 0;
    function<void(int, int, int &)> rootShift = [&] (int x, int p, int &centroid) {
        int f = 1;
        for (auto u : gr[x]) {
            if (del[u]) continue;
            if (siz[u] * 2 > size) f = 0;
        }
        if (f) centroid = x;
        for (auto u : gr[x]) {
            if (p == u || del[u]) continue;
            siz[x] -= siz[u];
            siz[u] += siz[x];
            rootShift(u, x, centroid);
            siz[u] -= siz[x];
            siz[x] += siz[u];
        }
    };

    function ask = [&] (char c, int x) {
        cout << c << ' ' << x << endl;
        int ans;
        cin >> ans;
        assert(ans != -1);
        return ans;
    };
    int odis = ask('d', 1);

    vector<int> nodes;
    for (int i = 1; i <= n; i ++) nodes.push_back(i);

    while (nodes.size() != 1) {
        assert(nodes.size() != 0);
        size = 0;
        int centroid = nodes[0];
        dfs(nodes[0], 0, size);
        rootShift(nodes[0], 0, centroid);
        int a = ask('d', centroid);

        if (a == 0) {
            cout << "! " << centroid << endl;
            return;
        }
        if (odis != a + dis[centroid] - 1) {
            int pr = 0;
            for (auto x : gr[centroid]) {
                if (dis[x] < dis[centroid]) pr = x;
            }
            goo(centroid, pr);
        }
        else {
            a = ask('s', centroid);
            goo(centroid, a);
        }

        nodes.clear();
        for (int i = 1; i <= n; i ++) {
            if (del[i] == 0) nodes.push_back(i);
        }
    }
    cout << "! " << nodes[0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;

    while ( T -- ){
        solve();
    }
}