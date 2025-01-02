#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define FOR(i, x, n) for(int i = x; i < n; i++)
#define F0R(i, n) FOR(i, 0, n)
#define ROF(i, x, n) for(int i = n - 1; i >= x; i--)
#define R0F(i, n) ROF(i, 0, n)

#define WTF cout << "WTF" << endl

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define EP emplace_back

#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x,rend()

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int LOG = 22;
const int A = 26;
const int SQ = 320;
const int MOD = 1e9 + 7;

struct Edge {
    int s, t, cap, val;

    Edge (int a, int b, int c, int d) {
        s = a;
        t = b;
        cap = c;
        val = d;
    }

    int ep(int x) {
        return (s == x ? t : s);
    }

    bool forward(int x) {
        return (x == s);
    }
};

int n, m;
bool done, seen[N];
VI pr, adj[N];
VPII odds, evens;
vector<Edge> eset;

bool isPrime(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;

    for(int i = 2; i * i <= x; i++) 
        if (x % i == 0) return 0;
    return 1;
}

void dfs(int now) {
    seen[now] = 1;
    if (now == m + n + 1) {
        done = 1;
        return;
    }

    for(int id : adj[now]) {
        int on = eset[id].ep(now);

        if (!seen[on]) {
            if (eset[id].forward(now) && eset[id].cap > eset[id].val) {
                eset[id].val++;
                dfs(on);
                if (done) return;
                eset[id].val--;
            }

            if (!eset[id].forward(now) && eset[id].val > 0) {
                eset[id].val--;
                dfs(on);
                if (done) return;
                eset[id].val++;
            }
        }
    }

    return;
}

void calc(int now) {
    seen[now] = 1;
    pr.PB(now);
    for(int id : adj[now]) if (!seen[ eset[id].ep(now) ] && eset[id].val == 1) calc(eset[id].ep(now));
    return;
}

int main() {
    IOS;
    
    cin >> n;
    F0R(i, n) {
        int x; cin >> x;
        if (x & 1) odds.PB({x, i});
        else evens.PB({x, i});
    }

    n = odds.size(); 
    m = evens.size();
    F0R(i, n) F0R(j, m) {
        if (isPrime(odds[i].F + evens[j].F)) {
            //cout << odds[i] + evens[j] << endl;
            eset.emplace_back(Edge(i, j + n, 1, 0));
            adj[i].PB(eset.size() - 1);
            adj[j + n].PB(eset.size() - 1);
        }
    }

    F0R(i, n) {
        eset.emplace_back(Edge(n + m, i, 2, 0));
        adj[n + m].PB(eset.size() - 1);
        adj[i].PB(eset.size() - 1);
    }

    FOR(i, n, n + m) {
        eset.emplace_back(Edge(i, n + m + 1, 2, 0));
        adj[n + m + 1].PB(eset.size() - 1);
        adj[i].PB(eset.size() - 1);
    }

    done = 1;
    while(done) {
        fill(seen, seen + m + n + 2, 0);
        done = 0;
        dfs(m + n);
    }

    fill(seen, seen + n + m + 2, 0);

    vector<VI> anss;
    F0R(i, n) {
        if (!seen[i]) {
            pr.clear();
            calc(i);

            anss.emplace_back(pr);
            pr.clear();
        }
    }

    int ans = 0;
    for(int id : adj[m + n]) {
        ans += eset[id].val;
        if (eset[id].val < 2) {
            cout << "Impossible";
            return 0;
        }
    }
    //cout << ans;
    //return 0;

    //return 0;
    for(int id : adj[m + n + 1]) if (eset[id].val < 2) {
        cout << "Impossible";
        return 0;
    }

    cout << anss.size() << endl;
    for(VI v : anss) {
        cout << v.size() << ' ';
        for(int on : v) cout << (on < n ? odds[on].S : evens[on - n].S) + 1 << ' ';
        cout << endl;
    }

    return 0;
}
