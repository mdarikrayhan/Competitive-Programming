/*
 بسم الله الرحمن الرحيم الحمد لله رب العالمين والصلاه والسلام على اشرف المرسلين وخاتم النبيين ورحمه الله للعالمين سيدنا محمد وعلى اله وصحبه اجمعين .
 */
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define MOD 1000000007
using namespace std;
const int N = 1e6 + 10, INF = 1e9 + 10;
constexpr ll OO = 1e18;
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void Ahmed_Bahy() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    ll n,m,k;cin>>n>>m>>k;
    ll a[n][m];
    cout<<m*(m-1)/2<<"\n";
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(!k)cout<<i<<" "<<j<<"\n";
            else cout<<j<<" "<<i<<"\n";
        }
    }
}

int main() {
    Ahmed_Bahy();
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
}