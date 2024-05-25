#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second 
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair   
#define AmirMakaM ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// solve it
const ull SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 mrand(SEED);
ull rnd(ull x = ~(0ull)) {return mrand() % x;} 
const ll MOD = 998244353;
const ll INF = 1e18;
const int inf = 1e9 + 7;
const int N = 1e6+1;
const int M = 2e5+1;
const double pi = 2*acos(0.0);
const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    
    if(n > y) {
        cout << -1;
        return;
    }
    
    ll res = n-1 + (y-n+1)*(y-n+1);
    if(res<x) {
        cout << -1;
        return;
    }
    
    for(int i=1; i<n; i++) cout << 1 << '\n';
    cout << y-n+1 << '\n';
}

int main() {
    AmirMakaM;
    srand(SEED);
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int ttt=1;
    //cin >> ttt;
    while(ttt--){
        solve();
    }
    return 0;
}