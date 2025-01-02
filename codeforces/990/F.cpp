// LUOGU_RID: 160086798
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define mp make_pair

int n, m, cnt, a[200010], b[200010], vtd[200010], ln[200010], bd[200010];
vector<pair<int, int> > v[200010];

void dfs(int u, int fa){
    cnt += bd[u], vtd[u] = 1;
    int ind = 0;
    for(int i = 0; i < v[u].size(); i++){
        auto I = v[u][i];
        if(!vtd[I.F]){
            dfs(I.F, u);
            if(a[I.S] == u)
                ln[I.S] += bd[I.F];
            else
                ln[I.S] -= bd[I.F];
            bd[u] += bd[I.F];
        }
    }
}

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> bd[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i], --a[i], --b[i];
        v[a[i]].push_back(mp(b[i], i)), v[b[i]].push_back(mp(a[i], i));
    }
    for(int i = 0; i < n; i++)
        if(!vtd[i]){
            cnt = 0, dfs(i, -1);
            if(cnt != 0){
                puts("Impossible");
                return 0;
            }
        }
    puts("Possible");
    for(int i = 0; i < m; i++)
        cout << ln[i] << endl;
    return 0;
}