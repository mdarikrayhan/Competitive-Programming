// Compete only with yourself
// Rating does not have enough dimensions to measure someone's skill 

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define nl "\n"
#define FOR(i, a, b) for (int(i) = (a); (i) <= (b); i++)
#define FI first
#define SE second
#define sz(X) (int)X.size()
#define all(X) (X).begin(), (X).end()
 
#define vint vector<int>
#define vvint vector<vector<int>>
#define vvpii vector<vector<pair<int, int>>>
#define vpii vector<pair<int,int>>
#define pii pair<int, int>

void YES() {std::cout << "YES" << std::endl;}
void NO() {std::cout << "NO" << std::endl;} 
void PYN(int c) {((c) ? YES() : NO());}
template<typename T> void print (T s = "", std::string se = nl) {std::cout << s << se;}
int dx [4] = {0, 0, 1, -1};
int dy [4] = {1, -1, 0, 0}; int _t = 1;
template <typename Container> void pri(Container &container) {  auto s = container.begin(), e = container.end(); while (s != e) std::cout << *(s++) << " "; std::cout << '\n'; }
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// when considering min and max in array sorting might help
// array sums - try prefix sums

const int MOD = 1e9+7;

// read problem properly
// think again if the code implements the logic you thought
// write down observations as soon as you get them


// #define int long long


void solve() {      
    string s, t;
    cin >> s >> t;

    s = "0" + s; t = "0" + t;

    int n1 = s.size() - 1, n2 = t.size() - 1;

    vvint dp(n1 + 1, vint(n2 + 1));

    FOR(i, 1, n1) {
        FOR(j, 1, n2) {
            if (t[j] == s[i]) {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j]++;
            }
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;

        }
    }

    int ans = 0;
    FOR(i, 1, n1) {
        ans += dp[i][n2];
        ans %= MOD;
    }

    print(ans);

    // for (auto i: dp) pri(i);
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T = 1;
    // cin >> T;

    // freopen("/.txt","r",stdin);
    // freopen("inp/n_60000_random.txt","w",stdout);

    std::cout << std::fixed << std::setprecision(10);
 
    for (; _t <= T; _t++)
        solve();

    return 0;
}