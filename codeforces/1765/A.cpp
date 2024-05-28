#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
int n, m;
char ss[MAXN][MAXN];
int dfn[MAXN], low[MAXN], tot, bel[MAXN], vis[MAXN], S[MAXN], top, bcnt;
vector<int> e[MAXN], b[MAXN];
void push(int x, int y) {
    e[x].push_back(y);
}
void tar(int x) {
    dfn[x] = low[x] = ++tot;
    S[++top] = x; vis[x] = 1;
    for(auto v : e[x]) {
        if(!dfn[v]) tar(v), low[x] = min(low[x], low[v]);
        else if(vis[v]) low[x] = min(low[x], dfn[v]);
    }
    if(dfn[x] == low[x]) {
        ++bcnt;
        while(S[top] != x) {
            int v = S[top--];
            vis[v] = 0, bel[v] = bcnt;
            b[bcnt].push_back(v);
        }
        int v = S[top--];
        vis[v] = 0, bel[v] = bcnt;
        b[bcnt].push_back(v);
    }
}
int BEL[MAXN], rk[MAXN];
int ANS[MAXN];
namespace flow{
    int head[MAXN<<1], cur[MAXN<<1], dep[MAXN<<1], s, t, cnt = 1;
    struct Edge{
        int next, to, w;
    } e[MAXN*MAXN*4];
    void add(int x, int y, int w) {
        e[++cnt] = {head[x], y, w};
        head[x] = cnt;
    }
    void push(int x, int y, int w) {
        // printf("##%d %d %d\n", x, y, w);
        add(x, y, w), add(y, x, 0);
    }
    bool bfs() {
        for(int i=1;i<=t;i++) dep[i] = 0, cur[i] = head[i];
        queue<int> q; q.push(s);
        dep[s] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i=head[x];i;i=e[i].next) {
                int v = e[i].to;
                if(dep[v] || !e[i].w) continue;
                dep[v] = dep[x] + 1;
                q.push(v);
            }
        }
        return dep[t];
    }
    int dfs(int x, int in) {
        if(x == t) return in;
        int out = 0;
        for(int &i=cur[x];i;i=e[i].next) {
            int v = e[i].to;
            if(dep[v] != dep[x] + 1 || !e[i].w) continue;
            int res = dfs(v, min(in, e[i].w));
            in -= res, out += res;
            e[i].w -= res, e[i^1].w += res;
            if(!in) break;
        }
        if(!out) dep[x] = 0;
        return out;
    } 
    int nxt[MAXN], in[MAXN];
    void solve() {
        int ret = 0;
        while(bfs()) ret += dfs(s, 0x3f3f3f3f);
        // printf("ret = %d\n", ret);
        for(int x=1;x<=bcnt;x++) {
            for(int i=head[x];i;i=e[i].next) {
                int v = e[i].to;
                if(!e[i].w) {nxt[x] = v-bcnt; in[v-bcnt]++; break;}
            }
        }
        vector<vector<int>> ans;
        for(int x=1;x<=bcnt;x++) {
            if(in[x]) continue;
            // printf("x = %d\n", x);
            vector<int> v;
            int xx = x;
            while(xx) BEL[xx] = ans.size()+1, rk[xx] = v.size() + 2, v.push_back(xx), xx = nxt[xx];
            ans.push_back(v);
        }
        cout << ans.size() << '\n';
        for(int i=1;i<=m;i++) cout << BEL[bel[i]] << " \n"[i==m];
        for(int i=1;i<=m;i++) cout << rk[bel[i]] <<  " \n"[i==m];
        for(int i=1;i<=n;i++) {
            for(int j=0;j<ans.size();j++) ANS[j+1] = 1;
            for(int j=1;j<=m;j++) if(ss[i][j] == '1')
                // printf("i = %d, j = %d, rk[%d] = %d\n", i, j, bel[j], rk[bel[j]]),
                ANS[BEL[bel[j]]] = max(ANS[BEL[bel[j]]], rk[bel[j]]);
            for(int j=0;j<ans.size();j++) cout << ANS[j+1] << " \n"[j==ans.size()-1];
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        scanf("%s", ss[i]+1);
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) if(i != j) {
            bool flag = true;
            for(int k=1;k<=n;k++) {
                if(ss[k][i] < ss[k][j]) flag = false;
            }
            if(flag) push(i, j);
        }
    }
    for(int i=1;i<=m;i++) if(!dfn[i]) tar(i);
    // for(int i=1;i<=bcnt;i++) {
    //     printf("i = %d\n", i);
    //     for(auto x : b[i]) printf("%d ", x); puts("");
    // }
    flow::s = 2*bcnt+1, flow::t = 2*bcnt+2;
    for(int i=1;i<=bcnt;i++) flow::push(flow::s, i, 1), flow::push(i+bcnt, flow::t, 1);
    for(int x=1;x<=m;x++) {
        for(auto v : e[x]) if(bel[v] != bel[x]) flow::push(bel[x], bel[v]+bcnt, 1);
    }
    flow::solve();
    return 0;
}