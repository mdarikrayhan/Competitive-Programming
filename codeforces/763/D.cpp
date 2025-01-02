#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

mt19937_64 rnd;
int n;
map<ull, int> H;
vector<ull> chHashes;
vector<int> hashDown, hashUp, rootHash;
vector<ull> R;
vector<vector<int>> G;
vector<int> counter, par, res;
int hMax = 0, cnt_good = 0;

void update_counter(int h, int d)
{
    if (counter[h] != 0)
        cnt_good--;
    counter[h] += d;
    if (counter[h] != 0)
        cnt_good++;
}

void dfs(int v, int p = -1)
{
    for (int u : G[v])
    {
        if (u == p) continue;
        par[u] = v;
        dfs(u, v);
        chHashes[v] += R[hashDown[u]];
    }
    if (!H.count(chHashes[v]))
    {
        R[hMax] = rnd();
        H[chHashes[v]] = hMax++;
    }
    hashDown[v] = H[chHashes[v]];
    update_counter(hashDown[v], 1);
}

void dfs2(int v, int p = -1)
{
    if (p != -1)
    {
        chHashes[p] -= R[hashDown[v]];
        if (par[p] != -1)
            chHashes[p] += R[hashUp[p]];
        if (!H.count(chHashes[p]))
        {
            R[hMax] = rnd();
            H[chHashes[p]] = hMax++;
        }
        hashUp[v] = H[chHashes[p]];
        chHashes[p] += R[hashDown[v]];
        if (par[p] != -1)
            chHashes[p] -= R[hashUp[p]];
        
        chHashes[v] += R[hashUp[v]];
        if (!H.count(chHashes[v]))
        {
            R[hMax] = rnd();
            H[chHashes[v]] = hMax++;
        }
        rootHash[v] = H[chHashes[v]];
        chHashes[v] -= R[hashUp[v]];
    }
    for (int u : G[v])
    {
        if (u == p) continue;
        dfs2(u, v);
    }
}

void dfs3(int v, int p = -1)
{
    if (p != -1)
    {
        update_counter(hashDown[p], -1);
        update_counter(hashUp[v], 1);
        
        update_counter(hashDown[v], -1);
        update_counter(rootHash[v], 1);
        res[v] = cnt_good;
        update_counter(rootHash[v], -1);
        update_counter(hashDown[v], 1);
    }else
        res[v] = cnt_good;
    for (int u : G[v])
    {
        if (u == p) continue;
        dfs3(u, v);
    }
    if (p != -1)
    {
        update_counter(hashDown[p], 1);
        update_counter(hashUp[v], -1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("../output.txt", "w", stdout);
    freopen("../input.txt", "r", stdin);
#endif
    rnd.seed((int)time(0));
    cin >> n;
    chHashes.assign(n, 0);
    hashDown.assign(n, 0);
    hashUp.assign(n, 0);
    rootHash.assign(n, 0);
    G.assign(n, vector<int>());
    counter.assign(4 * n, 0);
    R.assign(4 * n, 0);
    par.assign(n, -1);
    res.assign(n, 0);
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v; v--; u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(0);
    dfs2(0);
    dfs3(0);
    cout << max_element(res.begin(), res.end()) - res.begin() + 1 << '\n';
    return 0;
}