#include <bits/stdc++.h> 
using namespace std;

#ifdef XD
#else
/// Defines:
#define int long long
#define str string
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define ins insert
#define fl '\n'
#define sp " "
#define sz size()
// #define sz(a) int((a).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define SORT(x) sort(all(x));
#define RSORT(x) sort(rall(x));
#define REV(x) reverse(all(x))
#define forn(i, b) for (int i = 0; i < (int)(b); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define lgx(x, b) (log(x) / log(b))
// #define lg2(x) 31 - __builtin_clz(x)
// #define lg2ll(x) 63ll - __builtin_clzll(x)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define YN(x) cout << ((x) ? ("YES") : ("NO")) << fl;
#define yn(x) cout << ((x) ? ("yes") : ("no")) << fl;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
template <class T, class S>
inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S>
inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi readv(int cnt, int offset)
{
    vi v(cnt + offset, 0);
    for (int i = offset; i < cnt + offset; i++)
        cin >> v[i];
    return v;
}
void print(const vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << fl;
}
const ld pi = acos(-1.0);
const int dr4[4] = {-1, 0, 1, 0};
const int dc4[4] = {0, 1, 0, -1};
const int dr8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
#endif

#if (defined LOCAL && ONLINE_JUDGE)
#define asd cout << "\n------------------------------------------\n";
#define DB_1_ARGS(DBv0) cout << DBv0 << fl;
#define DB_2_ARGS(DBv0, DBv1) cout << DBv0 << sp << DBv1 << fl;
#define DB_3_ARGS(DBv0, DBv1, DBv2) cout << DBv0 << sp << DBv1 << sp << DBv2 << fl;
#define DB_4_ARGS(DBv0, DBv1, DBv2, DBv3) cout << DBv0 << sp << DBv1 << sp << DBv2 << sp << DBv3 << fl;
#define DB_5_ARGS(DBv0, DBv1, DBv2, DBv3, DBv4) cout << DBv0 << sp << DBv1 << sp << DBv2 << sp << DBv3 << sp << DBv4 << fl;
#define DB_GET_6TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, ...) arg6
#define DB_MACRO_CHOOSER(...) \
    DB_GET_6TH_ARG(__VA_ARGS__, DB_5_ARGS, DB_4_ARGS, DB_3_ARGS, DB_2_ARGS, DB_1_ARGS, )
#define db(...) DB_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#define DBn_1_ARGS(DBv0) cout << (#DBv0) << ": " << DBv0 << fl;
#define DBn_2_ARGS(DBv0, DBv1) cout << (#DBv0) << ": " << DBv0 << sp << (#DBv1) << ": " << DBv1 << sp << fl;
#define DBn_3_ARGS(DBv0, DBv1, DBv2) cout << (#DBv0) << ": " << DBv0 << sp << (#DBv1) << ": " << DBv1 << sp << (#DBv2) << ": " << DBv2 << fl;
#define DBn_4_ARGS(DBv0, DBv1, DBv2, DBv3) cout << (#DBv0) << ": " << DBv0 << sp << (#DBv1) << ": " << DBv1 << sp << (#DBv2) << ": " << DBv2 << sp << (#DBv3) << ": " << DBv3 << fl;
#define DBn_5_ARGS(DBv0, DBv1, DBv2, DBv3, DBv4) cout << (#DBv0) << ": " << DBv0 << sp << (#DBv1) << ": " << DBv1 << sp << (#DBv2) << ": " << DBv2 << sp << (#DBv3) << ": " << DBv3 << sp << (#DBv4) << ": " << DBv4 << fl;
#define DBn_GET_6TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, ...) arg6
#define DBn_MACRO_CHOOSER(...) \
    DBn_GET_6TH_ARG(__VA_ARGS__, DBn_5_ARGS, DBn_4_ARGS, DBn_3_ARGS, DBn_2_ARGS, DBn_1_ARGS, )
#define dbn(...) DBn_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#else
#define db(...)
#define dbn(...)
#define asd
#endif

const int maxn = 2e5 + 5; 
const int oo = 1e9 + 5;
const int OO = 1e18+5;
// const int mod = 1e9 + 7; 
const int MOD = 998244353; 
const ld eps = 1e-15;

/*******************************************************************************************************************************
*                                                Code?                                                                         *
*******************************************************************************************************************************/
 
void solve()
{    
    int n;
    cin>>n;
    int cur=0,mn=0,t=0,ans=0;
    forn(i,n){
        int x;cin>>x;
        t+=x;
        cur+=x;
        if(cur>0){
            cur=0;
        }
        if(cur<mn){mn=cur;ans=t-cur;}
    }
    cout<<ans<<fl;
    // db(ans)
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cout.precision(10);cout<<fixed;
 
    int cp = 1;
    cin >> cp;
    while (cp--){
        solve(); 
    }

    // cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;
    return 0;
}
//
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⡠⠤⠒⠒⠲⠤⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠁⠙⡮⣂⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣢⠊⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⣦⣂⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣠⣝⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠱⣥⠄⠀⠀⠀⠀
// ⠀⠀⠀⠀⣸⠮⣶⠞⠛⣛⣛⣛⣷⠶⠀⠀⠐⢶⣟⣛⣛⡛⠓⠿⡚⣮⡀⠀⠀⠀
// ⠀⠀⢀⢪⠛⠁⠀⣠⣚⣶⣶⡶⡆⡗⠀⠀⠰⡇⣶⣿⣿⣟⡢⠄⠀⠙⣮⢄⠀⠀
// ⠀⢀⢦⡋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⣳⢆⠀
// ⠀⢨⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠀⠀⠀⠈⢯⠄
// ⠀⡬⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⡼⠁⠀⠀⠀⠀⠊⡄
// ⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⡦⠤⠤⠤⠤⠤⠤⠴⠒⠋⠁⢰⠇⠀⠀⠀⠀⠀⠀⡇
// ⠰⣳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⠀⠀⠀⠀⠀⢀⣴⠛
// ⠀⠁⢷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⢵⠙⠀
// ⠀⠀⠀⠀⠩⠗⠲⠤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣠⡤⠴⠶⠚⠋⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠐⠂⠈⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀

