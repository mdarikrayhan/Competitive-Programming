#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table

#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define bitcount(a) (int) __builtin_popcount(a)
#define bitcountll(a) (int) __builtin_popcountll(a)
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define fora(x, o) for(auto& x : o)
#define bitat(x, i) (((x)>>(i))&1)


using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

template<class T, class U> istream& operator>>(istream &is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T> istream& operator>>(istream& is, vector<T>& vec) { for(auto &x : vec) cin >> x; return is; } 
template<class T, class U> ostream& operator<<(ostream &os, const pair<T, U>& p) { os << "<" << p.first << "," << p.second << ">"; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for(auto x : vec) os << x << " "; return os; }


int CaseN;

vector<string> people{"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"}; 
void solve() {
    int n;
    cin >> n;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        string s, u, v;
        cin >> s >> u >> v;
        arr.emplace_back(find(all(people), s)-people.begin(), find(all(people), v)-people.begin());
    }
    vll boss(3);
    cin >> boss;
    pll res{2e9, 2e9};
    for (int i = 0; i < 3*3*3*3*3*3*3; i++) {
        vi ord(7);
        vi took(3);
        int curr = i;
        for (int j = 0; j < 7; j++) {
            took[ord[j] = curr%3]++;
            curr /= 3;
        }
        if (*min_element(all(took)) == 0) {
            continue;
        }
        int frined = 0;
        for (auto [u, v] : arr) if (ord[u] == ord[v]) frined++;
        res = min(res, pll{max({boss[0]/took[0], boss[1]/took[1], boss[2]/took[2]})-min({boss[0]/took[0], boss[1]/took[1], boss[2]/took[2]}), -frined});
    }
    cout << res.first << " " << -res.second << endl;
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    // int t; cin >> t; for(CaseN = 1; CaseN <= t; ++CaseN) solve(); /*
    CaseN = 1;
    solve();/**/
    cout.flush();
    return 0;
}