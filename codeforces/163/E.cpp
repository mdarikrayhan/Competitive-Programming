#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define deb(x)          cout << x
#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define kill(x)         {cout << (x) << '\n'; exit(0);}
#define killt(x)        {cout << (x) << '\n'; return;}
#define md(x)           ((((x)%MOD)+MOD)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 1e6 + 23;
const int LOG = 23;

int TI=1, nxt[MXN][26], f[MXN];

int Insert(string s) {
    int v=0;
    for(char c : s) {
        if(!nxt[v][c-'a']) nxt[v][c-'a'] = TI++;
        v = nxt[v][c-'a'];
    }
    return v;
}

vector<int> g[MXN];
void Aho() {
    queue<int> q;
    q.push(0);
    while(SZ(q)) {
        int v = q.front();
        q.pop();
        if(v) g[f[v]].pb(v);
        for(int c=0; c<26; c++)
            if(nxt[v][c]) {
                f[nxt[v][c]] = (v ? nxt[f[v]][c] : 0);
                q.push(nxt[v][c]);
            }
            else nxt[v][c] = nxt[f[v]][c];
    }
}

int stt[MXN], fnt[MXN], timer;
void dfs(int v) {
    stt[v] = ++timer;
    for(int u : g[v]) dfs(u);
    fnt[v] = timer+1;
}

int fen[MXN];
void Upd(int p, int x) {
    for(p+=5; p<MXN; p+=p&-p) fen[p] += x;
}
int Get(int p) {
    int res=0;
    for(p+=5; p; p-=p&-p) res += fen[p];
    return res;
}

int n, k, pos[MXN], ac[MXN];

void Main() {
    cin >> n >> k;
    for(int i=1; i<=k; i++) {
        string s;
        cin >> s;
        pos[i] = Insert(s);
    }
    Aho();
    dfs(0);
    for(int i=1; i<=k; i++) {
        ac[i] = 1;
        Upd(stt[pos[i]], 1);
        Upd(fnt[pos[i]], -1);
    }
    while(n--) {
        char tp;
        cin >> tp;
        if(tp == '?') {
            string s;
            cin >> s;
            int v=0;
            ll ans=0;
            for(char c : s)
                ans += Get(stt[v = nxt[v][c-'a']]);
            cout << ans << '\n';
        }
        else {
            int i;
            cin >> i;
            int n_ac = (tp == '+' ? +1 : -1);
            if(n_ac == ac[i]) continue;
            ac[i] = n_ac;
            Upd(stt[pos[i]], ac[i]);
            Upd(fnt[pos[i]], -ac[i]);
        }
    }
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}