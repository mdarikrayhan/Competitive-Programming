#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cpx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound(ALL(v), x) - (v).begin())
#define ubv(v, x) (upper_bound(ALL(v), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
template <typename T, typename U>
ostream& operator<<(ostream &os, pair<T, U> p){return os << "(" << p.fs << ", " << p.sn << ")";}

const int MOD = 20240401;

const int MN = 1e5 + 5;
int dp[MN][2];

int solve(vi vec){
    ms(dp, 0);
    dp[0][0] = dp[0][1] = 1;
    FR(i, SZ(vec)){
        if(vec[i] == 0){
            dp[i+1][0] = dp[i][0];
        }
        else if(vec[i] == 1){
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = dp[i][0];
        }
        else {
            dp[i+1][1] = dp[i][1];
        }
    }
    return dp[SZ(vec)][0] + dp[SZ(vec)][1];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vi vec(n);
    FR(i, n) cin >> vec[i];

    vi vecs[2];
    FR(i, n) vecs[i&1].pb(vec[i]);
    vecs[0].insert(vecs[0].begin(), 0);
    vecs[~n&1].pb(0);

    cout << solve(vecs[0]) * solve(vecs[1]) << '\n';
}
