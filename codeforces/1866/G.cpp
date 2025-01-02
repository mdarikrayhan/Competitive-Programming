#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define BIT(i) (1LL << (i))
#define GBIT(mask,i) (((mask) >> (i)) & 1)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define sz(v) ((int)v.size())
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FOD(i,a,b) for(int i = a; i >= b; --i)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 2e9 + 7;
const long long infll = 1e18 + 7;

template<class T1,class T2> bool maximize(T1 &a,T2 b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1,class T2> bool minimize(T1 &a,T2 b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

#define MAX 200005

int n;
int a[MAX],d[MAX];
vector<pii> g[MAX];

bool check(ll x) {
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    FOR(i,1,n) {
        for(pii x:g[i]) pq.push(x);
        int tmp = x;
        while(sz(pq) && tmp >= 0) {
            pii t = pq.top();
            pq.pop();
            if(t.fi < i) return 0;
            if(t.se <= tmp) {
                tmp -= t.se;
            }
            else {
                t.se -= tmp;
                pq.push(t);
                break;
            }
        }
        if(sz(pq) && pq.top().fi <= i) return 0;
    }
    if(sz(pq)) return 0;
    return 1;
}

void process() {
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> d[i];
    FOR(i,1,n) {
        int L = max(1,i - d[i]);
        int R = min(n,i + d[i]);
        g[L].pb({R,a[i]});
    }
    int l = 0,r = inf,mid,res = r;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1,res = mid;
        else l = mid + 1;
    }
    cout << res;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #define TASK ""
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    if(fopen("main.inp","r")) {
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    srand(time(0));

    process();

    cerr << "\n" << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms";
    return 0;
}
