#include <bits/stdc++.h>

//turn on extra precision
//#pragma GCC target("fpmath=387")

using namespace std;
using str   = string;
using ll    = long long;
using pii   = pair <int,int>;
using pll   = pair <ll,ll>;
using vi    = vector <int>;
using vll   = vector <ll>;
using vpii  = vector <pii>;
using vpll  = vector <pll>;

template<class A, class B> bool chmin(A& x, B &y){
    if(x > y) { x = y; return true; }
    return false;
}
template<class A, class B> bool chmax(A& x, B &y){
    if(x < y) { x = y; return true; }
    return false;
}

template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> ostream& operator<<(ostream& os, const vector<T> &v) {
    bool sob = 1; os << '{';
    for(auto &i : v) { if(!sob) os << ", "; os << i; sob = 0; }
    os << '}'; return os;
}

template<class T, size_t sz>
ostream& operator<<(ostream&os, const array<T, sz> &arr) {
    bool fs = 1; os << '{';
    for(auto &i : arr) { if(!fs) os << ", "; os << i; fs = 0; }
    os << '}'; return os;
}

#define mp make_pair
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'
#define all(x) x.begin(), x.end()
#define watch(x) cerr << (#x) << " is : " << (x) << newl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll quickpow(ll num1, ll num2, const int MOD) {
    assert(num2 >= 0); ll ans = 1;
    for(; num2; num2>>=1, num1 = num1 * num1 % MOD) if(num2 & 1) ans = ans * num1 % MOD;
    return ans;
}

// end of Template


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int n; t--; ) {
        cin >> n;
        string s; cin >> s;

        vector<int> z;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') z.emplace_back(i);
        }

        int ans = 0;
        for(int i = 1; i < z.size(); ++i) {
            ans += max(0, 3 - (z[i] - z[i-1]));
        }
        cout << ans << newl;
    }

    return 0;
}
