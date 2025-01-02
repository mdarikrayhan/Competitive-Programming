#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5+10;
vector <int> ad[N], rad[N];
vector <int> topo;
bool vis[N];

int ans[N];

void dfs(int node) {
    vis[node] = 1;
    for(int v:ad[node]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    topo.push_back(node);
}

void dfs2(int node, int cc) {
    ans[node] = cc;
    vis[node] = 1;
    for(int v:rad[node]) {
        if(!vis[v]) {
            dfs2(v, cc);
        }
    }
}


void solve() {
    int n, k; cin >> n >> k;
    int p1[n], p2[n];
    for(int i=0; i<n; i++) {
        cin >> p1[i];
        if(i) {
            ad[p1[i]].push_back(p1[i-1]);
            rad[p1[i-1]].push_back(p1[i]);
        }
    }
    for(int i=0; i<n; i++) {
        cin >> p2[i];
        if(i) {
            ad[p2[i]].push_back(p2[i-1]);
            rad[p2[i-1]].push_back(p2[i]);
        }
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, 0, sizeof vis);
    reverse(topo.begin(), topo.end());
    int cc = 0;
    for(int i=0; i<n; i++) {
        if(!vis[topo[i]]) {
            dfs2(topo[i], cc);
            cc++;
        }
    }
    if(cc < k) {
        cout << "NO\n";
        return;
    }

    map <int, char> mchar;
    char st = 'z';
    for(int i=0; i<cc; i++) {
        mchar[i] = st;
        char ch = st-1;
        st = max('a', ch);
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++) {
        cout << mchar[ans[i]];
    }
    cout << "\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}
			  		   	   	 	 		  	 					