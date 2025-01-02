#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
ll mod2 = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

ll mod_inv(ll a,ll m){
    return pow(a,m-2,m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while (t--) {
        ll a,b,p,x;
        cin>>a>>b>>p>>x;
        ll z=a;
        ll ans=0;
        for (int i = 1; i < p; ++i) {
            ll y=(b* mod_inv(z,p))%p;
            ll first = (p - 1) * ((i - y + p) % p) + i;
            if (x>=first)
                ans+=(x-first)/(p*(p-1))+1;
            (z*=a)%=p;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
	  	 	   		  	   			 	   	   		