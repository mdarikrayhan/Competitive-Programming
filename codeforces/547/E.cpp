// LUOGU_RID: 159993085
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define per(i, a, b) for(int i = a; i >= b; i --)
#define vi vector<int>
#define fi first
#define se second
#define endl '\n'
#define ull unsigned long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define sz(v) ((int) v.size())
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x <  0) x += mod;
    return x;
}
int mul(int x, int y){
    return x * y %mod;
}
void upd(int &ans, int v){
    ans = add(ans, v);
}
const int N = 2e5 + 10;
int idx;
int ne[N], ch[N][26], fa[N];
int End[N];

vector<int> g[N];
vector<pair<int, int>> que[N];
int dfn[N], out[N], ts;

int tr[N];
int lowbit(int x){ return x & -x; }
void change(int x, int v){
    for(int i = x; i <= idx + 10; i += lowbit(i)) tr[i] += v;
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<string> str(n + 1);

    auto insert = [&](string S, int id) -> void{
        int p = 0;
        for(int i = 0; i < sz(S); i ++){
            if(!ch[p][S[i] - 'a']){
                ch[p][S[i] - 'a'] = ++ idx;
            }
            fa[ch[p][S[i] - 'a']] = p;
            p = ch[p][S[i] - 'a'];
        }
        End[id] = p;
    };
    auto dfs = [&](auto&&dfs, int u, int father) ->void{
        dfn[u] = ++ ts;
        for(auto v : g[u]){
            if(v == father) continue;
            dfs(dfs, v, u); 
        }
        out[u] = ts;
    };
    auto build = [&]() -> void{
        queue<int> q;
        for(int i = 0; i < 26; i ++){
            if(ch[0][i]){
                q.push(ch[0][i]);
            }
        }
        while(!q.empty()){
            auto u = q.front(); q.pop();
            for(int i = 0; i < 26; i ++){
                int v = ch[u][i];
                if(v){
                    ne[v] = ch[ne[u]][i];
                    q.push(v);
                }else{
                    ch[u][i] = ch[ne[u]][i];
                }
            }
        }
        for(int i = 1; i <= idx; i ++){
            g[ne[i]].push_back(i);
        }
        dfs(dfs, 0, 0);
    };

    for(int i = 1; i <= n; i ++){
        cin >> str[i];
        insert(str[i], i);
    }
    build();
    vector<int> ans(q + 1, 0);
    for(int i = 1; i <= q; i ++){
        int l, r, k; cin >> l >> r >> k;
        que[l - 1].push_back({k, -i});
        que[r].push_back({k, i});
    }
    for(int i = 1; i <= n; i ++){
        string T = str[i];
        int p = End[i];
        // cout << p << " " << dfn[p] << endl;
        while(p != 0){
            change(dfn[p], 1);
            p = fa[p];
        }
        // *** 
        for(auto v : que[i]){
            int u = v.fi, id = abs(v.se), k = v.se / id;
            ans[id] += k * (query(out[End[u]]) - query(dfn[End[u]] - 1));
        //    cout << out[End[u]] << " " << dfn[End[u]] - 1 << endl;
        }
    }
    for(int i = 1; i <= q; i ++){
        cout << ans[i] << endl;
    }

    return 0;
}