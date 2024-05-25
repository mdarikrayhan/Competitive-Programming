#include <bits/stdc++.h>
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define PB push_back
#define ll long long
#define int long long
#define ii pair<int, int>
#define pli pair<ll, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define  rep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rrep(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FOR rep
#define FORD rrep
#define FORV(v, H) for(auto &v: H)
#define reset(c, x) memset(c, x, sizeof(c))
#define MASK(i) (1LL << (i))
#define BIT(mask, i) ((mask >> i) & 1)
#define ONBIT(mask, i) (mask | (1LL << (i)))
#define OFFBIT(mask, i) (mask &~ (1LL << (i)))
#define REV(mask, i) (mask ^ (1LL << (i)))
#define CNTBIT __builtin_popcountll
#define lwb lower_bound
#define upb upper_bound
#define all(v) v.begin(), v.end()
#define SZ(v) (int) v.size()
#define special(v) v.erase(unique(all(v)), v.end())
#define sp ' '
#define nl '\n'
#define pyes print("YES")
#define pno print("NO")

using namespace std;

const string task = "896A";

const long long oo = 1e18 + 7;
const int INF      = INT_MAX;
const int MAXN     = 2e5 + 7;
const int MOD      = 1e9 + 7;
const int MAXV     = 1e6 + 7;
const int base     = 311;

template <class X, class Y> bool maximize(X &a, const Y &b) {
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
    if(a > b) return a = b, true;
    return false;
}

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

int test;
int N;
ll K;

//ll f[(int) 1e6 + 10];

const string A = "What are you doing at the end of the world? Are you busy? Will you save us?";

const string S1 = "What are you doing while sending \"";

const string S2 = "\"? Are you busy? Will you send \"";

const string S3 = "\"?";

int sa, s1, s2, s3;
int ma_id;

ll f[(int) 1e5 + 10];

char solve(int i, ll k) {

    if(i == 0) return A[k - 1];
//    if(i <= ma_id && k > f[i]) return '.';
    if(k <= s1) return S1[k - 1];
    k -= s1;
    if(k <= f[i - 1]) return solve(i - 1, k);
    k -= f[i - 1];
    if(k <= s2) return S2[k - 1];
    k -= s2;
    if(k <= f[i - 1]) return solve(i - 1, k);
    k -= f[i - 1];
    return S3[k - 1];
}

void roxy() {
    cin >> N >> K;

    if(K > f[N]) {
        cout << '.';
        return;
    }

    cout << (solve(N, K));
}

void iamtainguyen() {

    sa = SZ(A);
    s1 = SZ(S1);
    s2 = SZ(S2);
    s3 = SZ(S3);

    rep(i, 1, 1e5) f[i] = oo;

    f[0] = sa;
    rep(i, 1, 1e5) {
        f[i] = s1 + f[i - 1] + s2 + f[i - 1] + s3;
//        cerr << f[i] << sp;
        if(f[i] > 1e18) break;
    }

//    print(ma_id);

//    print(f[1]);

    cin >> test;

    while(test--) {
        roxy();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen((task + ".inp").c_str(), "r")) {
        freopen((task + ".inp").c_str(), "r", stdin);
        freopen((task + ".out").c_str(), "w", stdout);
    }

    iamtainguyen();



    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";

    return 0;
}
