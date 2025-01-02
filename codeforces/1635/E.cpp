#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 5;
int n, m, t[N], a[N], b[N], col[N], in[N], ans[N];
vector<int> G[N], GG[N];
queue<int> q;

bool DFS(int u, int color) {
	col[u] = color;
	for (int v : G[u]) {
		if (col[v] && col[u] == col[v]) return 0;
		if (!col[v] && !DFS(v, 3 - color)) return 0;
	}
	return 1;
}

bool Check() {
	bool ok = 1;
	for (int i = 1; i <= n; i++) {
		if (!col[i]) ok &= DFS(i, 1);
	}
	return ok;
}

bool Topo() {
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        ans[u] = ++cnt;
        q.pop();
        for (int v : GG[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    return cnt != n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
	if (!Check()) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 1) {
            if (col[a[i]] == 1) GG[a[i]].push_back(b[i]), in[b[i]]++;
            else GG[b[i]].push_back(a[i]), in[a[i]]++;
        }
        else {
            if (col[a[i]] == 2) GG[a[i]].push_back(b[i]), in[b[i]]++;
            else GG[b[i]].push_back(a[i]), in[a[i]]++;
        }
    }
    if (Topo()) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) cout << "L ";
        else cout << "R ";
        cout << ans[i] << '\n';
    }
	return 0;
}
						 	  			 		 			 		   	   	