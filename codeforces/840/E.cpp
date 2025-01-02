// LUOGU_RID: 160598509
#include<iostream>
#include<cstring>
#include<vector>
const int N = 50005, B = 256;
int n, q, a[N], f[9][N], g[N][B], d[N];
std::vector <int> e[N]; int s[N][2], mx[N], t;
inline void cm(int &x, int y){x = x > y ? x : y;}
void ins(int v){
    int x = 0; for(int i = 7; ~i; i--){
        int o = v >> i & 1;
        if(!s[x][o]) s[x][o] = ++t;
        x = s[x][o];
    }
}
int qr(int v){
    int x = 0, rs = 0; for(int i = 7; ~i; i--){
        int o = v >> i & 1;
        if(s[x][!o]) x=s[x][!o], rs|=1<<i;
        else x = s[x][o];
    } return rs << 8 | mx[rs ^ v];
}
void dfs(int x, int fa){
    d[x] = d[f[0][x] = fa] + 1;
    for(int i = 1; i <= 8; i++) f[i][x] = f[i - 1][f[i - 1][x]];
    if(d[x] >= B){
        memset(s, 0, sizeof s), memset(mx, 0, sizeof mx), t = 0;
        for(int i = 0, p = x; i < B; i++, p = f[0][p])
            ins(a[p]>>8), cm(mx[a[p]>>8], (a[p]&B-1)^i);
        for(int i = 0; i < B; i++) g[x][i] = qr(i);
    } for(auto v:e[x]) if(v != fa) dfs(v, x);
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    for(int i = 1, x, y; i < n; i++)
        std::cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
    dfs(1, 0); for(int i = 1, x, y; i <= q; i++){
        std::cin >> x >> y; int rs = 0, p = y;
        for(int i = 0; d[p] - d[x] >= B; p = f[8][p]) cm(rs, g[p][i++]);
        for(; p != f[0][x]; p = f[0][p]) 
        cm(rs, a[p] ^ (d[y] - d[p]));
        std::cout << rs << '\n';
    }
}