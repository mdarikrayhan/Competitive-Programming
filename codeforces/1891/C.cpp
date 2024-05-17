#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define float long double
#define ld long double
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vpii vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAXN = 1e6+1;
const int INF = INT64_MAX;
const int MOD = 1e9+7;
const int LOG = 60;
const ld PI = acos(-1);
const int MINF = INT64_MIN;
vpii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// leia a questão inteira e com calma
// não olhe os standings
// esqueça o tempo
// é só mais um virtual
// se divirta
// feliz show do bruninho :)

void solve(){

    int n, ans = 0; cin >> n;

    vi v(n), psum(n+2, 0);

    for(auto &x : v) cin >> x;

    sort(all(v));

    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + v[i-1];

    int lStop = n;

    for(int i = 1; i <= n; i++){

        if(psum[n] - psum[i-1] <= psum[i-1]){

            lStop = i-1;
            break;
        } if(psum[n] - psum[i-1] < 2*v[i-1] + psum[i-1]){

            ans +=  (psum[n] - 2*psum[i-1] + 1) / 2;
            v[i-1] -= (psum[n] - 2*psum[i-1] + 1) / 2;
            lStop = i;
            if(v[i-1]) lStop--;
            
            break;
        }

        ans += v[i-1];
    }

    cout << (ans + (n - lStop)) << '\n';

    return;
}
int32_t main(){ 
    sws;

    int t = 1; cin >> t;

    while(t--)
        solve();

    return 0;
}