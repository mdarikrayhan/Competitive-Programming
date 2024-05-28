#include <bits/stdc++.h>
#define f first
#define s second
#define ent '\n'
#define uint unsigned int
#define ull unsigned long long
//#define int long long

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Ofast,unroll-loops,fast-math,O3")


typedef long long ll;
using namespace std;
const int mod = 1e9 + 9;
const int mx = 5e5 + 12;
const bool T = 0;

bitset<100000030> B;
ll n, m, k;
uint a, b, c, d;

uint get(int x){
    uint ans = 0;
    for(ll t=x; t<=n; t *= x){
        ans += n/t;
    }
    return ans;
}

uint f(uint x){
    return a*x*x*x + b*x*x + c*x + d;
}

int pos(int x){
    if(x % 6 != 1 && x % 6 != 5){
        return 0;
    }
    int pos = (x/6) * 2 + 1;
    if(x%6 == 5){
        pos++;
    }
    return pos;
}

void solve(){
    cin >> n >> a >> b >> c >> d;
    int v = sqrt(n)+1;
    uint ans = get(2) * f(2) + get(3) * f(3);
    for(ll x=5;x<=n; x += 2 + 2*(x%6 == 1)){
        if(B[pos(x)]){
            continue;
        }
        ans += get(x) * f(x);
        for(ll i=x*x; i<=n; i+=2*x){
            B[pos(i)] = 1;
        }
    }
    cout << ans << ent;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    if(T){
        cin>>t;
    }
    while(t--){
        solve();
    }
}