#include<bits/stdc++.h>


#pragma GCC optimize("conserve-stack")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")


#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define isz(x) int(x.size())
#define ull unsigned long long
#define vld vector<ld>
#define vull vector<ull>
#define vvull vector<vull>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vvvvb vector<vvvb>
#define vvvvvb vector<vvvvb>
#define vi vector<int>
#define vll vector<ll>
#define vch vector<char>
#define vvch vector<vch>
#define vvvch vector<vvch>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvll vector<vector<ll>>
#define vvvll vector<vvll>
#define vvvvll vector<vvvll>
#define vvvvvll vector<vvvvll>
#define vpii vector<pair<int,int>>
#define vvpii vector<vpii>
#define vvvpii vector<vvpii>
#define vvvvpii vector<vvvpii>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define pb push_back


using namespace std;


const double EPS = 1e-9;
const int UNDEF = -1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int SHIFT = 500'000;
const int NO_OPERATION = 2 * INF;


void solve(){
    int n, m; cin >> n >> m;

    vpii w(m);

    string S(m, '0');
    forn(i, m){
        S[i] = '1';
        cout << '?' << ' ' << S << '\n';
        cout.flush();
        cin >> w[i].fi;
        w[i].se = i;
        S[i] = '0';
    }

    sort(all(w));

    int ans = 0;
    forn(i, m){
        int j = w[i].se;
        int wating_w = ans + w[i].fi;
        S[j] = '1';
        cout << '?' << ' ' << S << '\n';
        cout.flush();

        int W; cin >> W;
        if(W != wating_w){
            S[j] = '0';
        } else {
            ans = wating_w;
        }
    }

    cout << '!' << ' ' << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}