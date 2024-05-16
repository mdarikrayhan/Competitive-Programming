// g++ cfr.cpp -o p && ./p
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <bitset>
#define all(x) x.begin(), x.end()
#define __vec(x, n) vector<ll> x(n); for(ll i=0;i<n;++i)cin>>x[i]
#define __for(_x, _t) for(ll _x=0;_x<_t;++_x)
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    string s;
    cin>>n>>s;
    ll a=0,b=0;
    __for(L,n){
        if(s[L]==s[L+1]){
            if(s[L]=='0')
                a++;
            else
                b++;
        }
    }
    cout<<(a+b+1)/2<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;cin>>t;while(t--)
    solve();
    return 0;
}