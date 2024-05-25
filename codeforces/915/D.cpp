// LUOGU_RID: 160236049
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 510;
vector<int> e[N];
int deg[N], in[N], n;

bool topo (void)
{
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!in[i]) q.push (i);
    while (!q.empty ()) {
        int u = q.front (); q.pop ();
        for (auto v : e[u]) if (!--in[v]) q.push (v);
    } 
    for (int i = 1; i <= n; i++) if (in[i] > 0) return false;
    return true;
}

int main (void)
{
    int m;
    queue<int> q;

    ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, e[u].push_back (v), deg[v]++;
    memcpy (in, deg, sizeof deg);
    if (topo ()) cout << "YES\n", exit (0);
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) continue; 
        memcpy (in, deg, sizeof deg), in[i]--;
        if (topo ()) cout << "YES\n", exit (0);
    }
    cout << "NO\n";
    return 0;
}