#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define pii pair<int, int>
// #define int long long 

const int MX = 1e5 + 5;
vector<int> gr[MX];
vector<int> regions[MX];
int sz[MX], del[MX], ans[MX];
pii a[MX];
int n, m;

int cnt(pii x){
    int cw = x.second - x.first - 1; //clockwise
    int ccw = n - 2 - cw; //counter - clockwise
    return min(cw, ccw);
}

int dfs(int u, int p){
    sz[u] = 1;
    for(int v : gr[u]){
        if(v != p && !del[v]){
            sz[u] += dfs(v, u);
        }
    }
    return sz[u];
}

int centroid(int u, int p, const int &n){
    for(int v : gr[u]){
        if(v != p && !del[v] && sz[v]*2 >= n){
            return centroid(v, u, n);
        }
    }
    return u;
}

void decompose(int u, int p){
    dfs(u, 0);
    u = centroid(u, 0, sz[u]);
    del[u] = 1, ans[u] = ans[p] + 1;
    
    for(int v : gr[u]){
        if(!del[v]){
            decompose(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("main.inp","r",stdin);
    // freopen("main.out","w",stdout);

    cin>>n>>m;

    for(int i=1; i<=m; ++i){
        int u, v;
        cin>>u>>v;
        if(u > v){
            swap(u, v);
        }
        a[i] = {u, v};
    }

    //regions with less points go first
    sort(a+1, a+m+1, [](pii x, pii y){ 
        return cnt(x) < cnt(y);
    });

    set<int> cur;
    for(int i=1; i<=n; ++i){
        cur.insert(i);
    }

    set<int> :: iterator it;
    int k = 1;
    for(int i=1; i<=m; ++i, ++k){
        int x, y;
        tie(x, y) = a[i];
        int cw = y - x - 1;
        int ccw = n - 2 - cw;

        if(cw < ccw){
            regions[k].push_back(x);
            it = cur.upper_bound(x);
            while(it != cur.end() && *it < y){
                regions[k].push_back(*it);
                ++it;
                cur.erase(prev(it));
            }
            regions[k].push_back(y);
        }
        else{
            regions[k].push_back(y);
            it = cur.upper_bound(y);
            while(it != cur.end()){
                regions[k].push_back(*it);
                ++it;
                cur.erase(prev(it));
            }
            it = cur.begin();
            while(it != cur.end() && *it < x){
                regions[k].push_back(*it);
                ++it;
                cur.erase(prev(it));
            }
            regions[k].push_back(x);
        }
        sort(regions[k].begin(), regions[k].end(), greater<int>());
    }

    if(cur.size()){
        for(int x : cur){
            regions[k].push_back(x);
        }
        reverse(regions[k].begin(), regions[k].end());
    }

    sort(regions+1, regions+k+1); //order of importance
    
    map<pii, int> side;
    for(int i=1; i<=k; ++i){ //construct graph
        int m = regions[i].size();
        for(int j=0; j<m; ++j){
            int x = regions[i][j], y = regions[i][(j+1) % m];
            if(x > y){
                swap(x, y);
            }
            if(side.count({x, y})){
                int idx = side[{x, y}];
                gr[idx].push_back(i);
                gr[i].push_back(idx);
            }   
            else{
                side[{x, y}] = i;
            }
        }
    }

    decompose(1, 0);
    for(int i=1; i<=k; ++i){
        cout<<ans[i]<<' ';
    }

    return 0;
}