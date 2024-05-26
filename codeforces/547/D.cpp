#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;
int n, h[N], l[N], col[N];
vector<int> G[N];

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (!h[x]) h[x] = i;
        else G[i].push_back(h[x]), G[h[x]].push_back(i), h[x] = 0;
        if (!l[y]) l[y] = i;
        else G[i].push_back(l[y]), G[l[y]].push_back(i), l[y] = 0;
    }
	Check();
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) cout << 'r';
        else cout << 'b';
    }
	return 0;
}
		 			  	  					 						 	  		