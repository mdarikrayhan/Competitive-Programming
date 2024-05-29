#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vi = vc<int>;
using vl = vc<ll>;
using vvi = vc<vi>;
using vvl = vc<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define rev(x) reverse(ALL(x))
#define srt(x) sort(ALL(x))
#define rsrt(x) sort(rALL(x))
#define rb(_, l, r) for(int _= l; _ <= r; ++_)
#define rep(_, l, r) for(int _ = l; _ < r; ++_)
#define br(_, r, l) for(int _ = r; _ >= l; _--)
#define sz(x) (int)(x.size())
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
template<typename T> void in(vector<T>&a) {for(auto& e: a) cin>> e;}
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

void p(int x) { if (x) cout << "YES" << '\n'; else cout << "NO" << '\n'; }

template<class t> void printv(t x, char delimiter = ',', bool needBrace = true) {
    needBrace && cout << "{"; 
    for(auto it = x.begin(); it != x.end(); ) {
        cout << *it;
        it = next(it);
        if (it != x.end()) {
            cout << delimiter;
        } else {
            needBrace && cout << "}";
        }
    }
    cout << "\n";
}

#define TEST
#ifdef TEST
    #define pr(...) printf(__VA_ARGS__);
    #define db(x, ...)      debug##x(__VA_ARGS__)
    #define ldb(parm...)    do {cout << "Line:" << __LINE__ << "  "; db(parm);} while(0)
    #define debugv(v...)    do {printv(v);} while(0)
    #define debug1(a)       cout << #a << " = " << a << ' ';
    #define debug2(a,b)     do {debug1(a); debug1(b); cout << '\n';} while(0)
    #define debug3(a,b,c)   do {debug1(a); debug2(b, c);} while(0)
    #define debug4(a,b,c,d) do {debug1(a); debug3(b, c, d);} while(0)
#else
    #define db(...) "Your attitude towards suffering is the melody of life."; 
#endif

const char nl = '\n';

#define SINGLE
void solve() {
    int n, p;
    cin >> n >> p;
    vc<pii> vp;
    vi cnt(n + 1);
    map<pii, int> cnt2;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[a]++, cnt[b]++;
        if (a > b) swap(a, b);
        cnt2[{a, b}] ++;
    }
    long long ans = 0;
    for (auto&[a, b]: cnt2) {
        auto& [i, j] = a;
        if (cnt[i] + cnt[j] >= p and cnt[i] + cnt[j] - b < p)
            ans -= 1;
    }
    srt(cnt);
    for (int i = n, j = 1; i >= 1; --i) {
        while (cnt[i] + cnt[j] < p) j ++;
        if (i <= j) break;
        ans += i - j;
    }
    
    cout << ans;
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
#ifdef SINGLE
    solve();
#else
    int T; cin >> T; while (T--) solve();
#endif
    return 0;
}