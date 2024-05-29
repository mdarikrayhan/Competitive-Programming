#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define ld long double
#define all(_v) _v.begin(), _v.end()
#define sz(_v) (int)_v.size()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define veci vector <int>
#define vecll vector <ll>

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.141592653589793;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

void solve() {
    vector<string> a = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
    for(auto &i : a) i[0] = toupper(i[0]), i.back() = toupper(i.back());
    string s;
    cin >> s;
    int n = sz(s);
    vector<int>dp(n + 1);
    dp[0] = 1;
    s += "###";
    for(int i = 0; i < n; ++i) {
        for(auto t : a) {
            if(s.substr(i, sz(t)) == t) {
                dp[i + sz(t)] |= dp[i];
            }
        }
    }
    if(dp[n]) cout << "YES"; else cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int CNT_TESTS = 1;
    // cin >> CNT_TESTS;
    for(int NUMCASE = 1; NUMCASE <= CNT_TESTS; ++NUMCASE) {
        solve();
        if(NUMCASE != CNT_TESTS) cout << '\n';
    }
    return 0;
}
